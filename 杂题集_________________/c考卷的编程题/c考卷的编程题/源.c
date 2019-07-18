#define _CRT_SERECURE_NO_WARNINGS
#include<stdio.h>
//1、	请编码实现以下功能的函数
//功能：实现对一个8 bit数据（unsigned char类型）的指定位（例如第n位）的置0或者置1操作，并保持其他位不变。
//函数原型：
//void bit_set(unsigned char *p_data, unsigned char position, int flag)
//函数参数说明：
//p_data 是指定的源数据，position是指定位（取值范围1~8）；flag表示是置0还是置1操作
//
//2、	请实现字符串右循环移位函数，比如：“abcdefghi”循环右移2位就是“hiabcdefg”.
//函数原型：void RightLoopMove(char *pStr, unsigned short steps)
//函数参数说明：
//pStr : Point to a ‘\0’ terminated string
//   steps : The rotate shift numbers
//
//		   3. 请编写程序实现字符串到整数的转换，例如输入字符串“12345”，输出整数12345
void bit_set(unsigned char *p_data, unsigned char position, int flag)
{
	unsigned int flag1 = 1;
	//while (position > 1)
	//{
	//	flag1 <<= 1;
	//	position--;
	//}
	flag1 <<= position - 1;
	if (flag == 0)
		*p_data = *p_data & (~flag1);
	else
		*p_data = *p_data | flag1;
}
void RightLoopMove(char *pStr, unsigned short steps)
{

}
//第一题和第二题
int main()
{
	unsigned char uc = 0;//0000 0000
	bit_set(&uc, 4, 1);
	printf("%u\n", uc);
	system("pause");
	return 0;
}
//第三个题
//int main()
//{
//	char *pint = "12345";
//	int sum = 0;
//	while (*pint)
//	{
//		sum = 10 * sum + (*pint - '0');
//		pint++;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}