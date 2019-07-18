#include <windows.h>
#include<direct.h>
#include <stdio.h>

//typedef struct _WIN32_FIND_DATAA {
//	DWORD dwFileAttributes;//文件属性
//	FILETIME ftCreationTime;//创建时间
//	FILETIME ftLastAccessTime;//最近访问时间
//	FILETIME ftLastWriteTime;//最近修改时间
//	DWORD nFileSizeHigh;//高位大小
//	DWORD nFileSizeLow;//低位大小
//	DWORD dwReserved0;
//	DWORD dwReserved1;
//	_Field_z_ CHAR   cFileName[MAX_PATH];//文件名，非全路径
//	_Field_z_ CHAR   cAlternateFileName[14];
//} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

#define BUF_SIZE 256
void copyfile(const char *srcfile, const char *dstfile, char *dst_folder)
{
	//LPTSTR类型 与char*等价，表示普通字符/字符串变量，指向字符/字符串的指针。

	HANDLE handleIn, handleOut;//句柄（HANDLE)是资源的标识,操作系统要管理和操作这些资源，都是通过句柄来找到对应的资源
	//HANDLE 是一个32位的无符号整数,是一个对象的句柄,可以认为存放的是一个对象的地址
	//  printf("%d", handleIn);
	DWORD readsizeIn, readsizeOut;
	//#define DWORD unsigned long 所以比较方便移植用的 ，Windows下经常用来保存地址(或者存放指针) 

	CHAR Buffer[BUF_SIZE]; //大写的CHAR也表示 CHAR为单字节字符 Windows为了消除各编译器的差别，重新定义了一些数据类型


	//（1）判断文件1是否能打开， 创建一个句柄来标识输入文件
	//CreateFile 这是一个多功能的函数，可打开或创建以下对象，并返回可访问的句柄：控制台，通信资源，目录（只读打开），磁盘驱动器，文件，邮槽，管道。
	handleIn = CreateFile(srcfile, GENERIC_READ,FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//      printf("%ld", handleIn);    
	//如果文件打开失败 提示用户 并且调用GetLastError()函数取得上一个函数（也就是CreateFile函数）操作时所产生的错误代码
	if (handleIn == INVALID_HANDLE_VALUE) {
		printf("不能打开被复制文件（文件1）. 错误代码: %x\n",GetLastError());
		return ;
	}

	//dstfile = "F:\\代码\\c-code-from-windows\\_草稿1.3\\草稿1.3\\draft1.h";

	//同上 这次是判断是否能打开文件2， 解释如上
	handleOut = CreateFile(dstfile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//CREATE_DIRECTORY | FILE_ATTRIBUTE_DIRECTORY
	while(handleOut == INVALID_HANDLE_VALUE) {
		char tmp[260];
		strcpy(tmp, dstfile);
		//const char *dst_folder = "F:\\代码\\c-code-from-windows\\";////////////////////////////
		_chdir(dst_folder);//跳转到对应的目录
		int size = strlen(tmp);
		while (tmp[size] != '\\')--size;
		for (int index = strlen(dst_folder); index < size;)
		{
			int right = index;
			while (tmp[right] != '\\')++right; tmp[right] = '\0';
			_mkdir(tmp + index);//这里即使返回-1，程序也是正确的
			_chdir(tmp + index);
			index = right + 1;
		}

		handleOut = CreateFile(dstfile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
			CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		//printf("不能打开目标文件（文件2）. 错误代码: %x\n",GetLastError());
		//return ;
	}
	//下面进行文件复制的操作 调用ReadFile和WriteFile函数 每次读入字节数为BUF_SIZE
	//readsizeIn指向实际读取字节数的指针  而且ReadFile调用成功,返回非0，readsizeIn也要是大于0才表示可以继续读  

	while (ReadFile(handleIn, Buffer, BUF_SIZE, &readsizeIn, NULL) && readsizeIn > 0) {
		WriteFile(handleOut, Buffer, readsizeIn, &readsizeOut, NULL);
		if (readsizeIn != readsizeOut) {
			printf("文件复制时出现错误。 错误代码: %x\n", GetLastError());
			return ;
		}
	}
	//提示复制成功！
	printf("文件复制时成功\n");
	//关闭句柄 
	CloseHandle(handleIn);
	CloseHandle(handleOut);
}

void enum_path(char *cpath,char *dstbuff){
	WIN32_FIND_DATA wfd;//文件的各种信息
	HANDLE hfd;//句柄(HANDLE)是资源的标识，操作系统要管理和操作这些资源，都是通过句柄来找到对应的资源
	//HANDLE是一个32位的无符号整数，是一个对象的句柄，可以认为存放的是一个队形的地址
	char cdir[MAX_PATH];
	char subdir[MAX_PATH];
	int r;
	GetCurrentDirectory(MAX_PATH, cdir);
	SetCurrentDirectory(cpath);
	hfd = FindFirstFile("*.*", &wfd);
	if (hfd != INVALID_HANDLE_VALUE) {
		do{
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (wfd.cFileName[0] != '.') {
					// 合成完整路径名 
					sprintf(subdir, "%s\\%s", cpath, wfd.cFileName);
					// 递归枚举子目录 
					enum_path(subdir,dstbuff);
				}
			}
			else{
				//printf("%s\\%s\n", cpath, wfd.cFileName);打印遍历到的每个文件

				std::string aaa(wfd.cFileName);
				int cFileNameIndex = aaa.rfind('.');
				if (!strcmp(wfd.cFileName + cFileNameIndex, ".h") || !strcmp(wfd.cFileName + cFileNameIndex, ".c")
					|| !strcmp(wfd.cFileName + cFileNameIndex, ".hpp") || !strcmp(wfd.cFileName + cFileNameIndex, ".cpp")){
					const char *buff = "F:\\代码\\c\\";
					//const char *dstbuff = "F:\\代码\\c-code-from-windows\\";
					int pos = strlen(buff);
					char dstbuf[260] = { 0 };
					strcpy(dstbuf, dstbuff);
					strcat(dstbuf, cpath + pos);
					strcat(dstbuf, "\\");
					strcat(dstbuf, wfd.cFileName);//把目标路径拼接好

					char srcbuf[260] = { 0 };
					strcpy(srcbuf, cpath);
					strcat(srcbuf, "\\");
					strcat(srcbuf, wfd.cFileName);//把源路径拼接好

					copyfile(srcbuf, dstbuf, dstbuff);//进行文件的复制
					//Copy(srcbuf, dstbuf);
				}
				//printf("%s\n", wfd.cFileName);
				// 病毒可根据后缀名判断是否要感染相应的文件 
			}
		} while (r = FindNextFile(hfd, &wfd), r != 0);
	}
	SetCurrentDirectory(cdir);
}
void test()
{
	//enum_path  源文件夹 目标文件夹
	enum_path("F:\\代码\\c", "F:\\代码\\c-code-from-windows\\");
}
