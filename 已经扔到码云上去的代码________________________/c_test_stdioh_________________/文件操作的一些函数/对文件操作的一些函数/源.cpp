#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>

#include"test_stdio.h"

//void test1()
//{

//
//	//int a, c,d;
//	//scanf("%d",&a);
//	//d = fflush(stdin);//④用于清空缓冲流
//	//c = getchar();
//
//	//char*p;/*= NULL*/
//	//char arr[25] = "abc";
//	///*p = arr;
//	//puts(p);*/
//	//FILE *fp;
//	//fp = fopen("data3.txt", "r");//⑤打开名为data3.txt的文件
//	//if (fp == NULL)
//	//{
//	//	perror("data3");
//	//	exit(EXIT_FAILURE);
//	//}
//	//p = fgets(arr,20, fp);
//	//printf(arr);
//	//printf(p);
//	//fclose(fp);//③关闭fp指向的文件
//
//	//FILE*input, *output;
//	//char bufr[512];
//	//input = fopen("data3.txt", "r");
//	//output = fopen("macky,txt", "w");
//	//if (setvbuf(input, bufr, _IOFBF, 512) != 0)//⑥该函数功能：把缓冲区与流相关（看不懂啊啊）
//	//	printf("failed to set up buffer for input\n");
//	//else
//	//	printf("haha\n");
//	//if (setvbuf(output, NULL, _IOLBF, 132) != 0)
//	//	printf("failed to set up buffer for output\n");
//	//else
//	//	printf("hehe\n");
//
//	//①格式化的输入输出函数：printf()  fprintf()  sprintf()  vprintf()  vfprintf()  vaprintf()
//	//  scanf()   fscanf()   sscanf()
//	//②字符输入输出函数：putchar()  putc()  fputc()  puts()  fputs()
//	//  getchar()  getc()  fgetc()  gets()  fgets()
//	//③直接输入输出函数：size_t fread(void *ptr,size_t size,size_t nmemb,FILE*stream);
//	//  size_t fwrite(const void *ptr,size_t size,size_t nmemb,FILE*stream);
//	int x;
//	int a;                     //对文件操作的一些函数
//	char b, c[100];
//	char d[100];
//	char e[100];
//	char* str = "asd";
//
//	//char name1[11], name2[11];      //scanf()函数指定字段宽度的使用情况。
//	//scanf("%5s%10s", name1, name2);
//	//printf("%s %s\n", name1, name2);
//
//	FILE *input;
//	input = fopen("data3.txt", "a");//文本文件打开方式  ："r"  "w"  "a"  "r+"  "w+"  "a+"
//	if (input == NULL)              //二进制文件打开方式："rb"  "wb"  "ab"  "a+b"  "wb+"  "w+b"  "ab+"
//	{                               //
//		perror("data3");            //
//		exit(EXIT_FAILURE);         //
//	}
//
//	//fgets(d, 4, input);//从文件中读取4-1个字符
//	//printf("%s\n", d);
//	//fscanf(input, "%s", c);//从文件中读取一行字符串
//	//fscanf(input, "%4s", c);//从文件中读取4个字符串
//	//printf("%s\n", c);
//
//	//fscanf(input, "%c", &b);//从文件中读取一个字符
//	//printf("%c\n", b);
//	//printf("%c\n",getc(input));//从文件中读取一个字符
//	//putchar(fgetc(input));
//	//ungetc(a = getc(input), input);//把字符放回文件中去
//	//printf("%c\n",getc(input));
//	//ungetc(a, input);
//	//printf("%c\n", getc(input));
//	//printf("%c\n", a);
//
//	//sprintf(e, "%s", str);//将str指向的字符串写入到数组e中
//	x = fprintf(input, "%s", str);//向文件中写入一个字符串
//	x = fputs(str, input);
//	//fputs("eeeacd", input);//向文件中写入一个字符串
//	//fputc('abc', input);//向文件中写入一个字符
//	//putc('a', input);
//	//char arr[] = "abcdv   efg";
//	//puts(arr+5);//形参有const的限定符，是为了确保传进来的实参不会改变。
//
//	fclose(input);
//
//	//getchar()和scanf()
//
//	////getchar()按顺序从 缓冲区 读走每一个字符，相当于清除缓冲区，每读取一次缓冲区少一个字符，直到缓冲区中的数据被读取完。
//	////putchar(ch)目前只知道它单纯的输出字符ch。
//	////scanf()在读取数字时会跳过空格、制表符和换行符；getchar()读取每一个字符，包括空格、制表符和换行符。
//	////scanf()的返回值是它成功读入的项目数（即数据个数）。
//	//char ch;
//	//while ((ch = getchar()) != '\n')//   '\n'就表示enter键。
//	//putchar(ch);
//	////SUMMARY；简而言之，输入由字符组成，但scanf()可以将输入转化成整数值或者浮点数。使用像%d或%f这样的说明符可接受的输入的字符类型，但getchar()和使用%c的scanf()接受任何字符。
//	//int input;
//	//while (scanf("%d", &input) != 1)
//	//while ((getchar()) != '\n');//该语句的作用是剔除错误的输入（假如所输入的数据不合法，该语句就会逐个清除缓冲区里的所有字符）
//	//printf("%d\n", input);
//}



int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}