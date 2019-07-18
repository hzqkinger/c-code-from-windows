#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<CoreWindow.h>
#include<Windows.h>
int main()
{                     //文件定位函数：ftell()  fgetpos()  fsetpos()  fseek()  rewind()
	fpos_t a = 5, b;
	fpos_t *pos = &a;
	FILE *input;
	input = fopen("data3.txt", "r");
	if (input == NULL)
	{
		perror("data3");
		exit(EXIT_FAILURE);
	}
	fseek(input, 3, SEEK_SET);
	b = ftell(input);
	fsetpos(input, pos);
	fgetpos(input, pos);
	b = ftell(input);
	rewind(input);
	b = ftell(input);
	system("pause");
	return 0;
}