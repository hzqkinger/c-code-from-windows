#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main(){
	//char bha[2];
	//short cha[2];
	//int dha[2];
	//printf("%d %d %d\n", sizeof(bha), sizeof(cha), sizeof(dha));
	struct Stu
	{
		int num;
		char*pc; //结构体内存对齐
		short s;
		char a[2];
		short d[4];
	}*p;
	//char*p = new struct Stu;
	printf("%d %d %d %d %d\n", sizeof(p->num), sizeof(char*), sizeof(p->s), sizeof(p->a), sizeof(p->d));
	printf("%d\n", sizeof(struct Stu));
	//printf("%d\n", p + 0x1);
	system("pause");
	return 0;
}