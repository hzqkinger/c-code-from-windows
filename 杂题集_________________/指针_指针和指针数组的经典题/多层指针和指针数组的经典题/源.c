#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
//���ָ���ָ�����������
int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char**cp[] = { c + 3, c + 2, c + 1, c };
	char***cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	system("pause");
	return 0;
}

#if 0
//int fun(int (*p)[4])
//{
//	int ret = sizeof(*p);
//	return ret;
//}
int main()
{
	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int*p = a;
	int(*p1)[3][4] = &a;
	int(*p2)[4] = a;
	printf("%d\n%d\n%d\n", p, p1, p2);
	printf("%d\n%d\n%d\n", p + 1, p1 + 1, p2 + 1);
	printf("%d\n", sizeof(void*));

	system("pause");
	return 0;
}
#endif

//int main()
//{
//	int a = 10;              //p2ָ��p1��p1ָ��a
//	int*p1 = &a;
//	int **p2 = &p1;
//	printf("%d %d\n", a, *p1);
//	printf("%d %d %d\n", &a, p1, *p2);
//	printf("%d %d\n", &p1, p2);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 10;       //������ֵ���Ƿ�����ñ������ڴ�λ�����洢����ֵ2
//	int* b = &a;
//	printf("%p\n", b);
//	printf("%d\n", &b);
//	printf("%d\n", &a);
//	printf("%d\n", b);
//	system("pause");
//	return 0;
//}

//void fun(int *x)
//{
//	*x = *x + 1;
//}
//int main()
//{
//	int a = 10;
//	fun(&a);
//	printf("%d\n", a);
//	system("pause");
//	return 0;
//}