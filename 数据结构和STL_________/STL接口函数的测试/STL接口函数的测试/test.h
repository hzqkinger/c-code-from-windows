#pragma once

#include<vector>
/*
*vector��������ʧЧ���ٲ���ʱ��ֻҪû�����ݾͲ��ᵼ�µ�����ʧЧ
*                    ��ɾ��ʱ���ᵼ�����еĵ�������ʧЧ
*list��������ʧЧ��
*/
void test()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int>::iterator it = v.begin();
	auto it2 = ++it;
	//v.erase(it);
	cout << *it2 << endl;
}