#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//С����¥�����¼�
{
	int count = 10;
	float high = 0.0;
	float s = 0.0;
	printf("�������ʼ����߶ȣ�\n");
	scanf("%f", &high);
	while (count)
	{
		s += high;
		high /= 2;
		s += high;
		count--;
	}
	printf("%f   %f\n", s, high);
	system("pause");
	return 0;
}