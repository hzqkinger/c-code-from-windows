#pragma once

//#include<yvals.h>

void test2()
{
	//һ.���ļ��Ĳ���
	//�� int remove(const char *filename);
	//�� int rename(const char *old,const char *new)
	//�� FILE *tmpfile(void)
	//�� char *tmpnam(char *s)

	//��.�ļ����ʺ���
	////�� int fclose(FILE *stream)
	////�� FILE *fopen(const char *filename,const char *mode)
	//FILE *file1 = fopen("test2.txt", "r"); //r w a rb wb ab  r+ w+ a+ rb+ wb+ ab+
	////�� fclose(file1);
	////�� int fflush(FILE *stream)
	//printf("%ld\n", ftell(file1));
	//char _ch = fgetc(file1); printf("%c\n", _ch);
	//printf("%ld\n", ftell(file1));
	//fflush(file1);//�����Ͻ��ļ�ָ��ָ���ļ�ĩβ
	//_ch = fgetc(file1); printf("%c\n", _ch);
	//printf("%ld\n", ftell(file1));
	//printf("%d\n", sizeof(FILE));//FILE���͵Ĵ�С
	////�� FILE *freopen(const char *filename,const char *mode,FILE *stream)
	//FILE *file3 = freopen("test3.txt", "r", file1);//���ļ��ض�λ����.���óɹ�����file1,���򷵻�NULL
	//_ch = fgetc(file1); printf("%c\n", _ch);//�����������ر�file1ԭ��ָ����ļ���Ȼ����file1����ָ��һ���ļ�"test3.txt"
	//_ch = fgetc(file3); printf("%c\n", _ch);//������file1��file3ָ�붼ָ���ļ�"test3.txt"
	//fclose(file1);
	//fclose(file3);//���ü�����ԭ��(����ָ��ͬʱָ��ͬһ���ļ�)


	//�� �� void stebuf(FILE *stream,char *buf)
	//   �� int setvbuf(FILE *stream,char *buf,int mode,size_t size)//

	//��.��ʽ���������������
	//char arr[15]; int i = 0;
	////�� int fprintf(FILE *stream,const char *format,...)//�ӳ�����д���ݵ��ļ���
	////�� int fscanf(FILE *stream,const char *format,...)//���ļ���ɨ�����ݵ�������
	//file1 = fopen("test2.txt", "r");
	//file3 = fopen("test3.txt", "a");
	//printf("         %d      \n", ftell(file1));
	//printf("         %d      \n", ftell(file3));
	//fscanf(file1, "%1d", &i); //c�����������ո�TAB���س���Ƿ�����ʱ����Ϊ�������������
	//printf("         %d      \n",ftell(file1));
	//fprintf(file3,"%d",i);
	//printf("         %d      \n", ftell(file3));
	//fclose(file1);
	//fclose(file3);

	////�� int printf(const char *format,...)//�ӳ�����д���ݵ���Ļ��
	////�� int scanf(const char *format,...)//�Ӽ���ɨ�����ݵ�������
	//scanf("%s%*d%d", arr,&i);//����������ʱ��c�����������ո�TAB���س���Ƿ�����ʱ����Ϊ�������������
	//printf("%s %d",arr,i);

	////�� int sprintf(char *s,const *format,...)//�ӳ�����д���ݵ�������
	////�� int sscanf(char *s,const *format,...)//��������ɨ�����ݵ�������
	//char arr2[] = "55 abcdef 66 8a";
	//char arr3[10], arr4[10]; int i2, i3;
	//sscanf(arr2, "%d%s%s%d",&i2,arr3,arr4,&i3);
	//char arr5[20];
	//sprintf(arr5, "%d:%d->%s->%s", i2, i3, arr3, arr4);//�Զ�����arr5�������'\0'�ַ�

	//�� �� int vfprintf(FILE *stream,const char *format,va_list arg)
	//   �� int vprintf(const char *format,va_list arg)
	//   �� int vsprintf(const char *s,const char *format,va_list arg)

	//��.�ַ������������
	////�� int fgetc(FILE *stream)//��ĳ���ļ���ɨ��һ���ַ����ַ�����������
	////�� int getc(FILE *stream)
	////�� char *fgets(char *s,int n,FILE *stream)
	////�� int fputc(int c,FILE *stream)//�ӳ�����дһ���ַ����ַ������ļ���
	////�� int putc(int c,FILE *stream)
	////�� int fputs(const char *s,FILE *stream)
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

	////�� int getchar(void)//�Ӽ�����ɨ��һ���ַ����ַ�����������
	////�� char *gets(char *s)
	////�� int putchar(int c)//�ӳ�����дһ���ַ����ַ�������Ļ��
	////   int puts(const char *s)
	//char arr9[15];
	//putchar(getchar());
	//puts(gets(arr9));//getsֻ���������з���ֹͣ����

	////   int ungetc(int c,FILE *stream)//��һ���ַ����˵�һ���ļ���ȥ
	//FILE *fptr3 = fopen("test3.txt", "r");
	//char ch = fgetc(fptr3);
	//printf("   %d ", ftell(fptr3));
	//ungetc(ch, fptr3);
	//printf("   %d ", ftell(fptr3));

	//��.ֱ�������������
	////�� size_t fread(void *ptr,size_t size,size_t nmemb,FILE *stream)
	////�� size_t fwrite(void *ptr,size_t size,size_t nmemb,FILE *stream)
	//char ch[10] = ""; int i;
	//FILE *fptr2 = fopen("test2.txt", "r");
	//FILE *fptr3 = fopen("test3.txt", "a");
	//fread(ch, 1,5, fptr2);//���ļ���ɨ��5��Ԫ�ص�����ch��
	//printf("  %d  ", ftell(fptr2));
	//fread(&i, sizeof(int), 1, fptr2);
	//printf("  %d  ", ftell(fptr2));
	//fwrite(&i, sizeof(int), 1, fptr3);
	//fclose(fptr2);
	//fclose(fptr3);

	//��.�ļ���λ����
	//�� �� int fgetpos(FIle *stream,fpos_t *pos)
    //   �� int fsetpos(FILE *stream,const fpos_t *pos)

	////�� int fseek(FILE *stream,long int offset,int whence)
	////�� long int ftell(FILE *stream)
	////�� void rewind(FILE *stream)
	//FILE *fptr = fopen("test2.txt", "r"); int n = 1;
	//for (char ch = fgetc(fptr); ch != EOF; ch = fgetc(fptr)){
	//	printf("%d ", ftell(fptr));
	//	if (ftell(fptr) == 15 && n == 1){
	//		/*fseek(fptr, 0, SEEK_SET);*/rewind(fptr);
	//		--n; }
	//}

	//��.��������
	//�� void clearerr(FILE *stream)
	//�� int ferror(FILE *stream)

	//�� int feof(FILE *stream)//����streamָ��������ļ�������
	//�� void perror(const char *s)//
}