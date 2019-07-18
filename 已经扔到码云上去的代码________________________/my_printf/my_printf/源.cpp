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
			{//�����֣�+��-��#����ţ�����ѭ����                                                //��ź������������
				switch (*format)
				{
				case'+':
				{
						   if (ch1 != '-')ch1 = '+';
						   break;
				}
				case'-':
				{
						   ch1 = '-';//��'-'�������ȸ�ch1��ֵΪ'-'��
						   break;
				}
				case'#'://ֻ��o��x������ //����o�࣬�����ʱ��ǰ׺0������x�࣬�����ʱ��ǰ׺0x��
				{
							ch3 = '#';
				}
				case'0'://ch1��ʾ'+','-'��ch2��ʾ'0','��'
				{
							if (!isdigit(*(format - 1)))//���*format=='0'ʱ��ǰһ���ַ���������(������'0')
							{
								//ch1 = '-';
								ch2 = '0';
								break;
							}//'0','+'������(���+000xxxx)��'0','-',('+')������(���+xxxx)��
				}
					//�ڴ���m,nʱ���Ѿ���ch1��ch2������ˡ�
				case'1':
				case'2'://m��ʾ�������Ӧ�������������豸��ռ�ֽ���
				case'3':       //ָ��ռ�ֽ���m �� ʵ��ռ�ֽ����������������豸��ռ�ֽ���ȡ�������ֵ
				case'4'://n��ʾ���ȣ���Ҫ����˵�������ʵ������С��λ��
				case'5':      //��������15����%6.2d->    15����%6.4d->  0015����%6.8d->000015
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
			case 'c'://���cʱֻ�����m�йء�
			{
						 char ch = va_arg(arg, char);
						 if (ch1 == '+'|| ch1 == ' ')
						 while (--m)putchar(ch2);//ch2�����ǿգ�Ҳ������0.
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
						n = n > count ? n : count;//��֤n���������ֵ
						if (ch1 == '+'|| ch1 == ' ')
						{
							while (--m - n>0)putchar(' ');//��m>n,�ⲽ�Ľ������m = n������m<n���ⲽ��Ч
							if (i>0 && ch1 != ' ')
								putchar('+');
							while (n - count > 0)--n, putchar('0');//����n<count���ⲽ��Ч
						}

						if (ch1 == '-')
						{
							int tmpn = n;;
							while (tmpn-- - count > 0)putchar('0');//����n<count���ⲽ��Ч
						}
						f1(i, *format);
						if (ch1 == '-')
						while (m - n>0)--m, putchar(' ');//����m<n���ⲽ��Ч
						break;
			}
			case 'u':
			{
						int u = va_arg(arg, unsigned int);
						size_t tmp = u, count = 0;
						while (tmp)++count, tmp /= 10;
						n = n > count ? n : count;//��֤n���������ֵ
						if (ch1 == '+' || ch1 == ' ')
						{
							while (--m - n>0)putchar(' ');//��m>n,�ⲽ�Ľ������m = n������m<n���ⲽ��Ч
							if (u>0 && ch1 != ' ')
								putchar('+');
							while (n - count > 0)--n, putchar('0');//����n<count���ⲽ��Ч
						}

						if (ch1 == '-')
						{
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//����n<count���ⲽ��Ч
						}
						f1(u, *format);
						if (ch1 == '-')
						while (m - n>0)--m, putchar(' ');//����m<n���ⲽ��Ч
						break;
			}
			case 'f':
			{
						double f = va_arg(arg, double);
						if (0x80 & *((char*)(&f + 1) - 1))//�жϸø������Ƿ�Ϊ����
						{//����д������д��:if(f<0)
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
							while (--m - count>0)putchar(ch2);//����m<count���ⲽ��Ч
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

			case 'o'://û����ch2 == '0'�����
			{
						int o = va_arg(arg, unsigned int);
						size_t tmp = o, count = 0;
						while (tmp)++count, tmp /= 8;
						n = n > count ? n : count;//��֤n���������ֵ
						if (ch3 == '#')++n;
						if (ch1 == '+' || ch1 == ' ')
						{
							int tmpm = m;
							while (tmpm-- - n>0)putchar(' ');//����m<n���ⲽ��Ч
							if (m && m<n)--n;
							while (n - count > 0)--n, putchar('0');//����n<count���ⲽ��Ч
						}

						if (ch1 == '-')
						{
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//����n<count���ⲽ��Ч
						}
						f1(o, *format);
						if (m<n)--n;
						if (ch1 == '-')
						while (m - n>0)--m, putchar(' ');//����m<n���ⲽ��Ч
						break;
			}
			case'X':
				;
			case 'x'://û����ch2 == '0'�����
			{
						int x = va_arg(arg, unsigned);

						size_t tmp = x, count = 0;
						while (tmp)++count, tmp /= 16;
						n = n > count ? n : count;//��֤n���������ֵ
						if (ch3 == '#')m -= 2;
						if (ch1 == '+' || ch1 == ' ')
						{
							int tmpm = m;
							while (tmpm-- - n>0)putchar(' ');//����m<n���ⲽ��Ч
							if (ch3 == '#')putchar('0'),putchar('x');
							while (n - count > 0)--n, putchar('0');//����n<count���ⲽ��Ч
						}

						if (ch1 == '-')
						{
							if (ch3 == '#')putchar('0'), putchar('x');
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//����n<count���ⲽ��Ч
						}
						f1(x, *format);
						if (ch1 == '-')
						{
							m -= 1;
							while (m - n>0)--m, putchar(' ');//����m<n���ⲽ��Ч
						}
						break;
			}
			case 'p'://û����ch2 == '0'�����
			{
						int p = va_arg(arg, unsigned int);
						size_t tmp = p, count = 0;
						while (tmp)++count, tmp /= 16;
						n = 8;
						if (ch1 == '+' || ch1 == ' ')
						{
							int tmpm = m;
							while (tmpm-- - n>0)putchar(' ');//����m<n���ⲽ��Ч
							if (ch3 == '#')putchar('0'), putchar('x');
							while (n - count > 0)--n, putchar('0');//����n<count���ⲽ��Ч
						}

						if (ch1 == '-')
						{
							if (ch3 == '#')putchar('0'), putchar('x');
							int tmpn = n;
							while (tmpn-- - count > 0)putchar('0');//����n<count���ⲽ��Ч
						}
						f1(p, *format);

						if (ch1 == '-')
						{
							m -= 2;
							while (m - n>0)--m, putchar(' ');//����m<n���ⲽ��Ч
						}
						break;
			}
			case 's'://û����ch2 == '0'  ��ch3 == '#'�����
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
			case'n'://���Խ�������ַ����ĳ���ֵ����һ��������eg.int len;printf("abcdefg%n",&len);
				break;                                        //ִ�к��������ֵΪ7.

			case'a'://��������ʮ���������ֺ�p-(P-)������
			case'A':
				break;
			case'e'://������ָ�����
			case'E':
				break;
			case 'g'://�Զ�ѡf��ʽ��e��ʽ�н϶̵�һ��������Ҹ���������ʾ���������
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

//�����:%c %d %i %u %f %o %x/X %p %s %%  δ���:(%a/A %e/E  %g/G) %n
int main()
{
	printf("%%%\n");
	print5("%%%\n");
	system("pause");
	return 0;
}