#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>
#include<CoreWindow.h>

//伪随机序列产生函数①
static unsigned long int next = 1;
int my_rand()
{
	next = next * 1103515245 + 12345;             //这里为什么要用这个公式。1103515245和12345 可以换成别的数吗
	return (unsigned int)(next / 65536) % 32768;
}
void my_srand(unsigned int seed)
{
	next = seed;
}


//atof  atoi  itoa等字符转换函数②
double my_atof(const char *str)//一个浮点数的字符串："    -987.45e+2"
{
	double s = 0.0, d = 10.0, flag = 1.0;
	int count = 0;
	while (*str == ' ')
		str++;
	if (*str++ == '-')
		flag = -1.0;
	while (!(*str >= '0' && *str <= '9'))
		return s;
	while (*str >= '0' && *str <= '9')
	{
		s = s * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		s += (*str - '0') / d;
		d *= 10.0;
		str++;
	}
	if (*str == 'e' || *str == 'E')
	{
		str++;
		if (*str == '+')
		{
			str++;
			while (*str >= '0' && *str <= '9')
			{
				count = count * 10 + *str - '0';
				str++;
			}
			while (count--)
				s *= 10.0;
		}
		if (*str++ == '-')
		{
			while (*str >= '0' && *str <= '9')
			{
				count = count * 10 + *str - '0';
				str++;
			}
			while (count--)
				s /= 10.0;
		}
	}
	return s*flag;
}
int my_atoi(const char *str)//一个整型的字符串："   -956"
{
	int s = 0, flag = 1;
	while (*str == ' ')
		str++;
	if (*str++ == '-')
		flag = -1;
	while (*str >= '0' && *str <= '9')
	{
		s = s * 10 + *str - '0';
		str++;
	}
	return s*flag;
}
char *my_itoa(int val, char *dst, int rad)
{
	char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	int i = 0, cnt = 0;
	unsigned int num = 0;
	char tmp1;
	char *tmp = dst;
	if (val >= 0)
	{
		num = (unsigned)val;
		while (num)
		{
			*tmp = arr[num%rad];
			num /= rad;
			tmp++;
			cnt++;
		}
		for (i = 0; i <= (cnt - 1) / 2; i++)
		{
			tmp1 = *(dst + i);
			*(dst + i) = *(dst + cnt - i - 1);
			*(dst + cnt - i - 1) = tmp1;
		}
		*tmp = '\0';
		return dst;
	}
	else
	{
		if (rad == 10)
		{
			num = -val;
			*tmp++ = '-';
		}
		else
			num = (unsigned)val;
		while (num)
		{
			*tmp = arr[num%rad];
			num /= rad;
			tmp++;
			cnt++;
		}
		if (rad == 10)
		{
			for (i = 1; i <= (cnt + 1) / 2; i++)
			{
				tmp1 = *(dst + i);
				*(dst + i) = *(dst + cnt - i + 1);
				*(dst + cnt - i + 1) = tmp1;
			}
		}
		else
		{
			for (i = 0; i <= (cnt - 1) / 2; i++)
			{
				tmp1 = *(dst + i);
				*(dst + i) = *(dst + cnt - i - 1);
				*(dst + cnt - i - 1) = tmp1;
			}
		}
		*tmp = '\0';
		return dst;
	}
}

