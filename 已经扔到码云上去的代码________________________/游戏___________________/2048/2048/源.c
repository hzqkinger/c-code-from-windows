#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<CoreWindow.h>
#define ROW 4
#define COL 4
unsigned int moves = 0;
enum
{
	left = 1,
	down,
	right,
	up = 5,
};
void Initarr(int arr[][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			arr[i][j] = 0;
	}
}
void Random(int arr[][COL])
{
	int x, y;
	int tmp[2] = { 2, 4 };
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (arr[x][y] == 0)
		{
			arr[x][y] = tmp[rand() % 2];
			break;
		}
	}
}
void print(int arr[][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			printf("%5d", arr[i][j]);
		printf("\n");
	}
}
void uparr(int arr[][COL])
{
	int i, j;
	for (j = 0; j < COL; j++)
	{
		for (i = 0; i < ROW; i++)//先加
		{
			if (arr[i][j] != 0)
			{
				if (i + 1 < ROW && arr[i + 1][j] != 0)
				{
					if (arr[i][j] == arr[i + 1][j])
						arr[i][j] *= 2, arr[i + 1][j] = 0;
				}
				else if (i + 2 < ROW && arr[i + 2][j] != 0)
				{
					if (arr[i][j] == arr[i + 2][j])
						arr[i][j] *= 2, arr[i + 2][j] = 0;
				}
				else if (i + 3 < ROW && arr[i + 3][j] != 0)
				{
					if (arr[i][j] == arr[i + 3][j])
						arr[i][j] *= 2, arr[i + 3][j] = 0;
				}
			}
		}
		for (i = 0; i < ROW; i++)//后移
		{
			if (arr[i][j] == 0)
			{
				if (i + 1 < ROW&& arr[i + 1][j] != 0)
				{
					arr[i][j] = arr[i + 1][j], arr[i + 1][j] = 0;
				}
				else if (i + 2 < ROW && arr[i + 2][j] != 0)
				{
					arr[i][j] = arr[i + 2][j], arr[i + 2][j] = 0;
				}
				else if (i + 3 < ROW && arr[i + 3][j] != 0)
				{
					arr[i][j] = arr[i + 3][j], arr[i + 3][j] = 0;
				}
			}
		}
	}
}
void downarr(int arr[][COL])
{
	int i, j;
	for (j = 0; j < COL; j++)
	{
		for (i = ROW - 1; i >= 0; i--)//先加
		{
			if (arr[i][j] != 0)
			{
				if (i - 1 >= 0 && arr[i - 1][j] != 0)
				{
					if (arr[i][j] == arr[i - 1][j])
						arr[i][j] *= 2, arr[i - 1][j] = 0;
				}
				else if (i - 2 >= 0 && arr[i - 2][j] != 0)
				{
					if (arr[i][j] == arr[i - 2][j])
						arr[i][j] *= 2, arr[i - 2][j] = 0;
				}
				else if (i - 3 >= 0 && arr[i - 3][j] != 0)
				{
					if (arr[i][j] == arr[i - 3][j])
						arr[i][j] *= 2, arr[i - 3][j] = 0;
				}
			}
		}
		for (i = ROW - 1; i >= 0; i--)//后移
		{
			if (arr[i][j] == 0)
			{
				if (i - 1 >= 0 && arr[i - 1][j] != 0)
				{
					arr[i][j] = arr[i - 1][j], arr[i - 1][j] = 0;
				}
				else if (i - 2 >= 0 && arr[i - 2][j] != 0)
				{
					arr[i][j] = arr[i - 2][j], arr[i - 2][j] = 0;
				}
				else if (i - 3 >= 0 && arr[i - 3][j] != 0)
				{
					arr[i][j] = arr[i - 3][j], arr[i - 3][j] = 0;
				}
			}
		}
	}
}
void leftarr(int arr[][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)//先加
		{
			if (arr[i][j] != 0)
			{
				if (j + 1 < COL && arr[i][j + 1] != 0)
				{
					if (arr[i][j] == arr[i][j + 1])
						arr[i][j] *= 2, arr[i][j + 1] = 0;
				}
				else if (j + 2 < COL && arr[i][j + 2] != 0)
				{
					if (arr[i][j] == arr[i][j + 2])
						arr[i][j] *= 2, arr[i][j + 2] = 0;
				}
				else if (j + 3 < COL && arr[i][j + 3] != 0)
				{
					if (arr[i][j] == arr[i][j + 3])
						arr[i][j] *= 2, arr[i][j + 3] = 0;
				}
			}
		}
		for (j = 0; j < COL; j++)//后移
		{
			if (arr[i][j] == 0)
			{
				if (j + 1 < COL&& arr[i][j + 1] != 0)
				{
					arr[i][j] = arr[i][j + 1], arr[i][j + 1] = 0;
				}
				else if (j + 2 < COL && arr[i][j + 2] != 0)
				{
					arr[i][j] = arr[i][j + 2], arr[i][j + 2] = 0;
				}
				else if (j + 3 < COL && arr[i][j + 3] != 0)
				{
					arr[i][j] = arr[i][j + 3], arr[i][j + 3] = 0;
				}
			}
		}
	}
}
void rightarr(int arr[][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = COL - 1; j >= 0; j--)//先加
		{
			if (arr[i][j] != 0)
			{
				if (j - 1 >= 0 && arr[i][j - 1] != 0)
				{
					if (arr[i][j] == arr[i][j - 1])
						arr[i][j] *= 2, arr[i][j - 1] = 0;
				}
				else if (j - 2 >= 0 && arr[i][j - 2] != 0)
				{
					if (arr[i][j] == arr[i][j - 2])
						arr[i][j] *= 2, arr[i][j - 2] = 0;
				}
				else if (j + 3 >= 0 && arr[i][j - 3] != 0)
				{
					if (arr[i][j] == arr[i][j - 3])
						arr[i][j] *= 2, arr[i][j - 3] = 0;
				}
			}
		}
		for (j = COL - 1; j >= 0; j--)//后移
		{
			if (arr[i][j] == 0)
			{
				if (j - 1 >= 0 && arr[i][j - 1] != 0)
				{
					arr[i][j] = arr[i][j - 1], arr[i][j - 1] = 0;
				}
				else if (j - 2 >= 0 && arr[i][j - 2] != 0)
				{
					arr[i][j] = arr[i][j - 2], arr[i][j - 2] = 0;
				}
				else if (j - 3 >= 0 && arr[i][j - 3] != 0)
				{
					arr[i][j] = arr[i][j - 3], arr[i][j - 3] = 0;
				}
			}
		}
	}
}
void Step(int arr[][COL])
{
	int num;
	printf("请输入你要移动的方向：1.left,2.down,3.right,5.up\n");
	scanf("%d", &num);
	switch (num)
	{
	case up:
		uparr(arr);
		printf("moves = %u\n", ++moves);
		break;
	case down:
		downarr(arr);
		printf("moves = %u\n", ++moves);
		break;
	case left:
		leftarr(arr);
		printf("moves = %u\n", ++moves);
		break;
	case right:
		rightarr(arr);
		printf("moves = %u\n", ++moves);
		break;
	default:
		printf("the enter numbeer is wrong!\n");
		break;

	}
}
int Judge(int arr[][COL])
{
	int i, j,flag = 1;
	for (i = 0; i < ROW; i++)
	{
		if (flag == 0)
			break;
		for (j = 0; j < COL; j++)
		{
			if (arr[i][j] == 0)
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
int main()
{
	int arr[ROW][COL];
	srand(time(NULL));
	//设置初始二维数组
	Initarr(arr);
	Random(arr);
	Random(arr);
	print(arr);
	//开始游戏
	while (1)
	{
		Step(arr);//先加后移
		Random(arr);
		print(arr);
		if (Judge(arr))//这里的judge函数有瑕疵，因为它只是判断数组中是否不含0了，
			break;     //而真正2048的判断规则不是这样的。（求大神指导）
	}
	system("pause");
	return 0;
}