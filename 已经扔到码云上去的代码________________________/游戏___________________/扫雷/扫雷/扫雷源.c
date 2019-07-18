#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#define ROWS 12
#define COLS 12
#define ROW 10
#define COL 10
#define DEFAULT_COUNT 81
void SetMine(char board[ROWS][COLS])
{
	int count = DEFAULT_COUNT;
	while (count)
	{
		int x = rand() % ROW;
		int y = rand() % ROW;
		if ((x >= 1) && (y >= 1)&&board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}	
}
void InitBoard(char board[][COLS], int x, int y, const char a)
{
	int i = 0,j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
			board[i][j] = a;
	}
}
void Display(char board[][COLS], int x, int y)
{
	int i = 0, j = 0;
	for (i = 1; i < x-1; i++)
	{
		for (j = 1; j < y-1; j++)
			printf("%2c", board[i][j]);
			printf("\n");
	}

}
void Adds(char show1[][COLS],char mine1[][COLS],int x,int y)
{

	show1[x][y] = 48 + mine1[x - 1][y - 1] + mine1[x - 1][y] + mine1[x - 1][y + 1] + \
		mine1[x][y + 1] + mine1[x + 1][y + 1] + mine1[x + 1][y] + mine1[x + 1][y - 1] + \
		mine1[x][y - 1] - 8 * '0';
}
void Judge1(char show1[][COLS], char mine1[][COLS], int x, int y, int* count)
{                                //调用改函数之前mine[][] == '0'
	int tmp1 = x;
	int tmp2 = y;
	if (show1[tmp1][tmp2] == '0')
	{
		x = tmp1;
		y = tmp2;
		if (--x&&--y)//①
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge1(show1, mine1, x, y,&count);
		}
		//要重置为原来的x,y
		x = tmp1;
		y = tmp2;
		if (--x&&y)//②
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge1(show1, mine1, x, y, &count);
		}
		x = tmp1;
		y = tmp2;
		if (--x&&++y && y < COLS)//③
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge1(show1, mine1, x, y, &count);
		}
		x = tmp1;
		y = tmp2;
		if (x&&++y && y < COLS)//④
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge1(show1, mine1, x, y, &count);
		}
	}
}
void Judge(char show1[][COLS], char mine1[][COLS], int x, int y,int* count)
{                                //调用改函数之前mine[][] == '0'
	int tmp1 = x;
	int tmp2 = y;
	if (show1[tmp1][tmp2] == '0')
	{
		//x = tmp1;
		//y = tmp2;
		//if (--x&&--y)//①
		//{
		//	Adds(show1, mine1, x, y);
		//	*count++;
		//	if (show1[x][y] == '0')
		//		Judge(show1, mine1, x, y,&count);
		//}
		////要重置为原来的x,y
		//x = tmp1;
		//y = tmp2;
		//if (--x&&y)//②
		//{
		//	Adds(show1, mine1, x, y);
		//	*count++;
		//	if (show1[x][y] == '0')
		//		Judge(show1, mine1, x, y, &count);
		//}
		//x = tmp1;
		//y = tmp2;
		//if (--x&&++y && y < COLS)//③
		//{
		//	Adds(show1, mine1, x, y);
		//	*count++;
		//	if (show1[x][y] == '0')
		//		Judge(show1, mine1, x, y, &count);
		//}
		//x = tmp1;
		//y = tmp2;
		//if (x&&++y && y < COLS)//④
		//{
		//	Adds(show1, mine1, x, y);
		//	*count++;
		//	if (show1[x][y] == '0')
		//		Judge(show1, mine1, x, y, &count);
		//}
		x = tmp1;
		y = tmp2;
		if (++x&&++y&&x < ROWS && y < COLS)//⑤
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge(show1, mine1, x, y, &count);
		}
		x = tmp1;
		y = tmp2;
		if (++x&&y&&x < ROWS)//⑥
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge(show1, mine1, x, y, &count);
		}
		x = tmp1;
		y = tmp2;
		if (++x&&--y&&x < ROWS)//⑦
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge(show1, mine1, x, y, &count);
		}
		x = tmp1;
		y = tmp2;
		if (x&&--y)//⑧
		{
			Adds(show1, mine1, x, y);
			*count++;
			if (show1[x][y] == '0')
				Judge(show1, mine1, x, y, &count);
		}
	}
	else
		;
}
int main()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	int x = 0, y = 0;
	int win = 0;
	int count = 1;
	srand(time(NULL));
	//1丶布置雷
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine);
	Display(mine, ROWS, COLS);
	Display(show, ROWS, COLS);
	//2丶扫雷
	while (win < (ROW*COL - DEFAULT_COUNT))
	{

		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if ((x >= 1) && (x <= ROW) && (y >= 1) && (y <= COL))
		{
			if (count++ == 1 && mine[x][y] == '1')
			{
				mine[x][y] = '0';
				while (1)
				{
					int m = rand() % ROW;
					int n = rand() % ROW;
					if ((m >= 1) && (n >= 1) && mine[m][n] == '0')
					{
						mine[m][n] = '1';
						break;
					}
				}
				//Display(mine, ROWS, COLS);
			}
			else if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				break;
			}
			else                         //mine[x][y] == 0;
			{
				if (show[x][y] == '*')
					win++;
				Adds(show, mine, x, y);
				Judge1(show, mine, x, y,&win);
				Judge(show, mine, x, y, &win);
				Display(show, ROWS, COLS);
			}
		}
	}
	if (win == ROW*COL - DEFAULT_COUNT)
		printf("你赢了！");
	system("pause");
	return 0;
}




