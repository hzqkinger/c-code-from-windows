#pragma once

#include<vector>
/*
*vector迭代器的失效：①插入时，只要没有增容就不会导致迭代器失效
*                    ②删除时，会导致所有的迭代器都失效
*list迭代器的失效：
*/
void test()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int>::iterator it = v.begin();
	auto it2 = ++it;
	//v.erase(it);
	cout << *it2 << endl;
}