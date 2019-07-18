#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<string.h>    
#define ROW 5
#define COL 5
#define LEN 9
void InitMap(char tic[][COL], int x, int y)
{
	int i = 0, j = 0,k = 0;
	char arr[LEN] = "123456780";
	int brr[LEN] = { 0 };
	for (i = 1; i < x-1; i++)
	{
		for (j = 1; j < y-1; j++)
		{
			while (1)
			{
				k = rand() % LEN;
				brr[k] += 1;
				if (brr[k] == 1)
					break;
			}
			tic[i][j] = arr[k];
		}
	}
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
				tic[i][j] = '9';
		}

	}
}
void Display(char tic[][COL], int x, int y)
{
	int i = 0, j = 0;
	for (i = 1; i < x-1; i++)
	{
		for (j = 1; j < y-1; j++)
			printf("%2c", tic[i][j]);
		printf("\n");
	}
}
void Step(char tic[][COL], int x, int y)
{
	char tmp;
	if (tic[x][y - 1] == '0')
	{
		tmp = tic[x][y];
		tic[x][y] = tic[x][y - 1];
		tic[x][y - 1] = tmp;
	}
	else if (tic[x - 1][y] == '0')
	{
		tmp = tic[x][y];
		tic[x][y] = tic[x - 1][y];
		tic[x - 1][y] = tmp;
	}
	else if (tic[x][y + 1] == '0')
	{
		tmp = tic[x][y];
		tic[x][y] = tic[x][y + 1];
		tic[x][y + 1] = tmp;
	}
	else if (tic[x + 1][y] == '0')
	{
		tmp = tic[x][y];
		tic[x][y] = tic[x + 1][y];
		tic[x + 1][y] = tmp;
	}
	else
		;
}
int Judg(char tic[][COL], int x, int y)
{
	int i = 0,j = 0,k = 0;
	char brr[LEN] = "123456780";
	for (i = 1; i < x - 1; i++)
	{
		for (j = 1; j < y - 1; j++)
			if(tic[i][j] != brr[k++])
				break;
	}
	if (k == (ROW - 2)*(COL - 2))
		return 1;
	else
		return 0;
}
int main()
{
	//int i = 0, j = 0;//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	//int k = 0;                //所有A，目的是把3*3宫格拼好，然后测试Judg函数是否正确。
	//char arr1[LEN] = "123456780";//AAAAAAAAAAAAAAAAAAAAAAAAAAA
	int x = 0, y = 0;
	int flag = 0;
	char arr[ROW][COL] = { '0' };
	srand(time(NULL));
	//设置初始3*3宫格里随机放字符1,2,3,4,5,6,7,8,0，
	InitMap(arr, ROW, COL);
	Display(arr, ROW, COL);
	//开始拼图
	while (1)
	{
		//for (i = 1; i < ROW - 1; i++)//AAAAAAAAAAAAAAAAAAAAA
		//{
		//	for (j = 1; j < COL - 1; j++)
		//		arr[i][j] = arr1[k++];
		//}//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
		while (1)//其作用是输入有效的坐标
		{
			printf("请输入横纵坐标的值：\n");
			scanf("%d%d", &x, &y);
			if (x > 0 && x<ROW - 1 && y>0 && y < COL - 1)
				break;
			else
				printf("输入数据有误>\n");
		}
		Step(arr, x, y);
		Display(arr, ROW, COL);
		flag = Judg(arr, ROW, COL);
		if (flag == 1)
		{
			printf("完成拼图！\n");
			break;
		}
	}
	system("pause");
	return 0;
}