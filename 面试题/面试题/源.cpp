#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

//ע�⣬����ֻ���������һ��ͷ�ļ���������ܻ�����ͬ�ĺ�����
//#include"test_offer.h"
//#include"daily_bite.h"
//#include"LinkList.h"
//#include"Niuke.h"
//#include"TheSecondNiuke.h"
//#include"daily_bite2.h"
//#include"Coding.h"

//2.����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ�
//1.����һ���������ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ�
#include<vector>
class Solution {
public:
	//����ֱ�Ӵ�ǰ�������������һ�����Ͱ������Ӽ����ϸ�������µ��Ӽ���������ϼ��������Ӽ�
	vector<vector<int>> subsets(vector<int> & nums) {
		vector<vector<int>> res;
		res.push_back({});

		for (int var : nums) {
			int n = res.size();
			for (int j = 0; j < n; ++j) {
				res.push_back(res[j]);
				res.back().push_back(var);
			}
		}
		return res;
	}
};
void TEST()
{
	Solution s;
	vector<int> nums = { 1, 2, 3 };
	vector<vector <int> > res = s.subsets(nums);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
}


#include"����������Ϸcplus����.h"

int main()
{
	TEST();

	//test_offer();
	//test_daily_bite();
	//test_LinkList();
	//test_SecondNiuke();
	//test_coding();
	//test_daily_bite2();

	//testwmsj();
	system("pause");
	return 0;
}