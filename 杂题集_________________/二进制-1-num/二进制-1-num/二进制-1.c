#include<stdio.h>
#include<Windows.h>
int main()
{
	int num = 0;
	int count = 0;
	printf("请输入一个十进制数: \n");//这个方法不能计算负数二进制补码中的1的个数，
	scanf_s("%d", &num);               //因为它向右移位时在最左端自动用1补齐。  

	while (num != 0)//如果要求负数二进制补码中的1的个数，while循环中的条件应该改成只循环32次.
	{
		//num = num &(num - 1);//这是方法二，这种方法的思想是将num从低位到高位的1逐个置零
		//count++;
		if ((num & 1) == 1)
			count++;
		num = num >> 1;

	}
	printf("%d\n", count);
	system("pause");
	return 0;
}