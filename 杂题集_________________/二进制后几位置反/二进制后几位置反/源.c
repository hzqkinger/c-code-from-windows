#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
char*itob(int num, char*str)
{                   //�������±����ý��в����ģ�����str�ĸı���ʵ����ʵ�εĸı�
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
		puts("����ûת��ǰ�Ķ��������У�");
		itob(num, bin_str);
		show_bstr(bin_str);
		num = invert(num, bit);
		tmp = (int)bit;
		printf("����ת������%dλ֮��Ķ��������У�\n", tmp);
		itob(num, bin_str);
		show_bstr(bin_str);
		printf("������˳��밴q\n");
	}
	system("pause");
	return 0;
}