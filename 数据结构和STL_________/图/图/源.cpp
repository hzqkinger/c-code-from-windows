#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

#include"Graph_arr.h"//�ڽӾ�������ͼ������ͼ������������������
#include"adjacency_li.h"//�ڽӱ��ڽӱ���ͼ��һ����ʽ�洢�ṹ������ͼ������ͼ��

//����������δ���
#include"OrthogonalList.h"//ʮ������������ͼ��һ����ʽ�洢�ṹ
#include"AdjacencyMultilist.h"//�ڽӶ��ر�������ͼ��һ����ʽ�洢�ṹ

int main()
{
	//test();//�����ڽӾ���
	test2();//�����ڽӱ�
	system("pause");
	return 0;
}