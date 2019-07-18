#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include"GetMinStack.h"
//#include"Queue_by_TwoStack.h"
//#include"Stack_by_TwoQueue.h"
#include"ReverseStack.h"


//用一个栈实现另一个栈的排序
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

////生成窗口最大值数组
//#include<vector>
//#include<deque>//这个程序出了点问题，d.pop_back()和d.pop_front()到底是删除那个元素
//void Window_MaxArr()
//{
//	int val; cin >> val;//输入数组个数
//	vector<int> v(val);
//	for (size_t i = 0; i < v.size(); ++i){//依次输入数组元素 eg.2 1 6 4 5 2 7 4
//		cin >> val; v[i] = val;
//	}
//
//	vector<int> v2;deque<int> d;//v2是需要生成的最大值数组，d是辅助双端队列
//	cin >> val;//输入窗口大小
//	if (v.size() == 0 || val < 1 || v.size() < val)return;//判断数据是否合法
//
//	for (size_t i = 0; i < v.size(); ++i){
//		while (!d.empty() && v[i] >= d.back())d.pop_back();
//		d.push_back(i);
//		if (d.back() - d.front() >= val)d.pop_front();
//		if (d.front() >= val - 1)v2.push_back(v[d.front()]);
//	}
//
//	for (size_t i = 0; i < v2.size(); ++i){//打印生成最大值数组
//		cout << v2[i] << " ";
//	}
//}


//找到一个数组的中位数

int main()
{
	//test_GetMinStack();
	//test_Queue_By_TwoStack();
	//testStackBytwoQueue();
	//test_ReverseStack();
	//Window_MaxArr();//出错

	system("pause");
	return 0;
}