#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
//int my_strlen(char const *string)//�ټ����ַ�������
//{
//	int count = 0;
//	while (*string++)
//		count++;
//	return count;
//}
//int my_strlen(char const *string)//�ټ����ַ�������
//{
//	if (*string++)
//		return 0;
//	else
//		return 1 + my_strlen(string);
//}
//int my_strlen(char const *string)//�ټ����ַ�������
//{
//	char*tmp = string;
//	while (*string)
//		string += 1;
//	return string - tmp;
//}
//char *my_strcpy(char* dst, const char *src)//���ַ�����������
//{
//	char *tmp = NULL;
//	tmp = dst;
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return tmp;
//}
//char *my_strcat(char* dst, char const *src)//���ַ������Ӻ���
//{
//	char *tmp = NULL;
//	tmp = dst;
//	while (*dst++)
//	{
//		;
//	}
//	dst--;
//	while (*dst++ = *src++)
//	{
//		;
//	}
//	return tmp;
//}
//int my_strcmp(char const*s1, char const*s2)//���ַ����ȽϺ���
//{
//	while (1)
//	{
//		if (*s1 > *s2)
//			return 1;
//		else if (*s1 < *s2)
//			return -1;
//		else
//		{
//			if (*s1 == '\0')
//				return 0;
//		}
//		s1++;
//		s2++;
//	}
//}

//#if 0
//int my_strchr(char const*str, char ch)//���ؼ����һ���ַ��Ƿ��ַ��״γ������ַ����У�����ڣ��ǵڼ�λ��
//{
//	char*tmp = str;
//	while (*str++ != ch)
//	{
//		if (*(str - 1) == '\0')
//			return 0;
//	}
//		return str - tmp;
//		//char*a = str;
//		//while (*str&&*str != ch)
//		//	++str;
//		//return *str ? str - a + 1 : 0;
//}
//#endif
//char* my_strchr(char const*str, char ch)//�����һ���ַ����ַ�����һ�����ֵ�λ��
//{
//
//	while (*str != ch)
//	{
//		if (*str == '\0')
//			return NULL;
//		str++;
//	}
//	return str;
//}
//char*my_strrchr(char const*str, int ch)//�����һ���ַ����ַ������һ�����ֵ�λ��
//{
//	int i = 0;
//	char*tmp = NULL;
//	while(*str)
//	{
//		if(*str == ch)
//			tmp = str;
//		str++;
//	}
//	return tmp;
//}
//char*my_strpbrk(char const*str, char const*group)//������κμ����ַ�
//{
//	char* tmp2 = group;
//	while (*str != '\0')
//	{
//		group = tmp2;
//		while (*group != '\0')
//		{
//			if (*str == *group)
//				return str;
//			else
//				group++;
//		}
//			str++;
//	}
//	if (str == '\0')
//		return NULL;
//}
//char*my_strstr(const char* str, char const*group)//11ؼ����һ���Ӵ�
//{
//	while (*str != '\0')
//	{
//		char* tmp1 = str;
//		char* tmp2 = group;
//		while (*group != '\0'&&*tmp1++ == *group)
//		{
//			group++;
//		}
//		if (*group == '\0')
//			return str;
//		else
//		{
//			group = tmp2;
//			str++;
//		}
//	}
//	return NULL;
//}
//void *my_memcpy(void *dst, void *src, int count)
//{
//	int i = 0;
//	for (i = 0; i < count; i++)
//	{
//		*(char*)dst = *(char*)src;
//		dst = (char*)dst + 1;
//		src = (char*)src + 1;
//	}
//}
//char *memmove(char *dst, char *src, int count)
//{
//
//
//}
char *my_strncpy(char*dst, char const *src, size_t len)//��
{
	char *tmp = dst;
	while (len)
	{
		*dst++ = *src++;
		len--;
	}
	return tmp;
}
char *my_strncat(char*dst, char const *src, size_t len)//��
{
	char *tmp = dst;
	while (*dst)
		dst++;
	while (len)
	{
		*dst++ = *src++;
		len--;
	}
	return tmp;
}
int my_strncmp(char const*s1, char const*s2, size_t len)//��
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (*s1 == *s2)
			s1++, s2++;
		else
			return *s1 - *s2;
	}
	if (i == len)
		return 0;
}
int main()//1 2 3 4��8-��8 9 10 11
{
	char*a = NULL;
	int b = 0, c = 0;
	int i = 0;
	char arr[20] = "hello hah";
	char mess[] = "hello h";

	//my_strncat(arr, mess, 7);
	//my_strncpy(arr, mess, 3);
	printf("%d\n", my_strncmp(arr, mess, 8));
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	//int mess[] = { 5, 6, 7, 8, 9 };
	//memmove(arr, mess, 8);
	//my_memcpy(arr, mess, 7);
	//a = my_strrchr(arr, 'n');
	//a = my_strpbrk(arr, mess);
	//a = my_strstr(arr,mess);
	//a = my_strcmp(arr, mess);
	// my_strcat(arr, mess);
	//my_strcpy(arr, mess);
	//a = my_strlen(arr);
	//printf("%d\n",'d'-'a');
	//strcpy(mess, "a d");
	//strcat(a , "world");
	//printf("%s\n", mess);
	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//	printf("%d ", arr[i]);
	//printf("\n");

	system("pause");
	return 0;
}