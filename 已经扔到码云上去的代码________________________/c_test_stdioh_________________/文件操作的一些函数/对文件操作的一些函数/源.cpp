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
//	//d = fflush(stdin);//��������ջ�����
//	//c = getchar();
//
//	//char*p;/*= NULL*/
//	//char arr[25] = "abc";
//	///*p = arr;
//	//puts(p);*/
//	//FILE *fp;
//	//fp = fopen("data3.txt", "r");//�ݴ���Ϊdata3.txt���ļ�
//	//if (fp == NULL)
//	//{
//	//	perror("data3");
//	//	exit(EXIT_FAILURE);
//	//}
//	//p = fgets(arr,20, fp);
//	//printf(arr);
//	//printf(p);
//	//fclose(fp);//�۹ر�fpָ����ļ�
//
//	//FILE*input, *output;
//	//char bufr[512];
//	//input = fopen("data3.txt", "r");
//	//output = fopen("macky,txt", "w");
//	//if (setvbuf(input, bufr, _IOFBF, 512) != 0)//�޸ú������ܣ��ѻ�����������أ�������������
//	//	printf("failed to set up buffer for input\n");
//	//else
//	//	printf("haha\n");
//	//if (setvbuf(output, NULL, _IOLBF, 132) != 0)
//	//	printf("failed to set up buffer for output\n");
//	//else
//	//	printf("hehe\n");
//
//	//�ٸ�ʽ�����������������printf()  fprintf()  sprintf()  vprintf()  vfprintf()  vaprintf()
//	//  scanf()   fscanf()   sscanf()
//	//���ַ��������������putchar()  putc()  fputc()  puts()  fputs()
//	//  getchar()  getc()  fgetc()  gets()  fgets()
//	//��ֱ���������������size_t fread(void *ptr,size_t size,size_t nmemb,FILE*stream);
//	//  size_t fwrite(const void *ptr,size_t size,size_t nmemb,FILE*stream);
//	int x;
//	int a;                     //���ļ�������һЩ����
//	char b, c[100];
//	char d[100];
//	char e[100];
//	char* str = "asd";
//
//	//char name1[11], name2[11];      //scanf()����ָ���ֶο�ȵ�ʹ�������
//	//scanf("%5s%10s", name1, name2);
//	//printf("%s %s\n", name1, name2);
//
//	FILE *input;
//	input = fopen("data3.txt", "a");//�ı��ļ��򿪷�ʽ  ��"r"  "w"  "a"  "r+"  "w+"  "a+"
//	if (input == NULL)              //�������ļ��򿪷�ʽ��"rb"  "wb"  "ab"  "a+b"  "wb+"  "w+b"  "ab+"
//	{                               //
//		perror("data3");            //
//		exit(EXIT_FAILURE);         //
//	}
//
//	//fgets(d, 4, input);//���ļ��ж�ȡ4-1���ַ�
//	//printf("%s\n", d);
//	//fscanf(input, "%s", c);//���ļ��ж�ȡһ���ַ���
//	//fscanf(input, "%4s", c);//���ļ��ж�ȡ4���ַ���
//	//printf("%s\n", c);
//
//	//fscanf(input, "%c", &b);//���ļ��ж�ȡһ���ַ�
//	//printf("%c\n", b);
//	//printf("%c\n",getc(input));//���ļ��ж�ȡһ���ַ�
//	//putchar(fgetc(input));
//	//ungetc(a = getc(input), input);//���ַ��Ż��ļ���ȥ
//	//printf("%c\n",getc(input));
//	//ungetc(a, input);
//	//printf("%c\n", getc(input));
//	//printf("%c\n", a);
//
//	//sprintf(e, "%s", str);//��strָ����ַ���д�뵽����e��
//	x = fprintf(input, "%s", str);//���ļ���д��һ���ַ���
//	x = fputs(str, input);
//	//fputs("eeeacd", input);//���ļ���д��һ���ַ���
//	//fputc('abc', input);//���ļ���д��һ���ַ�
//	//putc('a', input);
//	//char arr[] = "abcdv   efg";
//	//puts(arr+5);//�β���const���޶�������Ϊ��ȷ����������ʵ�β���ı䡣
//
//	fclose(input);
//
//	//getchar()��scanf()
//
//	////getchar()��˳��� ������ ����ÿһ���ַ����൱�������������ÿ��ȡһ�λ�������һ���ַ���ֱ���������е����ݱ���ȡ�ꡣ
//	////putchar(ch)Ŀǰֻ֪��������������ַ�ch��
//	////scanf()�ڶ�ȡ����ʱ�������ո��Ʊ���ͻ��з���getchar()��ȡÿһ���ַ��������ո��Ʊ���ͻ��з���
//	////scanf()�ķ���ֵ�����ɹ��������Ŀ���������ݸ�������
//	//char ch;
//	//while ((ch = getchar()) != '\n')//   '\n'�ͱ�ʾenter����
//	//putchar(ch);
//	////SUMMARY�������֮���������ַ���ɣ���scanf()���Խ�����ת��������ֵ���߸�������ʹ����%d��%f������˵�����ɽ��ܵ�������ַ����ͣ���getchar()��ʹ��%c��scanf()�����κ��ַ���
//	//int input;
//	//while (scanf("%d", &input) != 1)
//	//while ((getchar()) != '\n');//�������������޳���������루��������������ݲ��Ϸ��������ͻ���������������������ַ���
//	//printf("%d\n", input);
//}



int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}