#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<CoreWindow.h>
#include<string.h>

//复制函数
void *my_memcpy(void *s1, const void *s2, size_t n)
{
	char *s = s1;
	while (n--)
	{
		*s++ = *(char*)s2;
		s2 = (char*)s2 + 1;
	}
	return s1;
}
void *my_memmove(void *s1, const void *s2, size_t n)//考虑字符串重叠问题
{
	char *sc1 = s1;
	const char *sc2 = s2;
	if (sc2 < sc1&&sc1 < sc2 + n)
	{
		for (sc1 += n, sc2 += n; 0 < n; --n)
			*sc1-- = *sc2--;
	}
	else
	{
		for (; 0 < n; --n)
			*sc1++ = *sc2++;
	}
	return s1;
}
char *my_strcpy(char *s1, const char *s2)
{
	char *s = s1;
	for (; (*s++ = *s2++) != '\0';);
	return s1;
}
char *my_strncpy(char *s1, const char *s2, size_t n)
{
	char *s = s1;
	for (; n > 0 && *s2 != '\0'; --n)
		*s++ = *s2++;
	for (; n > 0; --n)
		*s++ = '\0';
	return s1;
}

//连接函数
char *my_strcat(char *s1, const char *s2)
{
	char *s = s1;
	for (; *s != '\0'; ++s);
	for (; (*s++ = *s2++) != '\0';);
	return s1;
}
char *my_strncat(char *s1, const char *s2, size_t n)
{
	char *s = s1;
	for (; *s != '\0'; ++s);
	for (; n > 0 && (*s++ = *s2++) != '\0'; --n);
	*s = '\0';
	return s1;
}

//比较函数
int my_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *su1 = s1, *su2 = s2;
	for (; n > 0;++su1,++su2,--n)
	if (*su1 != *su2)return (*su1 < *su2 ? -1 : 1);
	return 0;
}
int my_strcmp(const char *s1, const char *s2)
{
	for (; *s1 == *s2;++s1,++s2)
	if (*s1 == '\0')//注意这里的*s1要与上一句的*s1一样
		return 0;
	return (*(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1);//可以改成相减
}
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	for (; n>0;++s1,++s2,--n)
	if (*s1 != *s2)return (*(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1);//可以改成相减
	return 0;
	//for (; n > 0 && *s1 == *s2;--n,++s1,++s2)
	//if (n == 1 || *s1 == '\0')//注意这里for循环的顺序是①②④③②④③②④③...
	//	return 0;
	//return (*(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1);//可以改成相减
}

int my_strcoll(const char *s1, const char *s2);//难
size_t my_strxfrm(char *s1, const char *s2, size_t n);//难

//查找函数
void *my_memchr(const void *s, int c, size_t n)//
{
	const unsigned char *us = s,uc = c;
	for (; n > 0;++us,--n)
	if (*us == uc)return ((void*)us);
	return NULL;
}
int my_strchr2(char const*str, char ch)//⑧减丶查找一个字符是否字符首次出现在字符串中，如存在，是第几位。
{
	char*tmp = str;
	while (*str++ != ch)
	{
		if (*(str - 1) == '\0')
			return 0;
	}
	return str - tmp;
	//char*a = str;
	//while (*str&&*str != ch)
	//	++str;
	//return *str ? str - a + 1 : 0;
}
char *my_strchr(const char *s, int c)//确定c在s指向的串中第一次出现的位置
{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return NULL;
		s++;
	}
	return (char*)s;
}
char *my_strrchr(const char *s, int c)//确定c在s指向的串中最后一次出现的位置
{
	char*tmp = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			tmp = (char*)s;
		s++;
	}
	return tmp;
}
char *my_strstr(const char *s1, const char *s2)//确定字符串s2在字符串s1中第一次出现的位置
{
	while (*s1 != '\0')
	{
		const char *tmp1 = s1;
		const char *tmp2 = s2;
		while (*s2 != '\0'&&*tmp1++ == *s2)
		{
			s2++;
		}
		if (*s2 == '\0')
			return s1;
		else
		{
			s2 = tmp2;
			s1++;
		}
	}
	return NULL;
}
char *my_strpbrk(const char *s1, const char *s2)//确定s2指向的任意字符在字符串s1中第一次出现的位置
{
	char* tmp2 = s2;
	while (*s1 != '\0')
	{
		s2 = tmp2;
		while (*s2 != '\0')
		{
			if (*s1 == *s2)
				return s1;
			else
				s2++;
		}
		s1++;
	}
	if (s1 == '\0')
		return NULL;
}

char *my_strtok(char *s1, const char *s2);//难
size_t my_strcspn(const char *s1, const char *s2);
size_t my_strspn(const char *s1, const char *s2);

//其他函数
void *my_memset(void *s, int c, size_t n)
{
	const unsigned char uc = c;
	unsigned char *us = s;
	for (; n > 0; ++us, --n)
		*us = uc;
	return s;
}
size_t my_strlen(const char *s)
{
	//	int count = 0;   //①
	//	while (*s++)
	//		count++;
	//	return count;
	char*tmp = s;       //②
	while (*s)
		s += 1;
	return s - tmp;
	//	if (*s++)       //③
	//		return 0;
	//	else
	//		return 1 + my_strlen(s);
}

char *my_strerror(int errnum);//难

int main()
{
	char p[20] = "abcdg";
	char *p2 = "abdgjjjj";
	my_memset(p, 'k', 4);
	printf("%s\n", p);
	system("pause");
	return 0;
}