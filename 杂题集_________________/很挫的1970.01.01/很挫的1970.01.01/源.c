#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//题二
{
	int second, min, hour, day, month, year;
	printf("请输入秒数：\n");
	scanf("%d", &second);
	day = second / (60 * 60 * 24);
	month = day / 30;
	day = 1 + day % 30;//
	year = 1970 + month / 12;//
	month = 1 + month % 12;//
	hour = second % (60 * 60 * 24) / 3600;//
	min = second % 3600 / 60;//
	second = second % 60;//
	printf("1970/01/01 00:00:00\n");
	printf("%d/%d/%d %d:%d:%d\n", year, month, day, hour, min, second);
	system("pause");
	return 0;
}