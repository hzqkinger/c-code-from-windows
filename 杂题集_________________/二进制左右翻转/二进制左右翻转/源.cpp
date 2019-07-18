#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//二进制位模左右翻转
{
	int num = 25;
	int cnt = 31;
	unsigned int key = 0;
	while (cnt)
	{
		key = key | ((num & 0x00000001) << cnt);
		num >>= 1;
		cnt--;
	}
	printf("%u\n", key);
	system("pause");
	return 0;
}