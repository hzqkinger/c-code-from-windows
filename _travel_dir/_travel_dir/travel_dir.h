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

//�ýṹ����io.hͷ�ļ���
//struct _finddata_t
//{
//	unsigned attrib;
//		//attrib��ȡֵ��Ҫ������һЩ��
//			//_A_ARCH���浵���� _A_HIDDEN�����أ���_A_NORMAL����������_A_RDONLY��ֻ������_A_SUBDIR���ļ��У���_A_SYSTEM��ϵͳ����
//	time_t time_create;
//	time_t time_access;
//	time_t time_write;
//	_fsize_t size;//���������ļ��Ĵ�С
//	char name[_MAX_FNAME];//���������ļ���
//};

#define Max 1024
char srcbuf[Max] = { "F:\\����\\c\\_�ݸ�1.3" };
//F:\����\c\_�ݸ�1.3
char dstbuf[Max] = { "F:\\����\\c-code-from-windows" };
char buf[Max * Max] = { 0 };


void Copy(const char *dst,const char *src)//����ֻ�ǿ����ļ�
{
	FILE *f1 = fopen(src, "rb");
	FILE *f2 = fopen(dst, "wb");
	fseek(f1, 0L, SEEK_END);
	int lens = ftell(f1);//ȡ��ԭ�ļ���С
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
	strcpy(srctmp, dir);//һ�������϶���һ���ļ���
	_chdir(dir);//�ı䵱ǰ����Ŀ¼
	_getcwd(buf, 1024);/////////////////////////////////////////////////////////////
	printf("%s\n", buf);/////////////////////////////////////////////////////////////
	strcat(srctmp, "\\");
	strcat(srctmp, "*.*");// F:\\����\\c\\*
	long handle = _findfirst(dir, &fileinfo);//��һ�β���
	if (-1 == handle)return;
	//printf("%s\n", fileinfo.name);//��ӡ����һ���ļ���

	do{
		if (fileinfo.attrib == _A_SUBDIR){//��������ļ��еĻ�
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0){
				//ɸ��������Ĭ�ϵ��ļ��У�һ��Ϊ��ǰĿ¼��һ��Ϊ��һ��Ŀ¼
				continue;
			}

			strcat(dir, "\\");
			strcat(dir, fileinfo.name);//F:\\����\\c\\xx
			travel_dir(dir);//�����ӵݹ����
		}else{//���������ͨ���ļ�
			//F:\\����\\c\\xx\\yy\\zz   --->   F:\\����\\c-code-from-windows yy\\zz
			int pos = strlen(dir);
			while (dir[pos] != '\\')--pos;
			while (dir[pos] != '\\')--pos; pos += 1;
			std::string a(dir + pos);//string("yy\\zz")
			if (a.rfind(".c") || a.rfind(".cpp") || a.rfind(".h") || a.rfind(".hpp")){
				char dsttmp[Max];
				strcpy(dsttmp, dstbuf);//F:\\����\\c-code-from-windows
				strcpy(dsttmp, "\\");
				strcpy(dsttmp, srctmp + pos); //F:\\����\\c - code - from - windows \\yy\\zz

				Copy(dsttmp, srctmp);//��srctmp�ļ��е����ݿ�����dsttmp��ȥ
			}
		}
	} while (!_findnext(handle, &fileinfo));//��ѯ�ɹ�����0��ʧ�ܷ���-1

	_findclose(handle);//�����˹رվ�
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
	//_chdir("F:\\����\\c\\���ݽṹ��STL_________\\my_list\\my_list");
	//_getcwd(buf, 1024);
	//printf("%s\n", buf);

	long handle;
	struct _finddata_t fileinfo;
	handle = _findfirst("./*", &fileinfo);//��һ�β���
	if (-1 == handle)return;
	printf("%s\n", fileinfo.name);//��ӡ����һ���ļ���

	//FILE *fp = fopen(fileinfo.name, "rb");//��һ���ļ�
	//int size = fread(buf, 1, 1023, fp);//���ļ�����
	//fwrite(buf, 1, size, stdout);//������������д����׼�����


	//while (!_findnext(handle, &fileinfo))
	//{
	//	printf("%s\n", fileinfo.name);

	//	FILE *fp = fopen("fileinfo.name", "r");
	//	int size = fread(buf, 1, 1023, fp);
	//	buf[size] = 0;
	//	printf("%s\n", buf);
	//	//fwrite(buf, 1, size, stdout);
	//}
	_findclose(handle);//�����˹رվ�
}