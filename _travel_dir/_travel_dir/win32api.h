#include <windows.h>
#include<direct.h>
#include <stdio.h>

//typedef struct _WIN32_FIND_DATAA {
//	DWORD dwFileAttributes;//�ļ�����
//	FILETIME ftCreationTime;//����ʱ��
//	FILETIME ftLastAccessTime;//�������ʱ��
//	FILETIME ftLastWriteTime;//����޸�ʱ��
//	DWORD nFileSizeHigh;//��λ��С
//	DWORD nFileSizeLow;//��λ��С
//	DWORD dwReserved0;
//	DWORD dwReserved1;
//	_Field_z_ CHAR   cFileName[MAX_PATH];//�ļ�������ȫ·��
//	_Field_z_ CHAR   cAlternateFileName[14];
//} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

#define BUF_SIZE 256
void copyfile(const char *srcfile, const char *dstfile, char *dst_folder)
{
	//LPTSTR���� ��char*�ȼۣ���ʾ��ͨ�ַ�/�ַ���������ָ���ַ�/�ַ�����ָ�롣

	HANDLE handleIn, handleOut;//�����HANDLE)����Դ�ı�ʶ,����ϵͳҪ����Ͳ�����Щ��Դ������ͨ��������ҵ���Ӧ����Դ
	//HANDLE ��һ��32λ���޷�������,��һ������ľ��,������Ϊ��ŵ���һ������ĵ�ַ
	//  printf("%d", handleIn);
	DWORD readsizeIn, readsizeOut;
	//#define DWORD unsigned long ���ԱȽϷ�����ֲ�õ� ��Windows�¾������������ַ(���ߴ��ָ��) 

	CHAR Buffer[BUF_SIZE]; //��д��CHARҲ��ʾ CHARΪ���ֽ��ַ� WindowsΪ���������������Ĳ�����¶�����һЩ��������


	//��1���ж��ļ�1�Ƿ��ܴ򿪣� ����һ���������ʶ�����ļ�
	//CreateFile ����һ���๦�ܵĺ������ɴ򿪻򴴽����¶��󣬲����ؿɷ��ʵľ��������̨��ͨ����Դ��Ŀ¼��ֻ���򿪣����������������ļ����ʲۣ��ܵ���
	handleIn = CreateFile(srcfile, GENERIC_READ,FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//      printf("%ld", handleIn);    
	//����ļ���ʧ�� ��ʾ�û� ���ҵ���GetLastError()����ȡ����һ��������Ҳ����CreateFile����������ʱ�������Ĵ������
	if (handleIn == INVALID_HANDLE_VALUE) {
		printf("���ܴ򿪱������ļ����ļ�1��. �������: %x\n",GetLastError());
		return ;
	}

	//dstfile = "F:\\����\\c-code-from-windows\\_�ݸ�1.3\\�ݸ�1.3\\draft1.h";

	//ͬ�� ������ж��Ƿ��ܴ��ļ�2�� ��������
	handleOut = CreateFile(dstfile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//CREATE_DIRECTORY | FILE_ATTRIBUTE_DIRECTORY
	while(handleOut == INVALID_HANDLE_VALUE) {
		char tmp[260];
		strcpy(tmp, dstfile);
		//const char *dst_folder = "F:\\����\\c-code-from-windows\\";////////////////////////////
		_chdir(dst_folder);//��ת����Ӧ��Ŀ¼
		int size = strlen(tmp);
		while (tmp[size] != '\\')--size;
		for (int index = strlen(dst_folder); index < size;)
		{
			int right = index;
			while (tmp[right] != '\\')++right; tmp[right] = '\0';
			_mkdir(tmp + index);//���Ｔʹ����-1������Ҳ����ȷ��
			_chdir(tmp + index);
			index = right + 1;
		}

		handleOut = CreateFile(dstfile, GENERIC_WRITE, FILE_SHARE_WRITE, NULL,
			CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		//printf("���ܴ�Ŀ���ļ����ļ�2��. �������: %x\n",GetLastError());
		//return ;
	}
	//��������ļ����ƵĲ��� ����ReadFile��WriteFile���� ÿ�ζ����ֽ���ΪBUF_SIZE
	//readsizeInָ��ʵ�ʶ�ȡ�ֽ�����ָ��  ����ReadFile���óɹ�,���ط�0��readsizeInҲҪ�Ǵ���0�ű�ʾ���Լ�����  

	while (ReadFile(handleIn, Buffer, BUF_SIZE, &readsizeIn, NULL) && readsizeIn > 0) {
		WriteFile(handleOut, Buffer, readsizeIn, &readsizeOut, NULL);
		if (readsizeIn != readsizeOut) {
			printf("�ļ�����ʱ���ִ��� �������: %x\n", GetLastError());
			return ;
		}
	}
	//��ʾ���Ƴɹ���
	printf("�ļ�����ʱ�ɹ�\n");
	//�رվ�� 
	CloseHandle(handleIn);
	CloseHandle(handleOut);
}

void enum_path(char *cpath,char *dstbuff){
	WIN32_FIND_DATA wfd;//�ļ��ĸ�����Ϣ
	HANDLE hfd;//���(HANDLE)����Դ�ı�ʶ������ϵͳҪ����Ͳ�����Щ��Դ������ͨ��������ҵ���Ӧ����Դ
	//HANDLE��һ��32λ���޷�����������һ������ľ����������Ϊ��ŵ���һ�����εĵ�ַ
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
					// �ϳ�����·���� 
					sprintf(subdir, "%s\\%s", cpath, wfd.cFileName);
					// �ݹ�ö����Ŀ¼ 
					enum_path(subdir,dstbuff);
				}
			}
			else{
				//printf("%s\\%s\n", cpath, wfd.cFileName);��ӡ��������ÿ���ļ�

				std::string aaa(wfd.cFileName);
				int cFileNameIndex = aaa.rfind('.');
				if (!strcmp(wfd.cFileName + cFileNameIndex, ".h") || !strcmp(wfd.cFileName + cFileNameIndex, ".c")
					|| !strcmp(wfd.cFileName + cFileNameIndex, ".hpp") || !strcmp(wfd.cFileName + cFileNameIndex, ".cpp")){
					const char *buff = "F:\\����\\c\\";
					//const char *dstbuff = "F:\\����\\c-code-from-windows\\";
					int pos = strlen(buff);
					char dstbuf[260] = { 0 };
					strcpy(dstbuf, dstbuff);
					strcat(dstbuf, cpath + pos);
					strcat(dstbuf, "\\");
					strcat(dstbuf, wfd.cFileName);//��Ŀ��·��ƴ�Ӻ�

					char srcbuf[260] = { 0 };
					strcpy(srcbuf, cpath);
					strcat(srcbuf, "\\");
					strcat(srcbuf, wfd.cFileName);//��Դ·��ƴ�Ӻ�

					copyfile(srcbuf, dstbuf, dstbuff);//�����ļ��ĸ���
					//Copy(srcbuf, dstbuf);
				}
				//printf("%s\n", wfd.cFileName);
				// �����ɸ��ݺ�׺���ж��Ƿ�Ҫ��Ⱦ��Ӧ���ļ� 
			}
		} while (r = FindNextFile(hfd, &wfd), r != 0);
	}
	SetCurrentDirectory(cdir);
}
void test()
{
	//enum_path  Դ�ļ��� Ŀ���ļ���
	enum_path("F:\\����\\c", "F:\\����\\c-code-from-windows\\");
}
