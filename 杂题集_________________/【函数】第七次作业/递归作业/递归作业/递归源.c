#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
//fun(int n,int k)                 //①编写一个递归函数实现n^k
//{
//	if (k > 1)
//		return n*fun(n, k - 1);
//	else
//		return n;
//	k--;
//}
//int main()
//{
//	int a = 1;
//	int b = 1;
//	int ret = 0;
//	printf("请输入两个数：\n");
//	scanf("%d%d", &a, &b);
//	ret = fun(a, b);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//DigitSum(n)         //②写一个递归函数，输入一个非负整数，返回组成它的数字之和
//{
//	if (n > 9)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	else
//		return n;
//
//}
//int main()
//{
//	int num = 0;
//	int digsum = 0;
//	printf("请输入一个数：\n");
//	scanf("%d", &num);
//	digsum = DigitSum(num);
//	printf("它的各位和等于%d\n",digsum);
//	system("pause");
//	return 0;
//}

//reverse_string(char*string)    //③将参数字符串中的字符反向排列
//{
//	if (*string != 0)
//	{
//		reverse_string(string + 1);
//		printf("%c", *string);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char*str = "ABCD";
//	reverse_string(str);
//	system("pause");
//	return 0;
//}
//int my_strlen(char*str)      //④不创建变量求字符串长度
//{
//	if (*str != 0)
//		return 1 + my_strlen(str+1);
//	else
//		return 0;
//
//}
//int main()
//{
//	char*a = "abcdef";
//	int count = my_strlen(a);
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}
//int main()          //⑤非递归实现n的阶乘
//{
//	int num = 0;
//	int i = 0;
//	int ret = 1;
//	printf("请输入数字：\n");
//	scanf("%d", &num);
//	for (i = 1; i <= num; i++)
//		ret *= i;
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}
//fun(int num)                //⑤递归实现n的阶乘
//{
//	if (num > 1)
//		return num*fun(num - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n = 0;
//	int ret = 1;
//	printf("请输入数字：\n");
//	scanf("%d", &n);
//	ret = fun(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
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
fun(int n)
{
	if (n > 2)
	{
		return fun(n - 2) + fun(n - 1);
	}
	else
		return 1;
}
int main()
{
	int num = 0;
	int ret = 0;
	printf("请输入数字：\n");
    scanf("%d", &num);
	ret = fun(num);
	printf("%d\n", ret);
	system("pause");
	return 0;
}