#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
//atof  atoi  itoa
double my_atof(const char *str)
{
	//"               +34555.444e+4"
	//"无意义的空格  +/ /- 正文 . 正文 e +/ /- 正文"
	double s = 0.0, d = 10.0, flag = 1.0;
	int count = 0;
	while (*str == ' ')str++;//① 跳过无效空格
	//flag = *str == '+' || *str = '-' ? *str++ : '+';
	if (*str == '-'){ flag = -1.0; str++; }//② 判断符号
	else if (*str == '+'){ str++; }


	while (*str >= '0' && *str <= '9')//③ 判断第一段正文
	{
		s = s * 10 + *str - '0';
		str++;
	}
	if (*str == '.')//④ 判断是否存在点
		str++;
	while (*str >= '0' && *str <= '9')//⑤ 判断第二段正文
	{
		s += (*str - '0') / d;
		d *= 10.0;
		str++;
	}
	if (*str == 'e' || *str == 'E')//⑥ 判断是否存在e/E
	{
		str++;
		if (*str == '+')//⑦ 在⑥成立的情况下判断指数的符号以及大小
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
		if (*str++ == '-')//⑦ 在⑥成立的情况下判断指数的符号以及大小
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
int my_atoi(const char*str)
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
char *my_itoa(int val, char*dst, int rad)
{
	const char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
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
int main()
{
	//int val = -12;
	//char dst[33] = { 0 };
	//char dst1[3] = { 0 };
	////printf("%u\n", val);
	////printf("%s\n", p);
	//my_itoa(val, dst, 9);
	//printf("%s\n", dst);

	//_itoa(val, dst1, 9);
	//printf("%s\n", dst1);

	char *p = ".3e+4";
	//atoi(p);
	printf("%f\n",atof(p));
	printf("%f\n", my_atof(p));
	system("pause");
	return 0;
}