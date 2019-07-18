#define _CRT_SECURE_NO_WARNINGS
#include<CoreWindow.h>
#include <stdio.h>  
#include <stdarg.h>  
//va_start(arg,format),��ʼ������ָ��arg������������format�ұߵ�һ��������ַ��ֵ��arg  
//format������һ��������ָ�룬���ԣ��������ͺ�������Ҫ��һ����ͨ�Ĳ���,   
//�Ӷ��ṩ��va_start ,����va_start�����ҵ��ɱ������ջ�ϵ�λ�á�   
//va_arg(arg,char),���argָ�������ֵ��ͬʱʹargָ����һ������,char����ָ����ǰ������  
//va_end ����Щʵ���п��ܻ��arg�ĳ���Чֵ������ǰ�argָ��ָ���� NULL,�������Ұָ��   
void print(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		char ret = *format;
		if (ret == '%')
		{
			switch (*++format)
			{
			case 'c':
			{
						char ch = va_arg(arg, char);
						putchar(ch);
						break;
			}
			case 's':
			{
						char *pc = va_arg(arg, char *);
						while (*pc)
						{
							putchar(*pc);
							pc++;
						}
						break;
			}
			default:
				break;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(arg);
}
void test8()
{
	int a;
	a = (4 + sizeof(int)-1)&~(sizeof(int)-1);
	printf("%d\n", a);
	for (size_t i = 1; i <= 101; ++i)
	{
		a = (i + sizeof(int)-1)&~(sizeof(int)-1);
		printf("%d ", a);
		if (i % 4 == 0 && i != 0)
			printf("\n");

	}
	const char* format;
	printf("%d\n%d\n", sizeof(format), sizeof(int));
	print("%s %s %c%c%c%c%c!\n", "welcome", "to", 'C', 'h', 'i', 'n', 'a');
}

int Max(int n, ...)
{
	//printf("%d\n", *((char*)&n));

	//for (size_t i = 1; i < 24; i++)
	//{
	//	//cout << *((char*)&n + i) << endl;
	//	printf("%d\n", *((char*)&n + i));
	//}
	va_list arg;
	//va_list at = (va_list)&n + ((sizeof(n)+sizeof(int)-1)&~(sizeof(int)-1));
	int i = 0, tmp = 0;
	va_start(arg, n);
	int max = va_arg(arg, int);
	for (i = 1; i < n; ++i)
	{
		if (max < (tmp = va_arg(arg, int)))
			max = tmp;
	}
	va_end(arg);
	return max;
}
void test9()
{
	char a = 2, b = 5, c = 3;
	int max1 = Max(2, b, c);
	int max2 = Max(3.0, c, b, a);
	printf("%d %d\n", max1, max2);
}

int average(int n, ...)       //�ڿɱ������ƽ��ֵ
{
	va_list arg;
	va_start(arg, n);
	int i = 0;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
	}
	return sum / n;
	va_end(arg);
}
void test10()
{
	int a = 1, b = 2, c = 3;
	int avg1 = average(2, a, c);
	int avg2 = average(3, a, b, c);
	printf("%d\n%d\n", avg1, avg2);
}

int main()
{
	test8();
	test9();
	test10();
	system("pause");
	return 0;
}