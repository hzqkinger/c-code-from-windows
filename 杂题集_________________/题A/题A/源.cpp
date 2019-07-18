#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

//问题A： 去除注释
//题目描述
//现有一段代码，将注释的部分去除，输出剩余的代码。
//注释共有两种形式：
//1. 行注视：以//开头，一直作用到行尾为止。
//2. 段注视：以/*开头，到*/结尾，中间部分都是注释，可以跨行。
//【注意】
//保留行尾换行符
//
//输入格式
//一段程序代码
//
//输出格式
//去掉注释部分后的程序
//
//样例输入
//int main() {
//	/*
//	我是
//	一段
//	注释
//	*/
//	int n;//n表示数据规模
//}
//
//样例输出
//int main() {
//
//	int n;
//}



#define N 100
int main()
{
	char *str = (char*)malloc(N);
	FILE *fp = fopen("data3.txt", "rw");
	fgets(str,N,fp);
	for (size_t i = 0; i< N; ++i)
	{
		if (i < N && str[i] == '/'&&str[i + 1] == '*')
		{
			i += 2;
			while (i < N && str[i] != '*'&&str[i + 1] != '/')++i;
			i += 2;
		}
		else if (i < N && str[i] == '/'&&str[i + 1] == '/')
		{
			while (i < N && str[i] != '\n')++i;
			i += 1;
		}
		else
		{
			printf("%c", str[i]);
		}
	}
	free(str);
	system("pause");
	return 0;
}