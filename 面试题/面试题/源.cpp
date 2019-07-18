#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

//注意，尽量只包含下面的一个头文件，否则可能会有相同的函数名
//#include"test_offer.h"
//#include"daily_bite.h"
//#include"LinkList.h"
//#include"Niuke.h"
//#include"TheSecondNiuke.h"
//#include"daily_bite2.h"
//#include"Coding.h"

//2.给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集
//1.给定一个不包含重复元素的整数数组 nums，返回该数组所有可能的子集
#include<vector>
class Solution {
public:
	//可以直接从前往后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
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


#include"完美世界游戏cplus开发.h"

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