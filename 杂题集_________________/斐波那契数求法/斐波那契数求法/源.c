#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>        
#include<math.h>         //青蛙跳台阶问题；兔子生子问题；2*1的小矩形填满2*n的大矩形；还有一丁点都没看懂的抛硬币问题.......
#include<time.h>
#include<Windows.h>
int main()            //sqrt()   pow()的参数都是double,都是double
{
	int n1 = 0;         //求第n项斐波那契数是多少
	float n = 0.0;
	int m = 0;
	printf("请输入斐波那契的第n项项数：\n");
	scanf("%f", &n);
	n1 = n;
	m = 1.0 / sqrt(5.0) *(pow((1.0 + sqrt(5.0)) / 2.0, n) - pow((1.0 - sqrt(5.0)) / 2.0, n));
	printf("第%d项斐波那契数是%d\n", n1, m);
	system("pause");
	return 0;
}

//int main()                //⑥非递归实现斐波那契数
//{
//	int a = 1, b = 1, c = 0;
//	int n = 0;
//	int i = 0;
//	printf("请输入数字：\n");
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


//fun(int n)  //递归方法实现斐波那契数列
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
//	printf("请输入数字：\n");
//    scanf("%d", &num);
//	ret = fun(num);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
