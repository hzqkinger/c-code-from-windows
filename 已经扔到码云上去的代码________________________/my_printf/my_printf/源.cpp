#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<cctype>

void f1(size_t i, char ch)
{
	int base = 10;
	static char arr[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	if (!i)return;
	else
	{
		if (ch == 'o')
			base = 8;
		else if (ch == 'x' || ch == 'X' || ch == 'p')
			base = 16;
		f1(i / base, ch);
	}
	if (ch == 'p')
	{
		if (isdigit(arr[i % base]))
			putchar(arr[i % base]);
		else
			putchar(arr[i % base] - 32);
	}
	else
		putchar(arr[i % base]);

}
//%c %d %i %u %f %o %x/X %p %s %%  (%a/A %e/E  %g/G) %n
void print5(const char*format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%') // % +0m.n c   (% ch1 ch2 m.n c)
		{
			char ch1 = ' ', ch2 = ' ', ch3 = ' ', ch = ' ';
			int m = 0, n = 0;
			while (isdigit(*++format) || *format == '+' || *format == '-' || *format == '#' || (*format == '.' && isdigit(*(format + 1))))
			{//让数字，+，-，#，点号，进入循环。                                                //点号后面必须是数字
				switch (*format)
				{
				case'+':
				{
						   if (ch1 != '-')ch1 = '+';
						   break;
				}
				case'-':
				{
						   ch1 = '-';//有'-'，则优先给ch1赋值为'-'。
						   break;
				}
				case'#'://只对o和x起作用 //对于o类，在输出时加前缀0；对于x类，在输出时加前缀0x。
				{
							ch3 = '#';
				}
				case'0'://ch1表示'+','-'；ch2表示'0','空'
				{
							if (!isdigit(*(format - 1)))//如果*format=='0'时，前一个字符不是数字(不包括'0')
							{
								//ch1 = '-';
								ch2 = '0';
								break;
							}//'0','+'混合情况(输出+000xxxx)；'0','-',('+')混合情况(输出+xxxx)。
				}
					//在处理m,n时，已经将ch1和ch2处理好了。
				case'1':
				case'2'://m表示域宽，即对应的输出项在输出设备所占字节数
				case'3':       //指定占字节数m 与 实际占字节数，输出项在输出设备所占字节数取二者最大值
				case'4'://n表示精度，主要用于说明输出的实型数的小数位数
				case'5':      //对于整型15：①%6.2d->    15；②%6.4d->  0015；③%6.8d->000015
				case'6':
				case'7':
				case'8':
				case'9':
				{
						   m = 10 * m + *format - '0';
						   break;
				}
				case'.':
				{
						   ch = *format;
						   while (isdigit(*++format))
							   n = 10 * n + *format - '0';
						   break;
				}
				}
				if (ch == '.')
					break;
			}
			switch (*format)
			{
			case 'c'://输出c时只和域宽m有关。
			{
						 char ch = va_arg(arg, char);
						 if (ch1 == '+'|| ch1 == ' ')
						 while (--m)putchar(ch2);//ch2可以是空，也可以是0.
						 putchar(ch);
						 if (ch1 == '-')
						 while (--m)putchar(' ');
						 break;
			}

			case 'i':
				;
			case 'd':
			{
						int i = va_arg(arg, int);
						if (i < 0)
						{
							putchar('-');
							i = -i;
						}
						int tmp = i, count = 0;
						while (tmp)++count, tmp /= 10;
						n = n > count ? n : count;//保证n是两者最大值
						if (ch1 == '+'|| ch1 == ' ')
						{
							while (--m - n>0)putchar(' ');//若m>n,这步的结果是让m = n；假如m<n，这步无效
							if (i>0 && ch1 != ' ')
								putchar('+');
							while (n - count > 0)--n, putchar('0');//假如n<count，这步无效
						}

						if (ch1 == '-')
						{
							int tmpn = n;;
							while (tmpn-- - count > 0)putchar('0');//假如n<count，这步无效
						}
						f1(i, *format);
						if (ch1 == '-')
						while (m - n>0)--m, putchar(' ');//假如m<n，这步无效
						break;
			}
			case 'u':
			{
						int u = va_arg(arg, unsigned int);
						size_t tmp = u, count = 0;
						while (tmp)++count, tmp /= 10;
						n = n > count ? n : count;//保证n是两者最大值
						if (ch1 == '+' || ch1 == ' ')
						{
							while (--m - n>0)putchar(' ');//若m>n,这步的结果是让m = n；假如m<n，这步无效
							if (u>0 && ch1 != ' ')
								putchar('+');
							while (n - count > 0)--n, putchar('0');//假如n<count，这步无效
						}

						if (ch1 == '-')
						{
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//假如n<count，这步无效
						}
						f1(u, *format);
						if (ch1 == '-')
						while (m - n>0)--m, putchar(' ');//假如m<n，这步无效
						break;
			}
			case 'f':
			{
						double f = va_arg(arg, double);
						if (0x80 & *((char*)(&f + 1) - 1))//判断该浮点数是否为负数
						{//这样写还不如写成:if(f<0)
							putchar('-');
							f = -f;
						}
						int tmp = (int)f,tmp2 = (int)f,count = 0;
						while (tmp)++count, tmp /= 10;
						count += n + 1;
						if (ch1 == '+' || ch1 == ' ')
						{
							if (f>0 && ch1 != ' ')
								putchar('+');
							while (--m - count>0)putchar(ch2);//假如m<count，这步无效
						}
						f1(tmp2, *format);
						putchar('.');

						if (n == 0)n = 6;
						while (n--)f*=10,tmp2 *= 10;
						tmp = f - tmp2;
						f1(tmp, *format);
						if (ch1 == ' ')
						{
							while (m-- - count > 0)putchar(' ');
						}
						break;
			}

			case 'o'://没测试ch2 == '0'的情况
			{
						int o = va_arg(arg, unsigned int);
						size_t tmp = o, count = 0;
						while (tmp)++count, tmp /= 8;
						n = n > count ? n : count;//保证n是两者最大值
						if (ch3 == '#')++n;
						if (ch1 == '+' || ch1 == ' ')
						{
							int tmpm = m;
							while (tmpm-- - n>0)putchar(' ');//假如m<n，这步无效
							if (m && m<n)--n;
							while (n - count > 0)--n, putchar('0');//假如n<count，这步无效
						}

						if (ch1 == '-')
						{
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//假如n<count，这步无效
						}
						f1(o, *format);
						if (m<n)--n;
						if (ch1 == '-')
						while (m - n>0)--m, putchar(' ');//假如m<n，这步无效
						break;
			}
			case'X':
				;
			case 'x'://没测试ch2 == '0'的情况
			{
						int x = va_arg(arg, unsigned);

						size_t tmp = x, count = 0;
						while (tmp)++count, tmp /= 16;
						n = n > count ? n : count;//保证n是两者最大值
						if (ch3 == '#')m -= 2;
						if (ch1 == '+' || ch1 == ' ')
						{
							int tmpm = m;
							while (tmpm-- - n>0)putchar(' ');//假如m<n，这步无效
							if (ch3 == '#')putchar('0'),putchar('x');
							while (n - count > 0)--n, putchar('0');//假如n<count，这步无效
						}

						if (ch1 == '-')
						{
							if (ch3 == '#')putchar('0'), putchar('x');
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//假如n<count，这步无效
						}
						f1(x, *format);
						if (ch1 == '-')
						{
							m -= 1;
							while (m - n>0)--m, putchar(' ');//假如m<n，这步无效
						}
						break;
			}
			case 'p'://没测试ch2 == '0'的情况
			{
						int p = va_arg(arg, unsigned int);
						size_t tmp = p, count = 0;
						while (tmp)++count, tmp /= 16;
						n = 8;
						if (ch1 == '+' || ch1 == ' ')
						{
							int tmpm = m;
							while (tmpm-- - n>0)putchar(' ');//假如m<n，这步无效
							if (ch3 == '#')putchar('0'), putchar('x');
							while (n - count > 0)--n, putchar('0');//假如n<count，这步无效
						}

						if (ch1 == '-')
						{
							if (ch3 == '#')putchar('0'), putchar('x');
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//假如n<count，这步无效
						}
						f1(p, *format);

						if (ch1 == '-')
						{
							m -= 2;
							while (m - n>0)--m, putchar(' ');//假如m<n，这步无效
						}
						break;
			}
			case 's'://没测试ch2 == '0'  和ch3 == '#'的情况
			{
						char *s = va_arg(arg, char*);
						n = (n && n<strlen(s)) ? n : strlen(s);
						if (ch1 == '+' || ch1 == ' ')
						{
							while (m-- - n > 0)putchar(' ');
						}
						for (size_t i = 0; i < n; ++i)
							putchar(*(s + i));
						if (ch1 == '-')
						{
							while (m-- - n > 0)putchar(' ');
						}
						break;
			}
			case '%':
			{
						putchar('%');
						break;
			}
			case'n'://可以将所输出字符串的长度值赋给一个变量。eg.int len;printf("abcdefg%n",&len);
				break;                                        //执行后变量被赋值为7.

			case'a'://浮点数、十六进制数字和p-(P-)计数法
			case'A':
				break;
			case'e'://浮点数指数输出
			case'E':
				break;
			case 'g'://自动选f格式或e格式中较短的一种输出，且浮点数不显示无意义的零
			case 'G':
				break;
			default:
				putchar(*format);
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

//已完成:%c %d %i %u %f %o %x/X %p %s %%  未完成:(%a/A %e/E  %g/G) %n
int main()
{
	printf("%%%\n");
	print5("%%%\n");
	system("pause");
	return 0;
}