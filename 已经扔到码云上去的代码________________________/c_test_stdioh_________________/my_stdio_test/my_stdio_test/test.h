#pragma once
#include<stdio.h>


//һ.���ļ��Ĳ���
//1. int remove(const char *filename);
//2. int rename(const char *oldname,const char *newname);
void test1()
{
	//FILE *fp = fopen("test10.txt", "w");

	//remove("test10.txt");  //��ɾ���ļ������ɾ���Ѵ򿪵��ļ�����ô����remove����ʵ���������Ƿ��ɾ�����ļ���
	//                                                                          //(���������ɾ���Ѿ��򿪵��ļ�)
	int n = rename("test10.txt", "test12.txt");  //ע�⣬���ŵ��ļ������޸��ļ�����ǰ����ļ���������ڣ�����Ĳ��ܴ��ڲŻ��޸ĳɹ�
	printf("%d\n", n);//���޸��ļ����������ɹ�����0��ʧ���򷵻ط�0.
}

//��.�ļ����ʺ���
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
	//fflush(stdin);//���������stdinָ��Ļ�����
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
	//fflush(fp);//�������������fpָ��Ļ�����,(ʵ���ǽ��ļ���λ��ָ���ļ�ĩβ)
	//ch = fgetc(fp);
	//printf("%c\n", ch);//�е��ɻ��ļ�ĩβ�ĺ��涼�ǻ��з���?(�ѵ������û��з����ֻ��������ֿ��ļ��Ͳ����ڵ��ļ���?)
	//fclose(fp);

	////FILE *fp2 = freopen("test22.txt", "w", stdout);//�����ض����׼�ļ���
	////if (fp2 == NULL)
	////	printf("freopen failed\n");
	////printf("i am happily running\n");
	////ch = fgetc(fp2);
	////printf("%c\n", ch);

	char arr[5] = { 0 };//��Ϊ�ƶ���������sizeΪ������ż���кܴ���
	FILE *fp3 = fopen("test23.txt", "w");
	setvbuf(fp3, arr,_IOFBF,sizeof(arr));//����arrΪfp3�Ļ�����
	for (int i = 0; i < 10; ++i)
		fputc(i + '0', fp3);
	//fflush(fp3);//ò����仰������ûʲô�ô�
	printf(arr);
	fclose(fp3);
}

//��.��ʽ���������������
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
	//fprintf(fp, "h e l lo world,i am %d years old\n", years);//���ո�ʽ���뵽fpָ����ļ���
	//printf("%d\n", ftell(fp));              //ע�⣬fprintf�������ļ�ֻ����׷��ģʽ�²���Ч
	//rewind(fp);
	//printf("%d\n", ftell(fp));
	//
	////for (int i = 0; i < 3;++i)
	////{
	////	char ch[10] = { 0 };
	////	int n = fscanf(fp, "%s", ch);//ע�⣬fscanf�����������ļ�ֻ��ģʽ�²���Ч������ģʽһ��ʧЧ
	////	//printf("%d\n", n);
	////	printf("%s\n", ch);
	////}
	//fclose(fp);

	//printf �� scanf�Ͳ������ˣ�(fprintf,fscanf,sprintf,sscanf�ľ���ʹ�ã���ο���printf��scanf��ʹ��)

	//char str[20] ="hello world:%d-%d\n";
	//int year = 2018, month = 8;
	//sprintf(str+2, str + 6, year, month);//���ո�ʽ���뵽������
	//printf(str);
	//int m, n;
	//sscanf(str, "heworld:%d-%d\n", &m, &n);//���ո�ʽ�������ж�����
	//printf("%d-%d\n", m, n);
}

//��.�ַ������������  (//ע�⣬ֻ��6,7,9,10Ĭ�ϸ���׼�ļ������)
//1.  int fgetc(FILE *stream);
//2.  char *fgets(char *s,int n,FILE *stream);
//3.  int fputc(int c,FILE *stream);
//4.  int fputs(const char *s,FILE *stream);

//5.  int getc(FILE *stream);
//8.  int putc(int c,FILE *stream);

//6   int getchar();               //��stdin�ж�ȡһ���ַ�
//7.  char *gets(char *s);         //��stdin�ж�ȡһ���ַ���
//9.  int putchar(int c);          //���ַ�cд��stdout
//10. int puts(const char *s);     //���ַ���sд��stdout

//11. int ungetc(int c,FILE *stream);
void test4()
{
	//FILE *fp = fopen("test40.txt", "r");
	//for (int i = 0; i < 10; ++i)
	//	fputc(i + 'a', fp);//ע�⣬fputc�������ļ�ֻ����׷��ģʽ�²���Ч
	//putc('z', fp);//ע�⣬putc�������ļ�ֻ����׷��ģʽ�²���Ч
	//ungetc('y', fp);//ʧЧ
	//fputs("how are you", fp);//ע�⣬fputs�������ļ�ֻ����׷��ģʽ�²���Ч
	//
	//rewind(fp);
	//printf("%c\n", getc(fp));//ע�⣬getc�����������ļ�ֻ��ģʽ�²���Ч
	//ungetc('y', fp);//ò��ֻ�����ļ�ֻ��ģʽ�²���Ч
	//printf("%c\n", fgetc(fp));//ע�⣬fgetc�����������ļ�ֻ��ģʽ�²���Ч
	//char str[5] = { 0 };
	//printf("%s\n", fgets(str, sizeof(str)-1, fp));//ע�⣬fgets�����������ļ�ֻ��ģʽ�²���Ч
	//printf(str);
	//fclose(fp);

	//getchar,gets,putchar,puts�Ͳ�������
}

//��.ֱ�������������
//1. size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
//2. size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
void test5()
{
	FILE *fp = fopen("test50.txt", "r");
	char arr[] = "heh";
	int ins = 49;
	for (int i = 0; i < 10; ++i)
		fwrite(&ins, sizeof(ins), 1, fp);//ע�⣬fwrite�������ļ�ֻ����׷��ģʽ�²���Ч

	rewind(fp);
	for (int i = 0; i < 10; ++i)
	{
		int ins2;
		fread(&ins2, sizeof(ins2), 1, fp);//ע�⣬fread�����������ļ�ֻ��ģʽ�²���Ч
		printf("%d\n", ins2);
	}
		

	fclose(fp);
}

//��.�ļ���λ����
//1. int fgetpos(FILE *stream,fpos_t *pos);
//2. int fseek(FILE *stream,long int offset,int whence);//fseekΪstreamָ������������ļ���λ��
//3. int fsetpos(FILE *stream,const fpos_t *pos);//fsetpos����posָ���ֵ������streamָ��������ļ���λ��
//4. long int ftell(FILE *stream);
//5. void rewind(FILE *stream);//rewindΪstreamָ������������ļ���λ��
void test6()
{
	FILE *fp = fopen("test60.txt", "r");

	fseek(fp, -22, SEEK_END);//

	fpos_t ps;
	int ps2 = fgetpos(fp, &ps);
	printf("pos_t:%lld,int:%d\n", ps, ps2);

	fclose(fp);
}

//��.��������
// clearerr feof ferror perror