#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<string.h>    
#include<stdlib.h>
#define ROW 3
#define COL 3
void InitMap(char tic[][COL], int x, int y, const char a)
{
	int i = 0, j = 0;
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
			tic[i][j] = a;
	}
}
void Display(char tic[][COL], int x, int y)
{
	int i = 0, j = 0;
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
			printf("%2c", tic[i][j]);
		printf("\n");
	}

}
void PcStep(char tic[][COL], int x1, int y1)
{
	int m = 0, n = 0;
	int i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (tic[i][j] == '0')
				m++;
		}
	}
	if (m > 0)
	{
		while (1)
		{
			m = rand() % (ROW + 1);
			n = rand() % (ROW + 1);
			if ((m != x1 || n != y1) && (tic[m][n] == '0'))
				break;
		}
	}
	else
		return;
	switch ((x1 + y1) % 2)
	{
	case 0://a[1][1] a[1][3] a[2][2] a[3][1] a[3][3]
		if (x1 == 1 && y1 == 1)//①
		{
			if (tic[x1][y1] + tic[x1][y1 + 1] + tic[x1][y1 + 2] - 2 * '0' == '2')
				return (tic[x1][y1 + 1] == '0') ? (tic[x1][y1 + 1] = '5') : (tic[x1][y1 + 2] = '5');
			else if (tic[x1][y1] + tic[x1 + 1][y1] + tic[x1 + 2][y1] - 2 * '0' == '2')
				return (tic[x1][y1 + 1] == '0') ? (tic[x1][y1 + 1] = '5') : (tic[x1][y1 + 2] = '5');
			else if (tic[x1][y1] + tic[x1 + 1][y1 + 1] + tic[x1 + 2][y1 + 2] - 2 * '0' == '2')
				return (tic[x1][y1 + 1] == '0') ? (tic[x1][y1 + 1] = '5') : (tic[x1][y1 + 2] = '5');
			else
				return tic[m][n] = '5';
		}
		if (x1 == 1 && y1 == 3)//③
		{
			if (tic[x1][y1] + tic[x1][y1 - 1] + tic[x1][y1 - 2] - 2 * '0' == '2')
				return (tic[x1][y1 - 1] == '0') ? (tic[x1][y1 - 1] = '5') : (tic[x1][y1 - 2] = '5');
			else if (tic[x1][y1] + tic[x1 + 1][y1 - 1] + tic[x1 + 2][y1 - 2] - 2 * '0' == '2')
				return (tic[x1 + 1][y1 - 1] == '0') ? (tic[x1 + 1][y1 - 1] = '5') : (tic[x1 + 2][y1 - 2] = '5');
			else if (tic[x1][y1] + tic[x1 + 1][y1] + tic[x1 + 2][y1] - 2 * '0' == '2')
				return (tic[x1 + 1][y1] == '0') ? (tic[x1 + 1][y1] = '5') : (tic[x1 + 2][y1] = '5');
			else
				return tic[m][n] = '5';
		}
		if (x1 == 2 && y1 == 2)//⑤
		{
			if (tic[x1][y1] + tic[x1][y1 - 1] + tic[x1][y1 + 1] - 2 * '0' == '2')
				return (tic[x1][y1 - 1] == '0') ? (tic[x1][y1 - 1] = '5') : (tic[x1][y1 + 1] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1] + tic[x1 + 1][y1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1] == '0') ? (tic[x1 - 1][y1] = '5') : (tic[x1 + 1][y1] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1 - 1] + tic[x1 + 1][y1 + 1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1 - 1] == '0') ? (tic[x1 - 1][y1 - 1] = '5') : (tic[x1 + 1][y1 + 1] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1 + 1] + tic[x1 + 1][y1 - 1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1 + 1] == '0') ? (tic[x1 - 1][y1 + 1] = '5') : (tic[x1 + 1][y1 - 1] = '5');
			else
				return tic[m][n] = '5';
		}
		if (x1 == 3 && y1 == 1)//⑦
		{
			if (tic[x1][y1] + tic[x1][y1 + 1] + tic[x1][y1 + 2] - 2 * '0' == '2')
				return (tic[x1][y1 + 1] == '0') ? (tic[x1][y1 + 1] = '5') : (tic[x1][y1 + 2] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1] + tic[x1 - 2][y1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1] == '0') ? (tic[x1 - 1][y1] = '5') : (tic[x1 - 2][y1] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1 + 1] + tic[x1 - 2][y1 + 2] - 2 * '0' == '2')
				return (tic[x1 - 1][y1 + 1] == '0') ? (tic[x1 - 1][y1 + 1] = '5') : (tic[x1 - 2][y1 + 2] = '5');
			else
				return tic[m][n] = '5';
		}
		if (x1 == 3 && y1 == 3)//⑨
		{
			if (tic[x1][y1] + tic[x1][y1 - 1] + tic[x1][y1 - 2] - 2 * '0' == '2')
				return (tic[x1][y1 - 1] == '0') ? (tic[x1][y1 - 1] = '5') : (tic[x1][y1 - 2] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1] + tic[x1 - 2][y1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1] == '0') ? (tic[x1 - 1][y1] = '5') : (tic[x1 - 2][y1] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1 - 1] + tic[x1 - 2][y1 - 2] - 2 * '0' == '2')
				return (tic[x1 - 1][y1 - 1] == '0') ? (tic[x1 - 1][y1 - 1] = '5') : (tic[x1 - 2][y1 - 2] = '5');
			else
				return tic[m][n] = '5';
		}
		break;
	case 1://a[1][2]  a[2][1] a[2][3] a[3][2]
		if (x1 == 1 && y1 == 2)//②
		{
			if (tic[x1][y1] + tic[x1][y1 - 1] + tic[x1][y1 + 1] - 2 * '0' == '2')
				return (tic[x1][y1 - 1] == '0') ? (tic[x1][y1 - 1] = '5') : (tic[x1][y1 + 1] = '5');
			else if (tic[x1][y1] + tic[x1 + 1][y1] + tic[x1 + 2][y1] - 2 * '0' == '2')
				return (tic[x1 + 1][y1] == '0') ? (tic[x1 + 1][y1] = '5') : (tic[x1 + 2][y1] = '5');
			else
				return tic[m][n] = '5';
		}
		if (x1 == 2 && y1 == 1)//④
		{
			if (tic[x1][y1] + tic[x1 - 1][y1] + tic[x1 + 1][y1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1] == '0') ? (tic[x1 - 1][y1] = '5') : (tic[x1 + 1][y1] = '5');
			else if (tic[x1][y1] + tic[x1][y1 + 1] + tic[x1][y1 + 2] - 2 * '0' == '2')
				return (tic[x1][y1 + 1] == '0') ? (tic[x1][y1 + 1] = '5') : (tic[x1][y1 + 2] = '5');
			else
				return tic[m][n] = '5';
		}
		if (x1 == 2 && y1 == 3)//⑥
		{
			if (tic[x1][y1] + tic[x1][y1 - 1] + tic[x1][y1 - 2] - 2 * '0' == '2')
				return (tic[x1][y1 - 1] == '0') ? (tic[x1][y1 - 1] = '5') : (tic[x1][y1 - 2] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1] + tic[x1 - 2][y1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1] == '0') ? (tic[x1 - 1][y1] = '5') : (tic[x1 - 2][y1] = '5');
			else
				return tic[m][n] = '5';
		}
		if (x1 == 3 && y1 == 2)//⑧
		{
			if (tic[x1][y1] + tic[x1][y1 - 1] + tic[x1][y1 + 1] - 2 * '0' == '2')
				return (tic[x1][y1 - 1] == '0') ? (tic[x1][y1 - 1] = '5') : (tic[x1][y1 + 1] = '5');
			else if (tic[x1][y1] + tic[x1 - 1][y1] + tic[x1 - 2][y1] - 2 * '0' == '2')
				return (tic[x1 - 1][y1] == '0') ? (tic[x1 - 1][y1] = '5') : (tic[x1 - 2][y1] = '5');
			else
				return tic[m][n] = '5';
		}
		break;
	default:
		break;
	}
}
int Judge(char tic[][COL])
{
	int flag = 0;
	if (tic[1][1] + tic[1][2] + tic[1][3] - 3 * '0' == 3 || \
		tic[2][1] + tic[2][2] + tic[2][3] - 3 * '0' == 3 || \
		tic[3][1] + tic[3][2] + tic[3][3] - 3 * '0' == 3 || \
		tic[1][1] + tic[2][1] + tic[3][1] - 3 * '0' == 3 || \
		tic[1][2] + tic[2][2] + tic[3][2] - 3 * '0' == 3 || \
		tic[1][3] + tic[2][3] + tic[3][3] - 3 * '0' == 3 || \
		tic[1][1] + tic[2][2] + tic[3][3] - 3 * '0' == 3 || \
		tic[1][3] + tic[2][2] + tic[3][1] - 3 * '0' == 3)
	{
		printf("玩家胜利\n");
		flag = 1;
	}
	else if (tic[1][1] + tic[1][2] + tic[1][3] - 3 * '0' == 15 || \
		tic[2][1] + tic[2][2] + tic[2][3] - 3 * '0' == 15 || \
		tic[3][1] + tic[3][2] + tic[3][3] - 3 * '0' == 15 || \
		tic[1][1] + tic[2][1] + tic[3][1] - 3 * '0' == 15 || \
		tic[1][2] + tic[2][2] + tic[3][2] - 3 * '0' == 15 || \
		tic[1][3] + tic[2][3] + tic[3][3] - 3 * '0' == 15 || \
		tic[1][1] + tic[2][2] + tic[3][3] - 3 * '0' == 15 || \
		tic[1][3] + tic[2][2] + tic[3][1] - 3 * '0' == 15)
	{
		printf("电脑胜利\n");
		flag = 1;
	}
	else if (tic[1][1] == '0' || \
		tic[1][2] == '0' || \
		tic[1][3] == '0' || \
		tic[2][1] == '0' || \
		tic[2][2] == '0' || \
		tic[2][3] == '0' || \
		tic[3][1] == '0' || \
		tic[3][2] == '0' || \
		tic[3][3] == '0')
		;
	else
	{
		printf("平局\n");
		flag = 1;
	}
	return flag;
}
void PcJudge()
{

}
int main()
{
	int x = 0, y = 0, count = 5;
	int jug = 0;
	char arr[3][3] = { 0 };
	srand(time(NULL));
	//设置初始棋盘数组里面都放0，
	InitMap(arr, ROW, COL, '0');
	Display(arr, ROW, COL);
	//开始下棋   我输入字符‘1’电脑输入字符‘5’；
	while (count)
	{
		while (1)//     my_step
		{
			printf("请输入坐标\n");
			scanf("%d%d", &x, &y);
			if (arr[x][y] == '0')
				break;
		}
		arr[x][y] = '1';
		count--;//
		Display(arr, ROW, COL);
		jug = Judge(arr);
		if (jug == 1)
			break;
		printf("\n");
		PcStep(arr, x, y);
		Display(arr, ROW, COL);
		jug = Judge(arr);
		if (jug == 1)
			break;
	}
	system("pause");
	return 0;
}

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#define ROWS 7
#define COLS 7
#define ROW 3
#define COL 3
void InitMap(char tic[][COLS], int x, int y, const char a)
{
	int i = 0, j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
			tic[i][j] = a;
	}
}
void Display(char tic[][COLS], int x, int y)
{
	int i = 0, j = 0;
	for (i = 2; i < x-2 ; i++)
	{
		for (j = 2; j < y-2; j++)
			printf("%2c", tic[i][j]);
		printf("\n");
	}

}
void PcStep(char tic[][COLS])
{
	//int x = rand() % ROW;
	//int y = rand() % ROW;

}
int main()
{
	int x = 0;
	int y = 0;
	char arr[7][7] = { 0 };
	srand(time(NULL));
	//设置初始棋盘数组里面都放*，
	InitMap(arr, ROWS, COLS, '*');
	Display(arr, ROWS, COLS);
	//开始下棋
	printf("请输入两个数\n");
	scanf("%d%d", &x, &y);
	x = x + 1, y = y + 1;
	arr[x][y] = '1';
	Display(arr, ROWS, COLS);

	system("pause");
	return 0;
}
#endif
