#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
#if 0  // ����һ��������żλ
#define SWAP(m) (((m&0xaaaaaaaa)>>1)|((m&0x55555555)<<1) )
int main()
{
	int a = 0;
	printf("���������֣�");
	scanf("%d", &a);
	printf("%d\n",SWAP(a));
	system("pause");
	return 0;
}
#endif
#if 0  //����������������
#define MAX(x,y) ((x)>(y)?(x):(y))
int main()
{
	int a = 0, b = 0;
	printf("������������");
	scanf("%d%d", &a, &b);
	printf("%d\n", MAX(a, b));
	system("pause");
	return 0;
}
#endif
#if 0     //���������������ж��ٸ���ͬλ
int main()
{
	int m = 0, n = 0;
	int ret = 0, count = 0;
	printf("������������");
	scanf("%d%d", &m, &n);
	ret = m^n;
	while (ret != 0)
	{
		ret &= (ret - 1);
		count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
#if 0         //��һ�������е�������������ǰ��
int main()
{
	int i = 0, j = 0;
	int temp = 0;
	int arr[10];// = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("������10��������");
	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
		{
			for (j = 9; j >i; j--)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	system("pause");
	return 0;
}
#endif
//#if 0                 //���Ͼ��������Ƿ�������������
#define Row 3
#define Cols 4
int main()
{
	int r = 0;
	int c = Cols - 1;
	int i = 0, key = 0;
	int arr[][4] = { 1, 3, 4, 7, 2, 5, 6, 13, 7, 8, 9, 14 };
	printf("������һ������");
		scanf("%d", &key);
	//printf("����������arr[3][4]��12����ʼֵ��");
	//for (i = 0; i < 12; i++)
	//	scanf("%d", &arr[i]);
	while (r < Row)
	{
		if ((key < arr[r][c]) && (c >= 0))
			c--;
		else if ((key == arr[r][c]) && (c >= 0))
		{
			printf("�����д�������������");
			break;
		}
		else
		r++;
	}
	if (r == Row)
		printf("�����в���������������");
	system("pause");
	return 0;
}
//#endif
