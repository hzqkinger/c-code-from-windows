#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>

static unsigned long int next = 1;
int my_rand()
{
	next = next * 1103515245 + 12345;             //����ΪʲôҪ�������ʽ��1103515245��12345 ���Ի��ɱ������
	return (unsigned int)(next / 65536) % 32768;
}
void my_srand(unsigned int seed)
{
	next = seed;
}

int main()
{
	int i, j = 10;
	my_srand(time(NULL));
	while (j--)
	{
		i = my_rand();
		printf("%d\n", i);
	}
	system("pause");
	return 0;
}