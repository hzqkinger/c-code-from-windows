#pragma once

#include<queue>
//template<class T,class con = vector<T>,class compare = less<class con::valuetype> > class priority_queue
void test_prio_queue()//less����˼�Ǻ���С��˫��
{
	priority_queue<int> pqu;//���ȼ����У��ײ�����õĶ�����˼�룩Ĭ�Ͻ����

	pqu.push(10);
	pqu.push(19);
	pqu.push(14);
	pqu.push(15);
	pqu.push(18);
	pqu.push(17);
	pqu.push(16);
	pqu.push(13); 

	cout << pqu.size() << endl;
	cout << pqu.empty() << endl;
	cout << pqu.top() << endl;

	priority_queue<int> pqu2;
	pqu2 = pqu;

	while (!pqu.empty())//���ȼ�����Ĭ�ϲ��ý�������
	{
		cout << pqu.top() << " ";
		pqu.pop();
	}
	cout << endl << endl;;


	cout << pqu2.size() << endl;
	cout << pqu2.empty() << endl;
	cout << pqu2.top() << endl;
	while (!pqu2.empty())//���ȼ�����Ĭ�ϲ��ý�������
	{
		cout << pqu2.top() << " ";
		pqu2.pop();
	}
	cout << endl;


	priority_queue<int,vector<int>,Great<int>> pqu3;//���ȼ����У��ײ�����õĶ�����˼�룩

	pqu3.push(10);//Great����˼�Ǻ��Ӵ���˫��
	pqu3.push(19);
	pqu3.push(14);
	pqu3.push(15);
	pqu3.push(18);
	pqu3.push(17);
	pqu3.push(16);
	pqu3.push(13);
	while (!pqu3.empty())
	{
		cout << pqu3.top() << " ";
		pqu3.pop();
	}
	cout << endl;
}