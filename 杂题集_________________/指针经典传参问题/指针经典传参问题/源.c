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
//int main()     //错误点：①程序奔溃②内存泄漏
//{
//	char*str = NULL;
//	Getmemry(str);
//	strcpy(str, "bit c++");
//	printf(str);
//	//free(str);//假如没有这句，会造成内存泄漏
//	//str = NULL;//假如没有这句，str会变成野指针，可能造成非法访问内存
//  return 0;
//}

//char *Getmemory(void) //函数栈帧问题
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
int main()//数组指针传参（感觉还有点迷糊）
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