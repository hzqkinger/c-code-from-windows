#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()
{
	float num = 0;             //求一个数的开方根算法一
	float a = 0;
	printf("enter a number:");
	scanf("%f", &num);
	a = sqrt(num);
	printf("square root of %f is %f\n", num, a);

	//float new_guess = 1;      //求一个数的开方根算法二
	//float last_guess = 1;
	//float num = 0;
	//printf("enter a number:");
	//scanf("%f", &num);
	//do
	//{
	//	last_guess = new_guess;
	//	new_guess = (last_guess + num / last_guess) / 2;
	//	printf("%f\n", new_guess);
	//} while (new_guess != last_guess);
	//printf("square root of %f is %f\n", num, new_guess);

	system("pause");
	return 0;
}
