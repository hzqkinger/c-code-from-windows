#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//������λģ���ҷ�ת
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