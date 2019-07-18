#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
char*itob(int num, char*str)
{                   //都是用下标引用进行操作的，所以str的改变其实就是实参的改变
	int i;
	for (i = 31; i >= 0; num >>= 1)
		str[i--] = (1 & num) + '0';
	str[32] = '\0';
	return str;
}
void show_bstr(const char*str)
{
	int i = 0;
	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
	putchar('\n');
}
int invert(int num, float bit)
{
	int mask = (int)pow(2.0, bit) - 1;
	return mask^num;
}
int main()
{
	int num, tmp;
	float bit;
	char bin_str[33] = { 0 };
	while (scanf("%d%f", &num, &bit) == 2)
	{
		puts("数字没转换前的二进制序列：");
		itob(num, bin_str);
		show_bstr(bin_str);
		num = invert(num, bit);
		tmp = (int)bit;
		printf("数字转换后面%d位之后的二进制序列：\n", tmp);
		itob(num, bin_str);
		show_bstr(bin_str);
		printf("如果想退出请按q\n");
	}
	system("pause");
	return 0;
}