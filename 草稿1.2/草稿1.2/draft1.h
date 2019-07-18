#pragma once

void Print(char *s)//递归
{
	if (*s)
	{
		//printf("%c", *s);
		Print(++s);
		printf("%c", *s);
	}
}
void tEst1()
{
	char str[] = "Geneius";
	Print(str);
	printf("\n");
}

struct test{
	int m1;
	//char m2;
	//float m3;
	union uu{            //联合体类型
		char u1[5];
		int u2[2];
	}ua;
};
typedef char Stri[20];
void tEst2()
{
	Stri s;
	printf("%d\n", sizeof(test));
}

//void intf(int *p)
//{
//	printf("%d\n",*p);
//	printf("%p\n", p);
//}
//void tEst3()
//{
//	//int val = 5;
//	//intf(&val);
//	//intf((int[]){5});//复合字面量  (在.c文件中，可以这样强转)
//	intf(reinterpret_cast<int*>(5));
//}

void tEst4()
{
	int num;
	while (scanf("%d", &num) == 1)
	{
		puts("如果想结束，请按除了数字之外的任意键");
	}
}

#if 0
enum col
{
	G,
	R,
	B
}Color;
typedef struct student
{
	int a;
	char c;
}stu, *pstu;
#define a int[10]
int main()
{
	printf("%d\n", sizeof(Color));//4，枚举类型占字节数

	//typedef char str;
	//str s;
	//s = 'w';

	typedef int STRING[3];         //typedef还可以这样定义字符数组
	STRING s[3];//可能等价于 char s[3]
	s[1][2] = 1;
	s[2][2] = 0;

	//s[0] = 'W';
	//s[1] = 'A';
	//s[2] = 0;
	printf("%s\n", s);

	const pstu stu3;//这里const修饰stu3，因为pstu是一个整体。

	system("pause");
	return 0;
}
#endif

void tEst6()
{

  int a = 4294967295;
  int b = 4294967294;
  printf("%d %d\n", a, b);
  a = a ^ b;                     //两种交换方法都正确，即使溢出。
  b = a ^ b;
  a = a ^ b;
  //a = a + b;
  //b = a - b;
  //a = a - b;
  printf("%d %d\n", a,b);

	//char arr[128];
	//int i;
	//for (i = 0; i < 128; i++)//0   '0'    '\0' 三者之间的区别
	//	arr[i] = i;
	//printf("%s\n",arr+1);

	//char i = 0;
	//printf("%d\n", i);//0   '0'    '\0' 三者之间的区别
}

void tEst7()
{
	//int a =/*/*/2 */**/1;
	//char *p = "";/*/**/"*/"/*"               //该编译器不允许注释嵌套
	//printf("%s\n", p);

	//int a = 1, b = 2;
	//printf("%d\n", (++a)++ + b);//(++a)++ + b可以再C++下编译过去，C不行；a+++++b在C/C++都编译不过
	//因为++a返回左值，a++返回右值

	//int a = 011;//如果一个整型常量的第一个字符是数字0，那么该常量被视为八进制数
	//printf("%d\n", a);   //单引号括起的一个字符代表一个整数；双引号括起的一个字符代表一个指针。

	int b = printf("\141");  //输出ASCII码，\141是八进制数（\d或\dd或\ddd都表示八进制数）
	int c = 3;
	int a = printf("%d%d\n",b,c);  //printf的副作用，返回字符串的长度。
	//a++;
	printf("%d\n", a);
	int d = printf("abcde");
	cout << d;

	char *s = "123456789";
	int e = printf(s);//打印了字符串，并且计算了它的长度
	cout << e;
}

void tEst8()
{
	volatile const int a = 10;    //在.c文件下a被改变可以显示出来；在.cpp文件下a被改变但不显示，因
	printf("%d\n", a);   //为a被拿到寄存器里面了（可以通过关键字volatile显示出来）保证内存可见性
	//解决常量折叠问题
}

//void tEst9()  //写不出来，以后在写。
//{
//	int cnt = 0,i = 0,j = 0;
//	char arr[10][10] = { 0 };
//	char*tmp = NULL;
//	char(*p)[10] = arr;
//	printf("请输入你要输入几个数：\n");
//	scanf("%d", &cnt);
//	for (i = 0; i < cnt; i++)
//		scanf("%s", p[i]);
//	for (i = 0; i < cnt; i++)
//	{
//		for (j = i + 1; j < cnt; j++)
//		{
//			if (strcmp(p[i], p[j]) < 0)
//			{
//				tmp = p[i];
//				p[i] = p[j];
//
//				//strcpy(tmp, p[i]);
//				//strcpy(p[i], p[j]);
//				//strcpy(p[j], tmp);
//			}
//		}
//	}
//	for (i = 0; i < cnt; i++)
//		printf("%s", p[i]);
//}

////对文件的操作
//int remove(const char*p);
//int rename(const char*p, const char*p2);
//FILE*tmpfile(void);
//char*tmpname(char*p);
////文件访问函数
//int fclose(FILE*fp);
//int fflush(FILE*fp);
//FILE*fopen(const char* p1, const char *p2);
//FILE*fropen(const char* p1, const char *p2, FILE*fp);
//void setbuf(FILE*fp, char*p);
//void setvbuf(FILE*fp, char*p, int i, size_t size);
////格式化输入输出函数
//int sscanf(const char*p, const char*format, ...);
//int fscanf(FILE*fp, const char*p, ...);
//int scanf(const char*format, ...);
//int fprint(FILE*fp, const char*format, ...);
//int printf(const char*format, ...);
//int sprintf(char*p, const char*format, ...);
//int vfprintf(FILE*fp, const char*p1, char*p2);
//int vprintf(const char*p1, char*p2);
//int vsprintf(char*p1, const char*p2, char*p3);
////字符输入输出函数
//int getchar(void);
//int getc(FILE*fp);
//int fgetc(FILE*fp);
//char*gets(char*p);
//char*fgets(char*p, int num, FILE*fp);
//int ungetc(int i, FILE*fp);
//int putchar(int i);
//int putc(int i, FILE*fp);
//int fputc(int i, FILE*fp);
//int puts(const char*p);
//int fputs(const char* p, FILE*fp);
////直接输入输出函数
//size_t fread(void*p, size_t size1, size_t size2, FILE*fp);
//size_t fwrite(const void*p, size_t size1, size_t size2, FILE*fp);
////文件定位函数
//int fgetpos(FILE*fp, fpos_t*pos);
//int fseek(FILE*fp, long l, int i);
//int fsetpos(FILE*fp, const fpos_t*p);
//long ftell(FILE*fp);
//void rewind(FILE*fp);
////错误处理函数
//void clearerr(FILE*fp);
//int feof(FILE*fp);
//int ferror(FILE*fp);
//void perror(const char*p);
////其他
//long _Fgpos(FILE*fp, fpos_t*pos);
//int _Fspos(FILE*fp, const fpos_t*pos, long l, int i);
//extern FILE*_Files[FOPEN_MAX];


void test_draft1()
{
	//tEst1();//Genius 的递归
	//tEst2();//结构体占字节数
	//tEst3();//强制类型转换                           .cpp文件下出错
	//tEst4();//scanf()输入不确定个数的整型数据
	//tEst6();//两个整型数据的交换方法
	tEst7();//注释嵌套，printf()函数的副作用
	//tEst8();//const与volatile
	//tEst9();//                                    出错
}