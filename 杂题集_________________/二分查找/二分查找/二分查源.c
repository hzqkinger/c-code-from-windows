#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996)
//int main()
//{
//	int arr[] = {11,22,33,44,55,66,77,88,99};
//	int key = 0;
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0]);
//	int mid = 0;
//	printf("���������֣�");
//	scanf("%d", &key);
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (key < arr[mid])
//		{
//			right = mid-1;
//		}
//		else if (key == arr[mid])
//		{
//			printf("��������������е�%dλ\n", (mid + 1));
//			break;
//		}
//		else
//		{
//			left = mid+1;
//		}
//	}
//	if (left > right)
//	{
//		printf("�����в�������������!\n");
//	}
//	system("pause");
//	return 0;
//}

//��ӭPlay��������Ϸ!
void Binary()
{
	srand(time(NULL));
	int dest = rand() % 100;
	int key = 0;
	int left = 0;
	int right = 100;
	int mid = 0;
	//printf("%d\n", dest);
	while (left <= right)
	{
		printf("������1~100����\n");
		scanf("%d", &key);
		mid = (left + right) / 2;
		if (key < dest)
		{
			right = mid - 1;
			printf("���С��");
		}
		else if (key == dest)
		{
			printf("��ϲ�¶���\n");
			break;
		}
		else
		{
			left = mid + 1;
			printf("��´���");

		}
	}

}

//����������������ҵ�һ������tag����
int Binary2(int *arr, int left, int right, int tag)//��[left,right)
{
	while (left < right){//ע��������<��������<=
		int mid = (left + right) >> 1;//ע������mid��ȡ��(ps:ֻҪ��������յģ�midȡ��)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid + 1 : (right = mid);//ע������right��ȡֵ
	}
	return -1;
}
int Binary3(int *arr, int left, int right, int tag)//��[left,right]
{
	while (left <= right){//ע��������<=��������<
		int mid = (left + right) >> 1;//ע������mid��ȡ��(ps:ֻҪ��������յģ�midȡ��)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid + 1 : (right = mid - 1);//ע������right��ȡֵ
	}
	return -1;
}
int Binary4(int *arr, int left, int right, int tag)//��(left,right]
{
	while (left < right){//ע��������<��������<=
		int mid = (left + right + 1) >> 1;//ע������mid�ǽ�һ(ps:ֻҪ�������󿪵ģ�mid��һ)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid: (right = mid - 1);//ע������left��ȡֵ
	}
	return -1;
}
int Binary5(int *arr, int left, int right, int tag)//��(left,right��
{
	while (left < right - 1){//ע��������< ��<right-1��������<=
		int mid = (left + right + 1) >> 1;//ע������mid�ǽ�һ(ps:ֻҪ�������󿪵ģ�mid��һ)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid : (right = mid);//ע������left��right��ȡֵ
	}
	return -1;
}

//�����������������ҵ���һ�����ڵ���tag����(ps:���������һ��>=tag��������Ҷ�����)
int Binary6(int *arr, int left, int right, int tag)//[left, right)
{
	while (left < right){
		int mid = (left + right) >> 1;
		arr[mid] < tag ? left = mid + 1 : (right = mid);
	}
	return right;//���ص�һ�����ڵ���tag�������±�

	//while (left < right){
	//	int mid = (left + right) >> 1;
	//	arr[mid] <= tag ? left = mid + 1 : (right = mid);//ע������<=������<
	//}
	//return right;//���ص�һ������tag�������±�
}
//�����������������ҵ����һ��С�ڵ���tag����(ps:�����ҵ�һ��<=tag��������Ҷ�����)
int Binary7(int *arr, int left, int right, int tag)//(left, right]
{
	while (left < right){
		int mid = (left + right + 1) >> 1;
		arr[mid] < tag ? left = mid : (right = mid - 1);
	}
	return left;//�������һ��С��tag�������±�

	//while (left < right){
	//	int mid = (left + right + 1) >> 1;
	//	arr[mid] <= tag ? left = mid : (right = mid - 1);
	//}
	//return left;//�������һ��С�ڵ���tag�������±�
}

int main()
{
	//printf("��ӭPlay��������Ϸ!\n");
	//Binary();

	int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	int flag = Binary2(arr, 0, sizeof(arr) / sizeof(arr[0]), 55);//[left,right)ǿ���Ƽ�д��
	printf("%d\n", flag);
	flag = Binary3(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 44);//[left,right]�Ƽ�д��
	printf("%d\n", flag);
	flag = Binary4(arr, -1, sizeof(arr) / sizeof(arr[0]) - 1, 44);//(left,right]���Ƽ�д��
	printf("%d\n", flag);
	flag = Binary5(arr, -1, sizeof(arr) / sizeof(arr[0]), 45);//(left,right)�ǳ����Ƽ�д��
	printf("%d\n", flag);

	printf("--------------���Ƿָ���-------------\n");
	int arr2[] = { 11, 22, 22, 23, 33,33, 33, 35, 44, 45, 55,55, 56};
	flag = Binary6(arr2, 0, sizeof(arr2) / sizeof(arr2[0]), 33);// [left, right)
	printf("%d\n", flag);
	//��һ��>=tag��������ǰ���һ�����������һ��<tag����(�߽�������п���)
	//��һ��>tag��������ǰ���һ�����������һ��<=tag����(�߽�������п���)
	flag = Binary7(arr2, -1, sizeof(arr2) / sizeof(arr2[0]) - 1, 33);// (left, right]
	printf("%d\n", flag);

	system("pause");
	return 0;
}