#define BASE_MAX 36
static const char digits[] = { "0123456789abcdefghijklmnopqrstuvwxyz" };
static const char ndigs[BASE_MAX + 1] = { 0, 0, 33, 21, 17,14, 13, 12, 11, 11,10, 10, 9, 9, 9, 9, 9, 8, 8, 8,8, 8, 8, 8, 7, 7, 7, 7, 7, 7,7, 7, 7, 7, 7, 7, 7 };
char *my_memchr(const char *buf, char ch, size_t size)
{
	char *tmp = (char*)buf;
	if (*(tmp+size-1) < ch)
		return NULL;
	if (ch >= '0' && ch <= '9')
		tmp += ch - '0';
	else if (ch >= 'a'&&ch <= 'z')
		tmp += ch - 'a'+10;
	return tmp;

}
int my_atoi2(const char *s)
{
	return (int)my_strtoul(s, NULL, 10);
}
long my_atol2(const char *s)
{
	return (long)my_strtoul(s, NULL, 10);
}
long int my_strtol(const char *nptr, char **endptr, int base)
{
	return (long int)my_strtoul(nptr, endptr, base);
}
//我一直不明白这里第二个参数的真正作用
unsigned long int my_strtoul(const char *s, char **endptr, int base)
{                       //"    000125a45"  "    0x45agrt5h"  "   -2543ag5"   
	const char *sc, *sd;
	const char *s1, *s2;
	char sign;
	//ptrdiff_t n;
	unsigned long x, y;
	//①先将字符串前面的空行符、正负号都处理掉
	for (sc = s; isspace(*sc); ++sc);
	sign = *sc == '-' || *sc == '+' ? *sc++ : '+';
	//②考虑字符串将要转换成几进制的数
	//（base合法的情况下：base == 0(可以是8,10,16进制数)；2<=base<=36(可分为16和其他进制)）
	//assert(base == 0 || (base >= 2 && base <= 36));//修改后
	if (base < 0 || base == 1|| BASE_MAX < base)//修改前
	{
		if (endptr)*endptr = (char*)s;
		return(0);
	}
	else if (base)
	{
		if (base == 16 && *sc == '0'
			&& (sc[1] == 'x' || sc[1] == 'X'))
			sc += 2;
	}
	else if (*sc != '0')
		base = 10;
	else if (sc[1] == 'x' || sc[1] == 'X')
		base = 16, sc += 2;
	else
		base = 8;
	//③去除字符串前面多余的零
	for (s1 = sc; *sc == '0'; ++sc);
	//④真正开始将对应有效的字符转换成n进制数
	x = 0;
	for (s2 = sc; (sd = my_memchr(digits, tolower(*sc), base)) != NULL; ++sc)
	{
		y = x; 
		x = x*base + (sd - digits);
	}
	if (s1 == sc)
	{
		if (endptr)
			*endptr = (char*)s;
		return (0);
	}
///*	n = sc - s2 - ndigs[base];
//	if (n < 0);
//	else */if(/*0 < n || */x < x - sc[-1] || (x - sc[-1]) / base != y)
//	{
	//		errno = ERANGE;// 34
	//		x = ULONG_MAX;//0xffffffffUL  /* maximum unsigned long value */
//	}
	if ((sc[-1] >= '0'&&sc[-1] <= '9') && (x < x - sc[-1] + '0' || (x - sc[-1] + '0') / base != y))
	{
		errno = ERANGE;
		x = ULONG_MAX;
	}
	else if ((sc[-1] >= 'a'&&sc[-1] <= 'z') && (x < x - tolower(sc[-1]) + 'a' || (x - tolower(sc[-1]) + 'a') / base != y))
	{
		errno = ERANGE;
		x = ULONG_MAX;
	}
	if (sign == '-')
		x = -(long)x;//修改后（long）
	if (endptr)
		*endptr = (char*)s;
	return x;
}

double my_strtod(const char *s, char **endptr);
double my_atof2(const char *str);

//整数算数函数⑥
int my_abs(int j)
{
	return (j < 0 ? -j : j);
}
long int my_labs(long int j)
{
	return (j < 0 ? -j : j);
}
div_t my_div(int numer, int denom)
{
	div_t val;
	val.quot = numer / denom;
	val.rem = numer - denom*val.quot;
	if (val.quot<0 && val.rem>0)
	{
		val.quot += 1;
		val.rem -= denom;
	}
	return val;
}
ldiv_t my_ldiv(long int numer, long int denom)
{
	ldiv_t val;
	val.quot = numer / denom;
	val.rem = numer - denom*val.quot;
	if (val.quot<0 && val.rem>0)
	{
		val.quot += 1;
		val.rem -= denom;
	}
	return val;
}

////内存管理函数③
//void *my_calloc(size_t nmemb, size_t size);
//void *my_malloc(size_t size);
//void *my_realloc(void *ptr, size_t size);
//void my_free(void *ptr);
////环境通信函数④
//void my_abort(void);
//int my_atexit(void(*func)(void));
//void my_exit(int status);
//char *my_getenv(const char *name);
//int my_system(const char *string);
////查找和排序函数 bsearch qsort⑤
////多字节字符函数⑦
//int my_Mbtowc(wchar_t *pwc, const char *s, size_t nin, _locale_t ps);
//int my_mblen(const char *s, size_t size);
//int my_mbtowc(wchar_t *pwc, const char *s, size_t size);
//int my_wctomb(char *s, wchar_t wchar);
////多字节串函数⑧
//size_t my_mbstowcs(wchar_t *pwcs, const char *s, size_t n);
//size_t my_wcstombs(char *s, const wchar_t *pwcs, size_t n);

int main()
{                  //只会写①②⑥
//	char *s = "  -52a4";
//	int num;
//	num = my_strtol(s,NULL,10);
//	printf("%d\n", num);

	//char*sc = "A";
	//char *sd;
	//tolower(*sc);
	//printf("%c\n",*sc);
	//sd = my_memchr(digits, tolower(*sc), 16);
	//printf("%s\n", sd);


	int _i = atoi(" 0000000000000000000009");
	printf("%d\n", _i);
	
	system("pause");
	return EXIT_SUCCESS;//头文件中包含了#define EXIT_SUCCESS 0和#define EXIT_FAILURE 1
}