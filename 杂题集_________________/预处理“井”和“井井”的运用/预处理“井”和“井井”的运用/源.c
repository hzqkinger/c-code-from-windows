#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
#define SQR(x) printf("the square of "#x" is %d.",((x)*(x)))
#define PRINT(FORMAT,VALUE) printf("the value of"#VALUE"is"FORMAT"\n",VALUE)
int main(){                  //预处理“#”和“##”的运用
	//SQR(8);
	int a = 2;
	PRINT("%d", 3);
	system("pause");
	return 0;
}