#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include"GetMinStack.h"
//#include"Queue_by_TwoStack.h"
//#include"Stack_by_TwoQueue.h"
#include"ReverseStack.h"


//��һ��ջʵ����һ��ջ������
#include<stack>
void StackSort_byotherStack(stack<int> &s)
{
	stack<int> help;
	while (!s.empty()){
		int cur = s.top(); s.pop();
		while (!help.empty() && cur > help.top()){
			s.push(help.top());help.pop();
		}
		help.push(cur);
	}
	while (!help.empty()){
		s.push(help.top()); help.pop();
	}
}

////���ɴ������ֵ����
//#include<vector>
//#include<deque>//���������˵����⣬d.pop_back()��d.pop_front()������ɾ���Ǹ�Ԫ��
//void Window_MaxArr()
//{
//	int val; cin >> val;//�����������
//	vector<int> v(val);
//	for (size_t i = 0; i < v.size(); ++i){//������������Ԫ�� eg.2 1 6 4 5 2 7 4
//		cin >> val; v[i] = val;
//	}
//
//	vector<int> v2;deque<int> d;//v2����Ҫ���ɵ����ֵ���飬d�Ǹ���˫�˶���
//	cin >> val;//���봰�ڴ�С
//	if (v.size() == 0 || val < 1 || v.size() < val)return;//�ж������Ƿ�Ϸ�
//
//	for (size_t i = 0; i < v.size(); ++i){
//		while (!d.empty() && v[i] >= d.back())d.pop_back();
//		d.push_back(i);
//		if (d.back() - d.front() >= val)d.pop_front();
//		if (d.front() >= val - 1)v2.push_back(v[d.front()]);
//	}
//
//	for (size_t i = 0; i < v2.size(); ++i){//��ӡ�������ֵ����
//		cout << v2[i] << " ";
//	}
//}


//�ҵ�һ���������λ��

int main()
{
	//test_GetMinStack();
	//test_Queue_By_TwoStack();
	//testStackBytwoQueue();
	//test_ReverseStack();
	//Window_MaxArr();//����

	system("pause");
	return 0;
}