#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<CoreWindow.h>

void Alphabet_count(char a[], int n)//算了，不区分大小写，一律输入进来的是大写
{
	int count[26] = { 0 }, i;
	for (i = 0; i < n; ++i)
		++count['Z' - a[i]]; //②++count[a[i] - 'A'];
	for (i = 0; i < 26; ++i)
		printf("%c = %d\n", 'Z' - i, count[i]);//②printf("%c = %d\n", 'A' + i, count[i]);
}
int main()
{
	char arr[] = "ABCDDEFGHIJKLMNOPQRSTUVWXYZ";
	Alphabet_count(arr,strlen(arr));
	system("pause");
	return 0;
}


////附带送个易错题
//char *f(char *str, char ch)
//{
//	char *it1 = str;
//	char *it2 = str;
//	while (*it2 != '\0')
//	{
//		while (*it2 == ch)it2++;
//		*it1++ = *it2++;
//	}
//	return str;
//}
//int main()
//{
//	char *a = (char*)malloc(10);
//	strcpy(a, "abcdcccd");
//	printf("%s\n", f(a, 'c'));
//
//	system("pause");
//	return 0;
//}