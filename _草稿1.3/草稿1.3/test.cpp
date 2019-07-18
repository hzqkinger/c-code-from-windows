#include<stdio.h>
//extern "C" int printf(char const *format, ...);

void func11111111()
{
	//std::cout << "sssssssssssssssssssss";
	printf("我也能在函数体内声明,且作用域只在该函数中\n");
}
void test3(int x = 10)
{
	printf("xxxxxxxxxxxxx\n");
}