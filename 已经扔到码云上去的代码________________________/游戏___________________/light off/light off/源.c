#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#define ROW 7
#define COL 7
void Initmap(char tic[][COL], int row, int col)
{
	int x, y,i,j;
	int cnt;//���ó�ʼ�����ĸ���
	while (1)
	{
		cnt = rand() % ((row - 2)*(col - 2));
		if (cnt > 0)
			break;
	}
	for (i = 0; i < row; i++)//�������ʼΪ�ַ�'0'
	{
		for (j = 0; j < col; j++)
			tic[i][j] = '0';
	}
	while (cnt)//���������е����ĸ�����λ�ã�����Ϊ�ַ�'1'
	{
		while (1)
		{
			x = rand() % 5 + 1;
			y = rand() % 5 + 1;
			if (tic[x][y] == '0')
			{
				tic[x][y] = '1';
				break;
			}
		}
		cnt--;
	}
}
void Display(char tic[][COL], int row, int col)
{
	int i, j;
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			printf("%2c", tic[i][j]);
		}
		printf("\n");
	}
}
void Step(char tic[][COL],int x,int y)
{
	(tic[x][y] == '1') ? (tic[x][y] = '0') : (tic[x][y] = '1');//���ڲ��������ȼ����⣬���ﶼ���������
	(tic[x-1][y] == '1') ? (tic[x-1][y] = '0') : (tic[x-1][y] = '1');
	(tic[x+1][y] == '1') ? (tic[x+1][y] = '0') : (tic[x+1][y] = '1');
	(tic[x][y-1] == '1') ? (tic[x][y-1] = '0') : (tic[x][y-1] = '1');
	(tic[x][y+1] == '1') ? (tic[x][y+1] = '0') : (tic[x][y+1] = '1');
}
int Judge(char tic[][COL], int row, int col)//����flag��ֵ��1���е�û�𣬷���ʱ0��ȫ��Ϩ��
{
	int i, j,flag = 0;
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (tic[i][j] == '1')
				flag = 1;
		}
	}
	return flag;
}
int main()
{
	//int i, j;//Ϊ����ϲ���Judge��������õ���������
	int flag = 0,count = 0;
	int x, y;
	char arr[ROW][COL];
	srand(time(NULL));
	//���õ�ͼ
	Initmap(arr,ROW,COL);
	Display(arr, ROW, COL);
	//��ʼ��Ϸ
	while (1)
	{
		while (1)//��֤���������Ϸ�
		{
			printf("���������꣺\n");
			scanf("%d%d", &x, &y);
			if (x > 0 && x<6 && y>0 && y < 6)
				break;
			else
				printf("������������\n");
		}
		Step(arr, x, y);
		//for (i = 1; i < ROW - 1; i++)//Ϊ�˲���Judge�����������жϲ���ȫ������Ϊ�ַ�'0'
		//{
		//	for (j = 1; j < COL - 1; j++)
		//	{
		//		arr[i][j] = '0';
		//	}
		//}
		Display(arr, ROW, COL);
		printf("your moves = %d\n", ++count);
		flag = Judge(arr, ROW, COL);
		if (flag == 0)
		{
			printf("you win!\n");
			break;
		}
	}
	system("pause");
	return 0;
}