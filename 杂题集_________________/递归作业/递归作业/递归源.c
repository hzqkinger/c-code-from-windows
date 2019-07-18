#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void move(char x, char y)
{
	printf("%c->%c\n", x, y);
}
void hanoi(int n, char one, char two, char three)
{
	if (n == 1)
		move(one, three);
	else
	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}
int main()
{
	int m = 20;
	hanoi(m, 'a', 'b', 'c');
	system("pause");
	return 0;
}
//fun(int n,int k)                 //�ٱ�дһ���ݹ麯��ʵ��n^k
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
//	printf("��������������\n");
//	scanf("%d%d", &a, &b);
//	ret = fun(a, b);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//DigitSum(n)         //��дһ���ݹ麯��������һ���Ǹ����������������������֮��
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
//	printf("������һ������\n");
//	scanf("%d", &num);
//	digsum = DigitSum(num);
//	printf("���ĸ�λ�͵���%d\n",digsum);
//	system("pause");
//	return 0;
//}

//reverse_string(char*string)    //�۽������ַ����е��ַ���������
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

//int my_strlen(char*str)      //�ܲ������������ַ�������
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

//int main()          //�ݷǵݹ�ʵ��n�Ľ׳�
//{
//	int num = 0;
//	int i = 0;
//	int ret = 1;
//	printf("���������֣�\n");
//	scanf("%d", &num);
//	for (i = 1; i <= num; i++)
//		ret *= i;
//	printf("%d\n",ret);
//	system("pause");
//	return 0;
//}

//fun(int num)                //�ݵݹ�ʵ��n�Ľ׳�
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
//	printf("���������֣�\n");
//	scanf("%d", &n);
//	ret = fun(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

