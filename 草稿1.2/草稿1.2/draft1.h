#pragma once

void Print(char *s)//�ݹ�
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
	union uu{            //����������
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
//	//intf((int[]){5});//����������  (��.c�ļ��У���������ǿת)
//	intf(reinterpret_cast<int*>(5));
//}

void tEst4()
{
	int num;
	while (scanf("%d", &num) == 1)
	{
		puts("�����������밴��������֮��������");
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
	printf("%d\n", sizeof(Color));//4��ö������ռ�ֽ���

	//typedef char str;
	//str s;
	//s = 'w';

	typedef int STRING[3];         //typedef���������������ַ�����
	STRING s[3];//���ܵȼ��� char s[3]
	s[1][2] = 1;
	s[2][2] = 0;

	//s[0] = 'W';
	//s[1] = 'A';
	//s[2] = 0;
	printf("%s\n", s);

	const pstu stu3;//����const����stu3����Ϊpstu��һ�����塣

	system("pause");
	return 0;
}
#endif

void tEst6()
{

  int a = 4294967295;
  int b = 4294967294;
  printf("%d %d\n", a, b);
  a = a ^ b;                     //���ֽ�����������ȷ����ʹ�����
  b = a ^ b;
  a = a ^ b;
  //a = a + b;
  //b = a - b;
  //a = a - b;
  printf("%d %d\n", a,b);

	//char arr[128];
	//int i;
	//for (i = 0; i < 128; i++)//0   '0'    '\0' ����֮�������
	//	arr[i] = i;
	//printf("%s\n",arr+1);

	//char i = 0;
	//printf("%d\n", i);//0   '0'    '\0' ����֮�������
}

void tEst7()
{
	//int a =/*/*/2 */**/1;
	//char *p = "";/*/**/"*/"/*"               //�ñ�����������ע��Ƕ��
	//printf("%s\n", p);

	//int a = 1, b = 2;
	//printf("%d\n", (++a)++ + b);//(++a)++ + b������C++�±����ȥ��C���У�a+++++b��C/C++�����벻��
	//��Ϊ++a������ֵ��a++������ֵ

	//int a = 011;//���һ�����ͳ����ĵ�һ���ַ�������0����ô�ó�������Ϊ�˽�����
	//printf("%d\n", a);   //�����������һ���ַ�����һ��������˫���������һ���ַ�����һ��ָ�롣

	int b = printf("\141");  //���ASCII�룬\141�ǰ˽�������\d��\dd��\ddd����ʾ�˽�������
	int c = 3;
	int a = printf("%d%d\n",b,c);  //printf�ĸ����ã������ַ����ĳ��ȡ�
	//a++;
	printf("%d\n", a);
	int d = printf("abcde");
	cout << d;

	char *s = "123456789";
	int e = printf(s);//��ӡ���ַ��������Ҽ��������ĳ���
	cout << e;
}

void tEst8()
{
	volatile const int a = 10;    //��.c�ļ���a���ı������ʾ��������.cpp�ļ���a���ı䵫����ʾ����
	printf("%d\n", a);   //Ϊa���õ��Ĵ��������ˣ�����ͨ���ؼ���volatile��ʾ��������֤�ڴ�ɼ���
	//��������۵�����
}

//void tEst9()  //д���������Ժ���д��
//{
//	int cnt = 0,i = 0,j = 0;
//	char arr[10][10] = { 0 };
//	char*tmp = NULL;
//	char(*p)[10] = arr;
//	printf("��������Ҫ���뼸������\n");
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

////���ļ��Ĳ���
//int remove(const char*p);
//int rename(const char*p, const char*p2);
//FILE*tmpfile(void);
//char*tmpname(char*p);
////�ļ����ʺ���
//int fclose(FILE*fp);
//int fflush(FILE*fp);
//FILE*fopen(const char* p1, const char *p2);
//FILE*fropen(const char* p1, const char *p2, FILE*fp);
//void setbuf(FILE*fp, char*p);
//void setvbuf(FILE*fp, char*p, int i, size_t size);
////��ʽ�������������
//int sscanf(const char*p, const char*format, ...);
//int fscanf(FILE*fp, const char*p, ...);
//int scanf(const char*format, ...);
//int fprint(FILE*fp, const char*format, ...);
//int printf(const char*format, ...);
//int sprintf(char*p, const char*format, ...);
//int vfprintf(FILE*fp, const char*p1, char*p2);
//int vprintf(const char*p1, char*p2);
//int vsprintf(char*p1, const char*p2, char*p3);
////�ַ������������
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
////ֱ�������������
//size_t fread(void*p, size_t size1, size_t size2, FILE*fp);
//size_t fwrite(const void*p, size_t size1, size_t size2, FILE*fp);
////�ļ���λ����
//int fgetpos(FILE*fp, fpos_t*pos);
//int fseek(FILE*fp, long l, int i);
//int fsetpos(FILE*fp, const fpos_t*p);
//long ftell(FILE*fp);
//void rewind(FILE*fp);
////��������
//void clearerr(FILE*fp);
//int feof(FILE*fp);
//int ferror(FILE*fp);
//void perror(const char*p);
////����
//long _Fgpos(FILE*fp, fpos_t*pos);
//int _Fspos(FILE*fp, const fpos_t*pos, long l, int i);
//extern FILE*_Files[FOPEN_MAX];


void test_draft1()
{
	//tEst1();//Genius �ĵݹ�
	//tEst2();//�ṹ��ռ�ֽ���
	//tEst3();//ǿ������ת��                           .cpp�ļ��³���
	//tEst4();//scanf()���벻ȷ����������������
	//tEst6();//�����������ݵĽ�������
	tEst7();//ע��Ƕ�ף�printf()�����ĸ�����
	//tEst8();//const��volatile
	//tEst9();//                                    ����
}