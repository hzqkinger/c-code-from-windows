#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
union un{
	int a;
	float b;
	char c;
}x;
int main()  //��С����λ�ε���������ɷ�Ϊ����˼·�����ȷ������ڴ�����ڴ�������
{
	//x.b = 1.5;
	x.a = 25;
	//x.b = 1.5;
	//x.c = 'a';
	//printf("%d %g %c\n", x.a, x.b, x.c);
	//printf("%d\n", sizeof(union un));
	//printf("%d\n", x.a);
	printf("%d\n", x.c);

	//int a = 0x11223344;
	//int b = 11;
	//char*p = (char*)&a;
	//*p = 20;
	//printf("%d\n", a);

	system("pause");
	return 0;
}