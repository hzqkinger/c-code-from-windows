#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main(){
	int i = 3;
	//printf("%d\n", (++i++ + i++ + i));

	//printf("%d\n", (a++++ + b));                //贪心法

	//int j =(i++, i++, i++);           // ++操作符的计算验证  
	//printf("%d\n", (++i, i++, i + 10));
	//for (i = 0; i < 10; i++){;}
	//printf("%d\n", ((i++) + (i++) + (i++)));
	//printf("%d\n", i);
	printf("%d\n", (++i) + (++i) + (++i));

	////for (i = 0, printf("壹=%d\n", i); printf("贰=%d\n", i), i < 5; i++, printf("叁=%d\n", i))
	////{printf("肆=%d\n", i);}
	system("pause");
	return 0;
}