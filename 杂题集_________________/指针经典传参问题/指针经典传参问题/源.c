#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<CoreWindow.h>
#define BUFFER_SIZE 256

//void GetMemeory(char**ppszbuf)
//{
//	if (NULL == ppszbuf)
//	{
//		asser(0);
//		return;
//	}
//	ppszbuf = (char*)malloc(BUFFER_SIZE);//*ppszbuf
//	return;
//}
//void Test()
//{
//	char *pszbuf = NULL;
//	GetMemory(&pszbuf);
//	strcpy(pszbuf, "hello world\n");
//	printf("%s", pszbuf);
//	free(pszbuf);
//	return;
//}

//void Getmemory(char*p)//char **p
//{
//	p = (char*)malloc(57);//*p
//}
//int main()     //����㣺�ٳ��������ڴ�й©
//{
//	char*str = NULL;
//	Getmemry(str);
//	strcpy(str, "bit c++");
//	printf(str);
//	//free(str);//����û����䣬������ڴ�й©
//	//str = NULL;//����û����䣬str����Ұָ�룬������ɷǷ������ڴ�
//  return 0;
//}

//char *Getmemory(void) //����ջ֡����
//{
//	char p[] = "bit c++";
//	return p;
//}
//int main()
//{
//	char *str = NULL;
//	str = Getmemory();
//	printf(str);
//	return 0;
//}



//char* test(char* ptr)
//{
//	ptr = (char*)malloc(10);
//	return ptr;
//}
//int main()
//{
//	char* ptr = NULL;
//	ptr = test(ptr);
//	char* pa = "nihao";
//	strcpy(ptr, pa);
//	printf("%s\n", ptr);
//	system("pause");
//	return 0;
//}

void f1(char*** p0)
{
	*p0 += 2;
}
void f2(char** p0)
{
	*p0 += 2;
}
int main()//����ָ�봫�Σ��о����е��Ժ���
{
	char* a[] = { "123", "abc", "456" }, **p1,**p2;
	p1 = a,p2 = a;
	printf("%s   %s\n", *p1, *p2);
	f1(&p1);
	//p1 += 2;
	printf("%s\n", *p1);
	f2(p2);
	printf("%s\n", *p2);
	system("pause");
	return 0;
}