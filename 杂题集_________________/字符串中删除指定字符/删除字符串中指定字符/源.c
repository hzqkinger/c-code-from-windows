#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<time.h>
#include<Windows.h>
int main()
{
	int i = 0, j = 0;
	char arr[20] = "aabfqcacrbadw";
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (arr[i] != 'a')
			arr[j++] = arr[i];
	}
	printf("%s\n", arr);
	system("pause");
	return 0;
}