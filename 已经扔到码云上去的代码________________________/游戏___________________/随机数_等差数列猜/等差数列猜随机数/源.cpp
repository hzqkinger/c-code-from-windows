#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//�Ȳ����з��������
{
	int max = 0, i = 0, sum = 0, count = 0, n = 0;
	int key[100] = { 0 };
	printf("�������������֣�");
	scanf("%d", &max);
	srand(time(NULL));
	int x = rand() % max;
	float f = (sqrt(1 + 8.0 * max) / 2 - 1.0 / 2);
	if (f > (int)f)
		n = (int)f + 1;
	else
		n = (int)f;
	for (i = 0; i < n; i++)
	{
		key[i] = sum += n-i;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d  ", key[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		count++;
		if (key[i] < x)
		{
			printf("С��\n");
		}
		else
		{
			sum = i;
			break;
		}
	}
	for (i = 0; i < n - sum; i++)
	{
		count++;
		if (key[sum] > x)
			key[sum]--;
		else
		{
			printf("Ҫ�ҵ����ǣ�%d\n", key[sum]);
			break;
		}
	}
	printf("���շ����ҵ�������Ĵ�����%d\n", count-1);
	system("pause");
	return 0;
}