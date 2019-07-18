#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
char* fun(char *arr, int k, int sz)
{
	int i = 0;
	int k1 = k;
	int ki = sz - k;
	for (i = 0; i <ki; i++,ki--)//for (i = 0; i < k; i++, k--)//
	{
		char temp = arr[i];
		arr[i] = arr[ki - 1];
		arr[ki - 1] = temp;
	}
	for (i =sz - k1; i < sz;i++,sz--)//for (i = k1; i < sz;i++,sz--)//
	{
		char temp = arr[i];
		arr[i] = arr[sz-1];
		arr[sz-1] = temp;
	}
}
int main()
{
	char arr[] = "ABCDEFG";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	int k = 0;
	printf("请输入要左旋几位：\n");
	scanf("%d", &k);
	fun(arr, len, len);
	fun(arr, k, len);
	printf("%s\n", arr);
	system("pause");
	return 0;
}