//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<Windows.h>
//#include<time.h>
//#include<stdlib.h>
//#define ROWS 12
//#define COLS 12
//#define ROW 10
//#define COL 10
//#define DEFAULT_COUNT 10
//void SetMine(char board[ROWS][COLS])
//{
//	int count = DEFAULT_COUNT;
//	while (count)
//	{
//		int x = rand() % ROW;
//		int y = rand() % ROW;
//		if ((x >= 1) && (y >= 1) && board[x][y] == '0')
//		{
//			board[x][y] = '1';
//			count--;
//		}
//	}
//}
//void InitBoard(char board[][COLS], int x, int y, const char a)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//			board[i][j] = a;
//	}
//}
//void Display(char board[][COLS], int x, int y)
//{
//	int i = 0, j = 0;
//	for (i = 1; i < x - 1; i++)
//	{
//		for (j = 1; j < y - 1; j++)
//			printf("%2c", board[i][j]);
//		printf("\n");
//	}
//
//}
//int main()
//{
//	char mine[ROWS][COLS] = { 0 };
//	char show[ROWS][COLS] = { 0 };
//	int x = 0, y = 0;
//	int win = 0;
//	int count = 1;
//	srand(time(NULL));
//	//1丶布置雷
//	InitBoard(mine, ROWS, COLS, '0');
//	InitBoard(show, ROWS, COLS, '*');
//	SetMine(mine);
//	Display(mine, ROWS, COLS);
//	Display(show, ROWS, COLS);
//	//2丶扫雷
//	while (win < (ROW*COL - DEFAULT_COUNT))
//	{
//
//		printf("请输入坐标：");
//		scanf("%d%d", &x, &y);
//		if ((x >= 1) && (x <= ROW) && (y >= 1) && (y <= COL))
//		{
//			if (count == 1 && mine[x][y] == '1')
//			{
//				mine[x][y] = '0';
//				while (1)
//				{
//					int m = rand() % ROW;
//					int n = rand() % ROW;
//					if ((m >= 1) && (n >= 1) && mine[m][n] == '0')
//					{
//						mine[m][n] = '1';
//						count++;
//						break;
//					}
//				}
//			}
//			else if (mine[x][y] == '1')
//			{
//				printf("你被炸死了\n");
//				break;
//			}
//			else
//			{
//				if (show[x][y] == '*')
//					win++;
//				show[x][y] = 48 + mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + \
//					mine[x][y + 1] + mine[x + 1][y + 1] + mine[x + 1][y] + mine[x + 1][y - 1] + \
//					mine[x][y - 1] - 8 * '0';
//				Display(show, ROWS, COLS);
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}



