#pragma once

#include<direct.h>
#include<io.h>
#include<string>

//int _mkdir(const char *_Path)			mkdir
//int _rmdir(const char *path)			rmdir
//char *_getcwd(char *buf, int buflen)	pwd
//int _chdir(const char *path)			cd

//long _findfirst(char *filespec, struct _finddata_t *fileinfo)
//int _findnext(long handle, struct _finddata_t *fileinfo)
//int _findclose(long handle)

//该结构体在io.h头文件中
//struct _finddata_t
//{
//	unsigned attrib;
//		//attrib的取值主要有以下一些：
//			//_A_ARCH（存档）、 _A_HIDDEN（隐藏）、_A_NORMAL（正常）、_A_RDONLY（只读）、_A_SUBDIR（文件夹）、_A_SYSTEM（系统）。
//	time_t time_create;
//	time_t time_access;
//	time_t time_write;
//	_fsize_t size;//这里存的是文件的大小
//	char name[_MAX_FNAME];//这里存的是文件名
//};

#define Max 1024
char srcbuf[Max] = { "F:\\代码\\c\\_草稿1.3" };
//F:\代码\c\_草稿1.3
char dstbuf[Max] = { "F:\\代码\\c-code-from-windows" };
char buf[Max * Max] = { 0 };


void Copy(const char *dst,const char *src)//仅仅只是拷贝文件
{
	FILE *f1 = fopen(src, "rb");
	FILE *f2 = fopen(dst, "wb");
	fseek(f1, 0L, SEEK_END);
	int lens = ftell(f1);//取出原文件大小
	rewind(f1);
	fread(buf, lens, 1, f1);
	fwrite(buf, lens, 1, f2);
	fclose(f1); fclose(f2);
}
void travel_dir(char *dir)
{
	struct _finddata_t fileinfo;
	char srctmp[Max];
	_getcwd(buf, 1024);/////////////////////////////////////////////////////////////
	printf("%s\n", buf);/////////////////////////////////////////////////////////////
	strcpy(srctmp, dir);//一进来，肯定是一个文件夹
	_chdir(dir);//改变当前工作目录
	_getcwd(buf, 1024);/////////////////////////////////////////////////////////////
	printf("%s\n", buf);/////////////////////////////////////////////////////////////
	strcat(srctmp, "\\");
	strcat(srctmp, "*.*");// F:\\代码\\c\\*
	long handle = _findfirst(dir, &fileinfo);//第一次查找
	if (-1 == handle)return;
	//printf("%s\n", fileinfo.name);//打印出第一个文件名

	do{
		if (fileinfo.attrib == _A_SUBDIR){//①如果是文件夹的话
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0){
				//筛掉这两个默认的文件夹，一个为当前目录，一个为上一级目录
				continue;
			}

			strcat(dir, "\\");
			strcat(dir, fileinfo.name);//F:\\代码\\c\\xx
			travel_dir(dir);//进行子递归调用
		}else{//②如果是普通的文件
			//F:\\代码\\c\\xx\\yy\\zz   --->   F:\\代码\\c-code-from-windows yy\\zz
			int pos = strlen(dir);
			while (dir[pos] != '\\')--pos;
			while (dir[pos] != '\\')--pos; pos += 1;
			std::string a(dir + pos);//string("yy\\zz")
			if (a.rfind(".c") || a.rfind(".cpp") || a.rfind(".h") || a.rfind(".hpp")){
				char dsttmp[Max];
				strcpy(dsttmp, dstbuf);//F:\\代码\\c-code-from-windows
				strcpy(dsttmp, "\\");
				strcpy(dsttmp, srctmp + pos); //F:\\代码\\c - code - from - windows \\yy\\zz

				Copy(dsttmp, srctmp);//将srctmp文件中的内容拷贝到dsttmp中去
			}
		}
	} while (!_findnext(handle, &fileinfo));//查询成功返回0，失败返回-1

	_findclose(handle);//别忘了关闭句
}
void test()
{
	//fopen("aa.txt", "wb");
	travel_dir(srcbuf);
}

void test1()
{
	//int ret = _mkdir("create_dir");
	//printf("%d\n", ret);
	//
	//char buf[1024] = { 0 };
	//_getcwd(buf, 1024);
	//printf("%s\n", buf);
	//
	//_chdir("Debug");
	//_getcwd(buf, 1024);
	//printf("%s\n", buf);
	//
	//_chdir("F:\\代码\\c\\数据结构和STL_________\\my_list\\my_list");
	//_getcwd(buf, 1024);
	//printf("%s\n", buf);

	long handle;
	struct _finddata_t fileinfo;
	handle = _findfirst("./*", &fileinfo);//第一次查找
	if (-1 == handle)return;
	printf("%s\n", fileinfo.name);//打印出第一个文件名

	//FILE *fp = fopen(fileinfo.name, "rb");//打开一个文件
	//int size = fread(buf, 1, 1023, fp);//读文件内容
	//fwrite(buf, 1, size, stdout);//将读到的内容写到标准输出中


	//while (!_findnext(handle, &fileinfo))
	//{
	//	printf("%s\n", fileinfo.name);

	//	FILE *fp = fopen("fileinfo.name", "r");
	//	int size = fread(buf, 1, 1023, fp);
	//	buf[size] = 0;
	//	printf("%s\n", buf);
	//	//fwrite(buf, 1, size, stdout);
	//}
	_findclose(handle);//别忘了关闭句
}