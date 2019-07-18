#pragma once
#include<stdio.h>


//一.对文件的操作
//1. int remove(const char *filename);
//2. int rename(const char *oldname,const char *newname);
void test1()
{
	//FILE *fp = fopen("test10.txt", "w");

	//remove("test10.txt");  //①删除文件；如果删除已打开的文件，那么是由remove函数实现来决定是否会删除该文件。
	//                                                                          //(在这里，不能删除已经打开的文件)
	int n = rename("test10.txt", "test12.txt");  //注意，打开着的文件不能修改文件名；前面的文件名必须存在，后面的不能存在才会修改成功
	printf("%d\n", n);//②修改文件名，操作成功返回0，失败则返回非0.
}

//二.文件访问函数
//1. int fclose(FILE *stream);
//2. int fflush(FILE *stream);
//3. FILE *fopen(const char *filename,const char *mode);
//4. FILE *freopen(const char *filename,const char *mode,FILE *stream);
//5. void setbuf(FILE *stream,char *buf);
//6. int setvbuf(FILE *stream,char *buf,int mode,size_t size);
void test_fflush()
{
	char c;
	scanf("%c", &c);
	printf("%d\n", c);
	//fflush(stdin);//作用是清空stdin指向的缓冲流
	scanf("%c", &c);
	printf("%d\n", c);

//	fflush has no effect on an unbuffered stream.
    //Buffers are normally maintained by the operating system, 
	//which determines the optimal time to write the data automatically to disk :
	//when a buffer is full, when a stream is closed, or when a program terminates normally 
	//	without closing the stream.
}
void test2()
{
	//FILE *fp = fopen("test20.txt", "r");
	//char ch = fgetc(fp);
	//printf("%c\n", ch);
	//fflush(fp);//表面作用是清空fp指向的缓冲流,(实质是将文件定位符指向文件末尾)
	//ch = fgetc(fp);
	//printf("%c\n", ch);//有点疑惑，文件末尾的后面都是换行符吗?(难道就是用换行符这种机制来区分空文件和不存在的文件吗?)
	//fclose(fp);

	////FILE *fp2 = freopen("test22.txt", "w", stdout);//用于重定向标准文件流
	////if (fp2 == NULL)
	////	printf("freopen failed\n");
	////printf("i am happily running\n");
	////ch = fgetc(fp2);
	////printf("%c\n", ch);

	char arr[5] = { 0 };//作为制定缓冲区（size为奇数和偶数有很大差别）
	FILE *fp3 = fopen("test23.txt", "w");
	setvbuf(fp3, arr,_IOFBF,sizeof(arr));//设置arr为fp3的缓冲区
	for (int i = 0; i < 10; ++i)
		fputc(i + '0', fp3);
	//fflush(fp3);//貌似这句话在这里没什么用处
	printf(arr);
	fclose(fp3);
}

//三.格式化的输入输出函数
//1. int fprintf(FILE *stream,const char *format,...);
//2. int fscanf(FILE *stream,const char *format,...);
//3. int printf(const char *format,...);
//4. int scanf(const char *format,...);
//5. int sprintf(char *s,const char *format,...);
//6. int sscanf(const char *s,const char *format,...);
//7.8.9 vfprintf,vprintf,vsprintf
void test3()
{
	//FILE *fp = fopen("test30.txt", "r");
	//int years = 22;
	//fprintf(fp, "h e l lo world,i am %d years old\n", years);//按照格式输入到fp指向的文件流
	//printf("%d\n", ftell(fp));              //注意，fprintf函数在文件只读或追加模式下才有效
	//rewind(fp);
	//printf("%d\n", ftell(fp));
	//
	////for (int i = 0; i < 3;++i)
	////{
	////	char ch[10] = { 0 };
	////	int n = fscanf(fp, "%s", ch);//注意，fscanf函数仅仅在文件只读模式下才有效，其他模式一律失效
	////	//printf("%d\n", n);
	////	printf("%s\n", ch);
	////}
	//fclose(fp);

	//printf 和 scanf就不测试了，(fprintf,fscanf,sprintf,sscanf的具体使用，请参考对printf和scanf的使用)

	//char str[20] ="hello world:%d-%d\n";
	//int year = 2018, month = 8;
	//sprintf(str+2, str + 6, year, month);//按照格式输入到数组中
	//printf(str);
	//int m, n;
	//sscanf(str, "heworld:%d-%d\n", &m, &n);//按照格式从数组中读数据
	//printf("%d-%d\n", m, n);
}

//四.字符输入输出函数  (//注意，只有6,7,9,10默认跟标准文件流相关)
//1.  int fgetc(FILE *stream);
//2.  char *fgets(char *s,int n,FILE *stream);
//3.  int fputc(int c,FILE *stream);
//4.  int fputs(const char *s,FILE *stream);

//5.  int getc(FILE *stream);
//8.  int putc(int c,FILE *stream);

//6   int getchar();               //从stdin中读取一个字符
//7.  char *gets(char *s);         //从stdin中读取一个字符串
//9.  int putchar(int c);          //将字符c写到stdout
//10. int puts(const char *s);     //将字符串s写到stdout

//11. int ungetc(int c,FILE *stream);
void test4()
{
	//FILE *fp = fopen("test40.txt", "r");
	//for (int i = 0; i < 10; ++i)
	//	fputc(i + 'a', fp);//注意，fputc函数在文件只读或追加模式下才有效
	//putc('z', fp);//注意，putc函数在文件只读或追加模式下才有效
	//ungetc('y', fp);//失效
	//fputs("how are you", fp);//注意，fputs函数在文件只读或追加模式下才有效
	//
	//rewind(fp);
	//printf("%c\n", getc(fp));//注意，getc函数仅仅在文件只读模式下才有效
	//ungetc('y', fp);//貌似只有在文件只读模式下才有效
	//printf("%c\n", fgetc(fp));//注意，fgetc函数仅仅在文件只读模式下才有效
	//char str[5] = { 0 };
	//printf("%s\n", fgets(str, sizeof(str)-1, fp));//注意，fgets函数仅仅在文件只读模式下才有效
	//printf(str);
	//fclose(fp);

	//getchar,gets,putchar,puts就不测试了
}

//五.直接输入输出函数
//1. size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
//2. size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
void test5()
{
	FILE *fp = fopen("test50.txt", "r");
	char arr[] = "heh";
	int ins = 49;
	for (int i = 0; i < 10; ++i)
		fwrite(&ins, sizeof(ins), 1, fp);//注意，fwrite函数在文件只读或追加模式下才有效

	rewind(fp);
	for (int i = 0; i < 10; ++i)
	{
		int ins2;
		fread(&ins2, sizeof(ins2), 1, fp);//注意，fread函数仅仅在文件只读模式下才有效
		printf("%d\n", ins2);
	}
		

	fclose(fp);
}

//六.文件定位函数
//1. int fgetpos(FILE *stream,fpos_t *pos);
//2. int fseek(FILE *stream,long int offset,int whence);//fseek为stream指向的流的设置文件定位符
//3. int fsetpos(FILE *stream,const fpos_t *pos);//fsetpos根据pos指向的值来设置stream指向的流的文件定位符
//4. long int ftell(FILE *stream);
//5. void rewind(FILE *stream);//rewind为stream指向的流的设置文件定位符
void test6()
{
	FILE *fp = fopen("test60.txt", "r");

	fseek(fp, -22, SEEK_END);//

	fpos_t ps;
	int ps2 = fgetpos(fp, &ps);
	printf("pos_t:%lld,int:%d\n", ps, ps2);

	fclose(fp);
}

//七.错误处理函数
// clearerr feof ferror perror