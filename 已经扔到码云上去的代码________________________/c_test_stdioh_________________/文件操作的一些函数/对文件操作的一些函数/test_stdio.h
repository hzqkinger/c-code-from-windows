#pragma once

//#include<yvals.h>

void test2()
{
	//一.对文件的操作
	//① int remove(const char *filename);
	//② int rename(const char *old,const char *new)
	//③ FILE *tmpfile(void)
	//④ char *tmpnam(char *s)

	//二.文件访问函数
	////① int fclose(FILE *stream)
	////② FILE *fopen(const char *filename,const char *mode)
	//FILE *file1 = fopen("test2.txt", "r"); //r w a rb wb ab  r+ w+ a+ rb+ wb+ ab+
	////③ fclose(file1);
	////④ int fflush(FILE *stream)
	//printf("%ld\n", ftell(file1));
	//char _ch = fgetc(file1); printf("%c\n", _ch);
	//printf("%ld\n", ftell(file1));
	//fflush(file1);//本质上将文件指针指向文件末尾
	//_ch = fgetc(file1); printf("%c\n", _ch);
	//printf("%ld\n", ftell(file1));
	//printf("%d\n", sizeof(FILE));//FILE类型的大小
	////⑤ FILE *freopen(const char *filename,const char *mode,FILE *stream)
	//FILE *file3 = freopen("test3.txt", "r", file1);//①文件重定位函数.调用成功返回file1,否则返回NULL
	//_ch = fgetc(file1); printf("%c\n", _ch);//②这个函数会关闭file1原来指向的文件，然后让file1重新指向一个文件"test3.txt"
	//_ch = fgetc(file3); printf("%c\n", _ch);//③现在file1与file3指针都指向文件"test3.txt"
	//fclose(file1);
	//fclose(file3);//引用计数的原理(两个指针同时指向同一个文件)


	//晕 ⑥ void stebuf(FILE *stream,char *buf)
	//   ⑦ int setvbuf(FILE *stream,char *buf,int mode,size_t size)//

	//三.格式化的输入输出函数
	//char arr[15]; int i = 0;
	////① int fprintf(FILE *stream,const char *format,...)//从程序中写数据到文件中
	////② int fscanf(FILE *stream,const char *format,...)//从文件中扫描数据到程序中
	//file1 = fopen("test2.txt", "r");
	//file3 = fopen("test3.txt", "a");
	//printf("         %d      \n", ftell(file1));
	//printf("         %d      \n", ftell(file3));
	//fscanf(file1, "%1d", &i); //c编译在碰到空格，TAB，回车或非法数据时即认为该数据输入结束
	//printf("         %d      \n",ftell(file1));
	//fprintf(file3,"%d",i);
	//printf("         %d      \n", ftell(file3));
	//fclose(file1);
	//fclose(file3);

	////③ int printf(const char *format,...)//从程序中写数据到屏幕上
	////④ int scanf(const char *format,...)//从键盘扫描数据到程序中
	//scanf("%s%*d%d", arr,&i);//输入多个数据时，c编译在碰到空格，TAB，回车或非法数据时即认为该数据输入结束
	//printf("%s %d",arr,i);

	////⑤ int sprintf(char *s,const *format,...)//从程序中写数据到数组中
	////⑥ int sscanf(char *s,const *format,...)//从数组中扫描数据到程序里
	//char arr2[] = "55 abcdef 66 8a";
	//char arr3[10], arr4[10]; int i2, i3;
	//sscanf(arr2, "%d%s%s%d",&i2,arr3,arr4,&i3);
	//char arr5[20];
	//sprintf(arr5, "%d:%d->%s->%s", i2, i3, arr3, arr4);//自动会在arr5后面添加'\0'字符

	//难 ⑦ int vfprintf(FILE *stream,const char *format,va_list arg)
	//   ⑧ int vprintf(const char *format,va_list arg)
	//   ⑨ int vsprintf(const char *s,const char *format,va_list arg)

	//四.字符输入输出函数
	////① int fgetc(FILE *stream)//从某个文件中扫描一个字符或字符串到程序中
	////⑤ int getc(FILE *stream)
	////② char *fgets(char *s,int n,FILE *stream)
	////③ int fputc(int c,FILE *stream)//从程序中写一个字符或字符串到文件中
	////⑧ int putc(int c,FILE *stream)
	////④ int fputs(const char *s,FILE *stream)
	//FILE *fptr2 = fopen("test2.txt", "r");
	//FILE *fptr3 = fopen("test3.txt", "a");
	//fputc(fgetc(fptr2), fptr3);
	//printf("%d  %d\n", ftell(fptr2), ftell(fptr3));
	//putc(getc(fptr2), fptr3);
	//printf("%d  %d\n", ftell(fptr2), ftell(fptr3));
	//char arr7[15];
	//fputs(fgets(arr7,10,fptr2), fptr3);
	//printf("%d  %d\n", ftell(fptr2), ftell(fptr3));
	//fclose(fptr2);
	//fclose(fptr3);

	////⑥ int getchar(void)//从键盘中扫描一个字符或字符串到程序中
	////⑦ char *gets(char *s)
	////⑨ int putchar(int c)//从程序中写一个字符或字符串到屏幕上
	////   int puts(const char *s)
	//char arr9[15];
	//putchar(getchar());
	//puts(gets(arr9));//gets只有遇到换行符才停止读入

	////   int ungetc(int c,FILE *stream)//将一个字符回退到一个文件中去
	//FILE *fptr3 = fopen("test3.txt", "r");
	//char ch = fgetc(fptr3);
	//printf("   %d ", ftell(fptr3));
	//ungetc(ch, fptr3);
	//printf("   %d ", ftell(fptr3));

	//五.直接输入输出函数
	////① size_t fread(void *ptr,size_t size,size_t nmemb,FILE *stream)
	////② size_t fwrite(void *ptr,size_t size,size_t nmemb,FILE *stream)
	//char ch[10] = ""; int i;
	//FILE *fptr2 = fopen("test2.txt", "r");
	//FILE *fptr3 = fopen("test3.txt", "a");
	//fread(ch, 1,5, fptr2);//从文件中扫描5个元素到数组ch中
	//printf("  %d  ", ftell(fptr2));
	//fread(&i, sizeof(int), 1, fptr2);
	//printf("  %d  ", ftell(fptr2));
	//fwrite(&i, sizeof(int), 1, fptr3);
	//fclose(fptr2);
	//fclose(fptr3);

	//六.文件定位函数
	//难 ① int fgetpos(FIle *stream,fpos_t *pos)
    //   ③ int fsetpos(FILE *stream,const fpos_t *pos)

	////② int fseek(FILE *stream,long int offset,int whence)
	////④ long int ftell(FILE *stream)
	////⑤ void rewind(FILE *stream)
	//FILE *fptr = fopen("test2.txt", "r"); int n = 1;
	//for (char ch = fgetc(fptr); ch != EOF; ch = fgetc(fptr)){
	//	printf("%d ", ftell(fptr));
	//	if (ftell(fptr) == 15 && n == 1){
	//		/*fseek(fptr, 0, SEEK_SET);*/rewind(fptr);
	//		--n; }
	//}

	//七.错误处理函数
	//① void clearerr(FILE *stream)
	//③ int ferror(FILE *stream)

	//② int feof(FILE *stream)//测试stream指向的流的文件结束符
	//④ void perror(const char *s)//
}