#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

//����A�� ȥ��ע��
//��Ŀ����
//����һ�δ��룬��ע�͵Ĳ���ȥ�������ʣ��Ĵ��롣
//ע�͹���������ʽ��
//1. ��ע�ӣ���//��ͷ��һֱ���õ���βΪֹ��
//2. ��ע�ӣ���/*��ͷ����*/��β���м䲿�ֶ���ע�ͣ����Կ��С�
//��ע�⡿
//������β���з�
//
//�����ʽ
//һ�γ������
//
//�����ʽ
//ȥ��ע�Ͳ��ֺ�ĳ���
//
//��������
//int main() {
//	/*
//	����
//	һ��
//	ע��
//	*/
//	int n;//n��ʾ���ݹ�ģ
//}
//
//�������
//int main() {
//
//	int n;
//}



#define N 100
int main()
{
	char *str = (char*)malloc(N);
	FILE *fp = fopen("data3.txt", "rw");
	fgets(str,N,fp);
	for (size_t i = 0; i< N; ++i)
	{
		if (i < N && str[i] == '/'&&str[i + 1] == '*')
		{
			i += 2;
			while (i < N && str[i] != '*'&&str[i + 1] != '/')++i;
			i += 2;
		}
		else if (i < N && str[i] == '/'&&str[i + 1] == '/')
		{
			while (i < N && str[i] != '\n')++i;
			i += 1;
		}
		else
		{
			printf("%c", str[i]);
		}
	}
	free(str);
	system("pause");
	return 0;
}