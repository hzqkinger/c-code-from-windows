#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>        
#include<math.h>         //������̨�����⣻�����������⣻2*1��С��������2*n�Ĵ���Σ�����һ���㶼û��������Ӳ������.......
#include<time.h>
#include<Windows.h>
int main()            //sqrt()   pow()�Ĳ�������double,����double
{
	int n1 = 0;         //���n��쳲��������Ƕ���
	float n = 0.0;
	int m = 0;
	printf("������쳲������ĵ�n��������\n");
	scanf("%f", &n);
	n1 = n;
	m = 1.0 / sqrt(5.0) *(pow((1.0 + sqrt(5.0)) / 2.0, n) - pow((1.0 - sqrt(5.0)) / 2.0, n));
	printf("��%d��쳲���������%d\n", n1, m);
	system("pause");
	return 0;
}

//int main()                //�޷ǵݹ�ʵ��쳲�������
//{
//	int a = 1, b = 1, c = 0;
//	int n = 0;
//	int i = 0;
//	printf("���������֣�\n");
//    scanf("%d", &n);
//	if (n < 3)
//		c = 1;
//	else
//	for (i = 3; i <= n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}


//fun(int n)  //�ݹ鷽��ʵ��쳲���������
//{
//	if (n > 2)
//	{
//		return fun(n - 2) + fun(n - 1);
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int num = 0;
//	int ret = 0;
//	printf("���������֣�\n");
//    scanf("%d", &num);
//	ret = fun(num);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
