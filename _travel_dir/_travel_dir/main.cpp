#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<CoreWindow.h>
//#include"travel_dirent.h"
//#include"travel_dir.h"
#include"win32api.h"

#define Max 1024
void test2()
{
	// "F:\\����\\c-code-from-windows\\_�ݸ�1.3\\�ݸ�1.3\\draft1.h";
	char buf[Max];
	_getcwd(buf, 1024);/////////////////////////////////////////////////////////////
	printf("%s\n", buf);/////////////////////////////////////////////////////////////
	_chdir("F:\\����\\c-code-from-windows");//�ı䵱ǰ����Ŀ¼
	_getcwd(buf, 1024);/////////////////////////////////////////////////////////////
	printf("%s\n", buf);/////////////////////////////////////////////////////////////
	_mkdir("_�ݸ�1.3");
	_chdir("_�ݸ�1.3");
	_getcwd(buf, 1024);/////////////////////////////////////////////////////////////
	printf("%s\n", buf);/////////////////////////////////////////////////////////////
	_mkdir("draft1.h");
	_chdir("draft1.h");
	_getcwd(buf, 1024);/////////////////////////////////////////////////////////////
	printf("%s\n", buf);/////////////////////////////////////////////////////////////
}

void test3()
{
	//create_dir
	char buf[260];
	const int size = sizeof(buf) / sizeof(buf[0]);
	_getcwd(buf,size);//////////////////////////
	printf("%s\n", buf);//////////////////////////
	int ret = _mkdir("create_dir");
	_chdir("create_dir");
	printf("%d\n", ret);
	_getcwd(buf, size);//////////////////////////
	printf("%s\n", buf);//////////////////////////

	_mkdir("create_dir");
}
void test4()
{
	char buf[260] = "F:\\����\\c//bitÿ��һ��//bitÿ��һ��\\Դ.cpp";
	//"F:\\����\\c-code-from-windows\\/bitÿ��һ��//bitÿ��һ��\\Դ.cpp"
	for (int left = 0, right = 0, size = strlen(buf); right <= size;){
		if (buf[right] != '/')
			buf[left++] = buf[right++];
		else{
			buf[left++] = '\\';
			right += 2;
		}
	}
	printf("%s\n", buf);

	char buf2[10];
	sprintf(buf, "%s\\%s", "aa", "bb");
	printf("%s\n", buf);

	//char buf[260] = "F:\\����\\c-code-from-windows\\draft1.h";
	printf("%d\n", strlen("\\"));
	printf("%d\n", strlen("//"));
}
int main()
{
	//const char *buf = "F:\\����\\c-code-from-windows\\draft1.h";
	//FILE *fp = fopen(buf, "wb");
	//if (fp)printf("�����ɹ�\n");
	//char arr[1024] = { 0 };
	//int size = fread(arr, 1, 1023, fp);//���ļ�����
	//fwrite(arr, 1, size, stdout);//������������д����׼�����

	test();
	//test2();
	//test3();
	//test4();
	system("pause");
	return 0;
}