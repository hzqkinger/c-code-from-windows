#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main(){
	int i = 3;
	//printf("%d\n", (++i++ + i++ + i));

	//printf("%d\n", (a++++ + b));                //̰�ķ�

	//int j =(i++, i++, i++);           // ++�������ļ�����֤  
	//printf("%d\n", (++i, i++, i + 10));
	//for (i = 0; i < 10; i++){;}
	//printf("%d\n", ((i++) + (i++) + (i++)));
	//printf("%d\n", i);
	printf("%d\n", (++i) + (++i) + (++i));

	////for (i = 0, printf("Ҽ=%d\n", i); printf("��=%d\n", i), i < 5; i++, printf("��=%d\n", i))
	////{printf("��=%d\n", i);}
	system("pause");
	return 0;
}