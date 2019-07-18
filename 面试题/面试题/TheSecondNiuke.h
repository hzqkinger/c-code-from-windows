#pragma once
#include"DefineNode.h"

//1.1.1.在一个数组中寻找最长递增子序列的长度  eg. 2 1 6 4 5 2 7 4 的最长子序列是2457或者1457，长度是4
// 方法一O(NlgN)：开辟一个辅助数组help,令help[0] = v[0],用v[i]与help数组比较，找到第一个比v[i]大的数help[index],把
//       help[index]替换掉，如果没有比v[i]大的，那么直接将v[i]添加到help末尾
//方法二O(N^2)： 开辟一个辅助数组help，help[i]的含义是以v[i]为末尾的情况下的最长子序列长度
#include<vector>
void Find_Maxlength()//O(NlgN)
{
	//1.输入数组元素个数，依次输入数组元素
	//2.开辟一个辅助数组help，用上述方法对help进行操作
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	vector<int> help; help.push_back(v[0]);//help[j]的含义是代表遍历到原数组第i个数的时候长度j+1的递增子序列最小末尾
	for (size_t i = 1; i < n; ++i)
	{
		if (v[i]>help[help.size() - 1]){ help.push_back(v[i]); continue; }//修改最小末尾

		int start = 0, end = help.size() - 1, mid;
		while (start <= end)//用二分查找第一个比v[i]大的数help[j]
		{
			mid = start + (end - start) / 2;
			if (help[mid] <= v[i])
				start = mid + 1;
			else
				end = mid - 1;
		}
		help[mid] = v[i];
	}
	cout << help.size() << endl;
}
void Find_Maxlength2()//O(N^2)
{
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }
	vector<int> v2(n, 1);//辅助数组，v2[i]的含义是以v[i]为末尾的递增子序列的长度
	for (size_t i = 1; i < n; ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (v[i]>v[j]){ v2[i] = v2[i] <= v2[j] ? v2[j] + 1 : v2[i]; }
		}
	}
	val = v2[0];
	for (size_t i = 1; i < n; ++i){ val = val < v2[i] ? v2[i] : val; }
	cout << val;
}

//1.1.2.一堆二元组[a1,b1],[a2,b2],...[an,bn],往上垒二元组，要求ai>ai+1,bi>bi+1。(俄沙皇问题，leetcode354题)
//  方法：(排序策略:a从小到大排，当a一样时b从大到小排；申请一个辅助数组存放b的值)
//        在排好序之后，开辟一个辅助数组help,help里面只存b的值，接下来做法与上题方法一相同
struct dou{
	int a;
	int b;
};
struct Com{
	bool operator()(dou i, dou j)
	{
		//if (i.a < j.a)return true;                    //将a从小到大排序
		//else if (i.a == j.a && i.b > j.b)return true; //当a相等时,将b从大到小排序
		//else return false;

		if (i.a == j.a)return i.b > j.b;
		return i.a < j.a;
	}
}Com;
#include<algorithm>
int Find_Maxlength3(vector<dou>& arr)//O(NlgN)
{
	//1.先将a从小到大排序,a值一样时，将b值从大到小排序
	//2.开辟辅助数组help，只存b的值
	sort(arr.begin(), arr.end(), Com);//1.

	vector<int> help(1); help[0] = arr[0].b;//2.
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (arr[i].b>help[help.size() - 1]){ help.push_back(arr[i].b); continue; }//修改最小末尾

		int start = 0, end = help.size() - 1, mid;
		while (start <= end)//用二分查找第一个比v[i]大的数help[j]
		{
			mid = start + (end - start) / 2;
			if (help[mid] <= arr[i].b)
				start = mid + 1;
			else
				end = mid - 1;
		}
		help[mid] = arr[i].b;
	}
	return help.size();
}
void test_112()
{
	vector<dou> arr = { { 3, 2 }, { 4, 6 }, { 2, 5 }, { 1, 7 }, { 5, 9 }, { 2, 2 }, { 4, 4 }, { 1, 10 }, { 3, 1 }, { 1, 4 } };

	cout << Find_Maxlength3(arr) << endl;
	cout << endl;
}

//1.1.3.题目描述：有一个存放非负整数的数组，求凹进去的地方能装多少水
//  方法：两头指针问题，例如数组[0,1,0,2,1,0,1,3,2,1,2,1]
void Water()
{
	size_t n; cin >> n;//输入数据的个数，
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	//本质是求第i个位置的存水量
	int left = v[0], right = v[n - 1];//最优解：left代表左侧最大值，right代表右侧最大值
	int i = 0, j = n - 1, sum = 0;

	while (i < j)
	{
		if (left < right)
		{
			if (v[i] <= left){ sum += left - v[i]; ++i; }
			else{ left = v[i]; }
		}
		else
		{
			if (v[j] <= right){ sum += right - v[j]; --j; }
			else{ right = v[j]; }
		}
	}
	cout << sum;
}
void Water2()
{
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	//本质是求第i个位置的存水量
	vector<int> vl(n), vr(n);//vl[i]代表从最左边到i位置的最大值，vr[i]代表从i位置到最右边的最大值
	//ps:优化：可以用一个变量代替vl(n)数组，因为前面都遍历过，知道从左到i位置的最大值
	vl[0] = v[0]; vr[n - 1] = v[n - 1]; val = 0;
	for (size_t i = 1; i < n; ++i){
		vl[i] = v[i]>vl[i - 1] ? v[i] : vl[i - 1];
	}
	for (int i = n - 2; i >= 0; --i){
		vr[i] = v[i]>vr[i + 1] ? v[i] : vr[i + 1];
	}
	for (size_t i = 1; i < n - 1; ++i){
		val += vl[i] < vr[i] ? vl[i] - v[i] : vr[i] - v[i];
	}
	cout << val;
}

//1.1.4.有一个存储非负数的数组，求两个数之间围成的面积的最大值。
//    eg.2 1 6 4 5 2 7 4围成的最大值是18（两头指针问题），最左边的2<最右边的4，那么围成的面积是2*5=10
void SurroudArea()
{
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	size_t i = 0, j = n - 1, max = 0;
	while (i < j){
		size_t max2 = (j - i - 1)*(v[i] < v[j] ? v[i] : v[j]);
		max = max < max2 ? max2 : max;
		v[i] < v[j] ? ++i : --j;
	}
	cout << max;
}


//2.1.1在一个数组中寻找子数组的最大和。eg. 3 -2 1 -5 4 -2 3 6 -1 的子数组的最大和是4-2+3+6=11
//    方法：用两个变量val,max;
void Find_MaxArr()
{
	size_t n; cin >> n;//输入数据的个数
	if (n < 1)return;//如果数组中没有元素，直接返回
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	int max = v[0]; val = v[0];
	for (size_t i = 1; i < n; ++i)
	{
		val = val < 0 ? 0 : val;//确定val是保留还是置零
		val += v[i];
		if (val > max) max = val;//max代表原数组[0,i]范围内的最大子数组加和
	}
	cout << max;
}

//2.1.2有一个未排序数组，可以把它划分出来很多子数组，找出来两个不相容的子数组，使这两个子数组的加和最大
void Find_MaxArrTwo()//3 -2 1 -5 4 -2 3 6 -1
{
	size_t n; cin >> n;//输入数据的个数
	if (n < 2)return;//如果数组中元素个数小于2，那么不可能有两个不相容的子数组，直接返回
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	vector<int> vl(n);//vl[i]代表原数组[0,i]范围内的子数组的最大加和   ps:优化时可以用一个变量记录
	vector<int> vr(n);//vr[i]代表原数组(i,n-1]范围内的子数组的最大加和
	val = vl[0] = v[0];
	for (size_t i = 1; i < n; ++i)
	{
		val = val<0 ? 0 : val; val += v[i];
		if (val>vl[i - 1])vl[i] = val; else vl[i] = vl[i - 1];
	}
	val = vr[n - 1] = v[n - 1];
	for (size_t i = n - 2; i > 0; --i)
	{
		val = val < 0 ? 0 : val; val += v[i];
		if (val>vr[i + 1])vr[i] = val; else vr[i] = vr[i + 1];
	}

	val = vl[0] + vr[1];
	for (size_t i = 1; i < n - 1; ++i){ if (val < vl[i] + vr[i + 1])val = vl[i] + vr[i + 1]; }
	cout << val;
}

//2.1.3有一个存储非负数的未排序数组，给定一个k值，求最长的加和为k的子数组，算出它的长度（双指针问题）
void Find_Length()
{
	size_t n; cin >> n;//输入数据的个数
	if (n < 1)return;//如果数组中没有元素，直接返回
	vector<int> v(n); int val;
	for (size_t i1 = 0; i1 < n; ++i1){ cin >> val; v[i1] = val; }
	cout << "给定的k值为："; cin >> val;/////////////////

	int i = -1, j = 0, len = 0, sum = v[0];

	while (j < n)
	{
		if (sum == val)len = len < j - i ? j - i : len;

		if (sum <= val){ ++j; if (j < n)sum += v[j]; }
		else { ++i; sum -= v[i]; }
	}
	cout << len;
}
//4.3.1有一个可正可负可零的未排序数组中累加和为给定定值的最长子数组系列问题
//1、给定一个无序数组arr，其中元素可正可负可零，给定一个整数k，求arr所有子数组中累加和等于k的最长子数组长度
//2、给定一个无序数组arr，其中元素可正可负可零，求arr所有子数组中正数与负数个数相等的最长子数组长度  (把正数改为1,负数改为-1,且求定值0的最长子数组长度)
//3、给定一个无序数组arr，其中数组元素只有0或1，求arr所有子数组中0和1个数相等的最长租数组长度  （把0改成-1，且求定值0的最长子数组长度）
#include<map>
int Find_length2(vector<int>& v, int k)
{
	if (v.size() < 1)return 0;
	map<int, int> mp; mp[0] = -1;

	int sum = 0, maxlength = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		if (mp.count(sum) == 0)mp[sum] = i;
	}
	sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		if (mp.count(sum - k) != 0 && maxlength < i - mp[sum - k])
			maxlength = i - mp[sum - k];
	}
	return maxlength;
}
//有一个可正可负可零的未排序数组中累加和小于等于给定定值的最长子数组系列问题
//4.3.2给定一个无序数组arr，其中元素可正可负可零，给定一个整数k，求arr所有子数组中累加和小于或等于k的最长子数组长度
int Find_length3(vector<int>& v,int k)
{
	if (v.size() < 1)return 0;

	vector<int>help(v.size() + 1);//help是一个辅助的递增数组
	int sum = 0; help[0] = v[0] - 1;
	for (size_t i = 1; i < help.size(); ++i)
	{
		sum += v[i - 1];
		help[i] = help[i - 1] > sum ? help[i - 1] : sum;
	}

	int maxlength = 0; sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		if (sum <= k){ maxlength = i + 1; continue; }//这一句很关键

		int left = 0, right = help.size() - 1;
		while (left < right)//找到第一个大于等于target的数
		{
			int mid = left + (right - left) / 2;
			if (help[mid] >= sum - k)right = mid;
			else left = mid + 1;
		}

		if (i - right > maxlength)maxlength = i - right;
	}
	return maxlength;
}
void test_Find_length3()
{
	vector<int> v = { 3, -1, 2, -1, 4, -2, 4 };
	cout << Find_length2(v, 3) << endl;

	cout << Find_length3(v, 5) << endl;
}


//3.1.1在一个二维数组中寻找子矩阵的最大和。eg. 3 -2  1 -5 4 
//                                        1  2 -3 -4 5 （a[2][1]+a[2][2]+a[3][1]+a[3][2] = 13）
//                                       -2  3  6 -1 2
//                                       -3  6 -2 -3 -3 的子矩阵的最大和是13
int Find_Maxsum(int arr[][5], const int M, const int N)
{
	int val, max = arr[0][0];//两个辅助空间

	for (int i = 0; i < M; ++i)
	{
		vector<int> arr2(N, 0);//一个辅助数组
		for (int j = i; j < M; ++j)
		{
			for (size_t a = 0; a < N; ++a){ arr2[a] += arr[j][a]; }val = arr2[0];

			for (int k = 1; k < N; ++k)
			{
				//if (max < 0 && val < 0)//处理数组中全为负数的情况（假如数组中所有数据都为负数，那么不会执行下面几句话）
				//{max = max<val ? val>arr2[k] ? val : arr2[k] : max; val = arr2[k]; continue;}

				val = val < 0 ? 0 : val;//防止辅助数组第零个数为负数的情况（该语句放在这比较好）
				val += arr2[k];//处理数组中不全是负数的情况
				//val = val < 0 ? 0 : val;//后面累加后的val如果是负数则置零
				if (val>max)max = val;
			}
		}
	}
	return max;
}
void test_Find_Maxsum()
{
	int arr[][5] = { { 3, -2, 1, -5, 4 }, { 1, 2, -3, -4, 5 }, { -2, 3, 6, -1, 2 }, { -3, 6, -2, -3, -3 } };
	cout << Find_Maxsum(arr, 4, 5) << endl;
}

//有一个存储非负数的数组，找到所有数左侧离它最近的比该数大(小)的值和右侧离它最近的比该数大(小)的值
//3.1.4有一个存储非负数的数组，求以每个数为宽的最大矩形面积。eg.2 1 6 4 5 2 7 4最大面积是12
//如果以2为宽，最大矩形的长为1，那么面积是2；如果以1为宽，最大矩形的长为8，那么面积是8
#include<stack>
int Surroud_Area(vector<int>& v)
{
	v.push_back(0);//这步很关键，向数组中多压一个零，那么下面的步骤能保证栈会空

	size_t max = 0; stack<size_t> help;//一个栈维持从栈底到栈顶依次递减
	for (size_t i = 0; i < v.size(); ++i)
	{
		while (!help.empty() && v[i] <= v[help.top()]){
			size_t max2;
			size_t tmp = help.top(); help.pop();
			max2 = v[tmp] * (help.empty() ? i : i - 1 - help.top());
			max = max2>max ? max2 : max;
		}
		help.push(i);
	}
	return max;
}
void test_Surroud_Area()
{
	vector<int> v = { 2, 1, 6, 4, 5, 2, 7 };
	cout << Surroud_Area(v) << endl;
}


//4.1.4只用递归函数实现一个栈的逆序（提示:因为递归与栈是等价的，所以先考虑假如能申请一个栈时该怎那么做）


//4.1.5实现简单四则运算的表达式计算，其中有小括号
//①可以认为给定的字符串一定是正确的表达式，即不需要对str做公式有效性检查
//②如果是负数，就需要用括号括起来，比如"4*(-3)"。但如果负数作为公式的开头或括号部分的开头，
//  则可以没有括号，比如"-3*4"和"(-3*4)"都是合法的。
//③不用考虑计算过程中会发生溢出的情况。
//（左程云思想:①用递归函数处理掉小括号对表达式的影响，即消除括号。
//              遇到左括号就给自己的子过程，当遇到右括号就返回上一层切将结果和下标扔回给上层
//             ②并且乘除在进队列之前就结算）
#include<ctype.h>
#include<queue>
int AddSum(queue<int>& qu)//负责只有加减的运算
{
	int sum, cur;
	if (!qu.empty())
	{
		sum = qu.front();
		qu.pop();
	}
	while (!qu.empty())
	{
		char tmp = qu.front();
		qu.pop();
		cur = qu.front();
		qu.pop();

		tmp == '+' ? sum += cur : sum -= cur;
	}
	return sum;
}
int Expression(char *str, int& index)//负责把有加减乘除和括号的运算转换为只有加减的运算
{
	if (!str || str[index] == 0)return 0;

	queue<int> qu;
	if (str[index] == '-')//处理第一个数
	{
		qu.push(0);
		qu.push(str[index++]);
	}

	int sum,cur;
	while (str[index])
	{
		sum = 0;
		if (str[index] == '(')
			sum = Expression(str, ++index);
		else{
			while (isdigit(str[index]))
				sum = sum * 10 + str[index++] - '0';
		}

		while (str[index] != ')' && (str[index] == '*' || str[index] == '/'))
		{
			cur = 0;
			char tmp = str[index++];
			if (str[index] == '(')
				sum *= Expression(str, ++index);
			else
			{
				while (isdigit(str[index]))
					cur = cur * 10 + str[index++] - '0';
				tmp == '*' ? sum *= cur : sum /= cur;
			}
		}

		qu.push(sum);
		if (str[index] != ')' && (str[index] == '+' || str[index] == '-'))
			qu.push(str[index++]);

		if (str[index] == ')'){ ++index; break; }
	}

	return AddSum(qu);
}
void test_expression()
{
	char *str = "14+(3+6*(-2+15))*4";
	int index = 0;
	cout << Expression(str,index) << endl;
}

//4.2.2生成窗口最大值数组
//【题目】有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置。
//	例如，数组为[4,3,5,4,3,3,6,7]，
//		窗口大小为3时：[435]43367
//		窗口中最大值为54[354]3367
//		窗口中最大值为543[543]367
//		窗口中最大值为5435[433]67
//		窗口中最大值为44354[336]7
//		窗口中最大值为643543[367]
//		窗口中最大值为7如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。
//		请实现一个函数。输入：整型数组arr，窗口大小为w。
//		输出：一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值。
//		以本题为例，结果应该返回{5,5,5,4,6,7}
#include<vector>
#include<deque>
vector<int> GetMaxWindow(vector<int>& arr, size_t k)
{
	if (arr.size() <= k)
		return vector<int>();

	size_t left = 0, right = 0;
	int first_max_index = 0;
	for (right = 1; right < k; ++right)//①先找到以一个窗口的最大值下标
	{
		if (arr[first_max_index] <= arr[right])
			first_max_index = right;
	}
	deque<int> de; de.push_back(first_max_index);
	vector<int> dst; dst.push_back(arr[de.front()]);

	for (; right < arr.size(); ++right)//②左右指针分别向后移一位，以保证窗口大小不变[left,right)
	{
		if (de.front() < ++left)//判断队前存储的下标是否过期
			de.pop_front();

		while (!de.empty() && arr[de.back()] <= arr[right])//找到合适的插入位置
			de.pop_back();
		de.push_back(right);

		dst.push_back(arr[de.front()]);//队前的元素永远都是窗口最大值
	}
	return dst;
}
void test_GetMaxWindow()
{
	vector<int> arr = { 4, 3, 5, 4, 3, 3, 6, 7 };
	vector<int> dst = GetMaxWindow(arr, 3);
	for (auto&r : dst){ cout << r << " "; }cout << endl;
}

//5.2.1 maxtree(如何找到所有数左侧和右侧离它最近的比它大的数，ps：栈维持递增或递减)
//一个数组的MaxTree定义如下。数组必须没有重复元素。MaxTree是一棵二叉树，数组的每一个值对应一个二叉树节点。
//包括MaxTree树在内且在其中的每一棵子树上，值最大的节点都是树的头。给定一个没有重复元素的数组arr，
//写出生成这个数组的MaxTree的函数，要求如果数组长度为N，则时间复杂度为O(N)、额外空间复杂度为O(N)。
#include<stack>
TreeThreeLinkNode *MaxTree(vector<int> &arr)
{
	vector<TreeThreeLinkNode *> dst(arr.size());
	for (size_t i = 0; i < arr.size(); ++i)
		dst[i] = new TreeThreeLinkNode(arr[i]);

	stack<TreeThreeLinkNode *> sta;
	for (size_t i = 0; i < dst.size(); ++i)
	{
		while (!sta.empty() && sta.top()->val < dst[i]->val)//弹出元素时，结算
		{
			TreeThreeLinkNode *tmp = sta.top();
			sta.pop();
			if (!sta.empty() && sta.top()->val < dst[i]->val)
			{
				if (!sta.top()->left)sta.top()->left = tmp;
				else sta.top()->right = tmp;
				tmp->parent = sta.top();
			}
			else{
				if (!dst[i]->left)dst[i]->left = tmp;
				else dst[i]->right = tmp;
				tmp->parent = dst[i];
			}
		}
		sta.push(dst[i]);//每个元素都只入栈一次
	}

	TreeThreeLinkNode *head = NULL;
	while (!sta.empty())//弹出时结算
	{
		head = sta.top();
		sta.pop();
		if (!sta.empty())
		{
			if (!sta.top()->left)sta.top()->left = head;
			else sta.top()->right = head;
			head->parent = sta.top();
		}
	}
	return head;
}
void test_MaxTree()
{
	vector<int> arr = { 6, 4, 3, 5 };
	TreeThreeLinkNode *head = MaxTree(arr);
}

//5.2.2找窗口最大值或最小值（ps:维持双端队列递增或递减）
//最大值减去最小值小于或等于num的子数组数量
//【题目】给定数组arr和整数num，共返回有多少个子数组满足如下情况：max(arr[i..j]) - min(arr[i..j]) <= num
//max(arr[i..j])表示子数组arr[i..j]中的最大值，
//min(arr[i..j])表示子数组arr[i..j]中的最小值。
//【要求】如果数组长度为N，请实现时间复杂度为O(N)的解法。
#include<deque>
int NumberSubarr(vector<int> &arr, int target)
{
	if (arr.size() <= 0)return 0;

	deque<int> mindeq, maxdeq;
	size_t left = 0, right = 0, count = 0;
	while (right < arr.size())
	{
		while (!mindeq.empty() && arr[mindeq.back()] >= arr[right])//找到合适的插入位置
			mindeq.pop_back();
		mindeq.push_back(right);//该队列队头存储窗口最小值

		while (!maxdeq.empty() && arr[maxdeq.back()] <= arr[right])//找到合适的插入位置
			maxdeq.pop_back();
		maxdeq.push_back(right);//该队列队头存储窗口最大值

		if (arr[maxdeq.front()] - arr[mindeq.front()] <= target){
			++right;
			count += right - left;
		}else{
			++left;
			if (left > right)right = left;//保证right总是大于等于left，很关键

			if (mindeq.front() < left)//判断队前存储的下标是否过期
				mindeq.pop_front();
			if (maxdeq.front() < left)//判断队前存储的下标是否过期
				maxdeq.pop_front();
		}
	}
	return count;
}
void test_NumberSubarr()
{
	vector<int> arr = { 4, 6, 3};
	cout << NumberSubarr(arr, 13) << endl;
}

//6.2.1判断一个链表是否为回文结构
//【题目】给定一个链表的头节点head，请判断该链表是否为回文结构。
//例如：1->2->1，返回true。1->2->2->1，返回true。15->6->15，返回true。1->2->3，返回false。
#include<stack>
bool test1(FlistNode*head)//下面对head都没判空
{
	std::stack<int> s;//方法一:需要申请n个空间
	FlistNode *tmp = head;
	while (tmp){
		s.push(tmp->val); tmp = tmp->next;
	}
	tmp = head;
	while (!s.empty() && s.top() == tmp->val){
		s.pop(); tmp = tmp->next;
	}
	return s.empty() ? true : false;
}
bool test11(FlistNode*head)
{
	std::stack<int> s2;//方法二:需要申请n/2个空间
	FlistNode *slow = head, *fast = head;
	while (fast->next){
		slow = slow->next;//慢指针走一步
		fast = fast->next; if (fast->next)fast = fast->next;//快指针走两步
	}
	while (slow->next){//从慢指针指向元素的后一个结点开始一直压栈
		slow = slow->next;
		s2.push(slow->val);
	}
	slow = head;
	while (!s2.empty() && s2.top() == slow->val){
		s2.pop(); slow = slow->next;
	}
	return s2.empty() ? true : false;
}
bool test12(FlistNode *head)
{
	FlistNode *slow2 = head, *fast2 = head; bool flag = false;//方法三,只需要几个指针变量
	while (fast2->next){
		slow2 = slow2->next;//慢指针走一步
		fast2 = fast2->next; if (fast2->next)fast2 = fast2->next;//快指针走两步
	}
	FlistNode *prev = nullptr, *cur = slow2, *next = cur->next;//改指针操作
	while (cur){
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	prev = head, next = fast2;
	while (prev && next){//判断是不是回文
		if (prev->val == next->val){ prev = prev->next; next = next->next; }
		else break;
	}
	if (!(prev && next))flag = true;
	prev = nullptr; cur = fast2; next = cur->next;
	while (cur){//最后将指针改回来
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	return flag;
}

//6.2.2复制含有随机指针节点的链表。时间复杂度为O(N)，额外空间复杂度O(1)
RondomListNode* test2(RondomListNode *head)
{
	if (!head)return NULL;//头结点是空直接返回

	RondomListNode *cur = head, *next = head->next;//由①②③变成①①②②③③，但复制出来的结点的随机指针都指向空
	while (cur){
		RondomListNode *tmp = new RondomListNode(cur->val);
		cur->next = tmp; tmp->next = next;
		cur = next; if (next)next = next->next;
	}
	cur = head; next = cur->next;//将随机指针指向正确的位置
	while (cur){
		next->rand = cur->rand ? cur->rand->next : NULL;
		cur = next->next; if (cur)next = cur->next;
	}
	cur = head; next = cur->next;//将新旧链表分离开
	RondomListNode *tmp = next;
	while (cur){
		cur->next = next->next; cur = next->next;
		if (cur){ next->next = cur->next; next = cur->next; }
		else next->next = NULL;
	}
	return tmp;//返回复制出来的新链表的头结点
}

//6.2.3两个单链表相交的一系列问题
//【题目】在本题中，单链表可能有环，也可能无环。给定两个单链表的头节点head1和head2，这两个链表可能相交，
//也可能不相交。请实现一个函数，如果两个链表相交，请返回相交的第一个节点；如果不相交，返回null即可。
//【要求】如果链表1的长度为N，链表2的长度为M，时间复杂度请达到O(N + M)，额外空间复杂度请达到O(1)
class Solution11 {
public:
	bool IsCycle(FlistNode *head)
	{
		FlistNode *fast = head, *slow = head;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast)fast = fast->next;

			if (fast == slow)return true;
		}
		return false;
	}
	FlistNode* FindEnterNode(FlistNode *head)
	{
		FlistNode *fast = head, *slow = head;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast)fast = fast->next;

			if (fast == slow)break;
		}

		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
	FlistNode *FindCommonNode(FlistNode* pHead1, FlistNode* pHead2, FlistNode *end)
	{
		int count1 = 0, count2 = 0;
		FlistNode *cur1 = pHead1, *cur2 = pHead2;//在这里cur1总是指向长的链表，先假设pHead1比较长
		while (cur1 != end){ count1++; cur1 = cur1->next; }
		while (cur2 != end){ count2++; cur2 = cur2->next; }

		if (count1 < count2){ cur1 = pHead2; cur2 = pHead1; }
		else{ cur1 = pHead1; cur2 = pHead2; }

		for (int i = 0; i < abs(count1 - count2); ++i)//让cur1先走几步
			cur1 = cur1->next;

		while (cur1 != end){
			if (cur1 == cur2)return cur1;

			cur1 = cur1->next; cur2 = cur2->next;
		}
		return NULL;
	}
	FlistNode* FindFirstCommonNode(FlistNode* pHead1, FlistNode* pHead2) {
		if (!pHead1 || !pHead2)return NULL;//判空

		bool flag1 = IsCycle(pHead1);
		bool flag2 = IsCycle(pHead2);

		if ((flag1 == true && flag2 == false) || (flag1 == false && flag2 == true))//其中一个带环，另外一个不带环
			return NULL;
		else if (flag1 == false && flag2 == false)//两个都不带环
		{
			return FindCommonNode(pHead1, pHead2, NULL);
		}
		else//两个都带环
		{
			//1.两个环不相交  2.两个环在环外相交  3.两个环在环内相交
			FlistNode *enter1 = FindEnterNode(pHead1);
			FlistNode *enter2 = FindEnterNode(pHead2);

			if (enter1 == enter2)//情况2
			{
				return FindCommonNode(pHead1, pHead2, enter1->next);
			}
			else//情况1或情况3
			{
				FlistNode *tmp = enter1->next;
				while (tmp != enter2)//探测是不是情况3
				{
					if (tmp == enter1)return NULL;//说明是情况1
					tmp = tmp->next;
				}
				//能走到这里，说明就是情况3
				return enter1;//或者return enter2;
			}
		}
	}
};
//7.1.1将一棵二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点。
TreeNode *_TreeToLink(TreeNode *root)
{
	if (!root)return NULL;//递归返回条件

	TreeNode *left = _TreeToLink(root->left);//left是左边单链表的最左结点
	TreeNode *right = _TreeToLink(root->right);//right是右边单链表的最左结点

	TreeNode *left_to_right;//左边单链表的最右结点
	left_to_right = left ? left->left : NULL;
	TreeNode *right_to_right;//右边单链表的最右结点
	right_to_right = right ? right->left : NULL;

	root->left = left_to_right;//根的左孩子
	if (left_to_right)left_to_right->right = root;
	root->right = right;//根的右孩子
	if (right)right->left = root;

	if (!left)left = root;
	left->left = right ? right_to_right : root;

	return left;
}
TreeNode *TreeToLink(TreeNode *root)//递归思路
{
	if (!root)return NULL;

	TreeNode *head = _TreeToLink(root);
	head->left = NULL;
	return head;
}
void test_TreeToLink()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	head4->left = head3; head4->right = head6;//根
	head3->left = head1;//左子树
	head1->right = head2;
	head6->left = head5; head6->right = head8;//右子树
	head8->left = head7;

	TreeNode *head = TreeToLink(head4);
	TreeNode *cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->right;
	}cout << endl;
}

//7.1.2 删除单链表中的一个非尾节点
void Erase(FlistNode *node)
{
	FlistNode *next = node->next;
	node->val = next->val;
	node->next = node->next;
	delete next;
}
void test_linklist()
{
	FlistNode *cur11 = new FlistNode(1);
	FlistNode *cur12 = new FlistNode(2); cur11->next = cur12;
	FlistNode *cur13 = new FlistNode(3); cur12->next = cur13;
	//Node *cur14 = new Node(3); cur13->_next = cur14;
	FlistNode *cur15 = new FlistNode(2); cur13->next = cur15;
	FlistNode *cur16 = new FlistNode(1); cur15->next = cur16;
	cout << test1(cur11) << endl;
	cout << test11(cur11) << endl;
	cout << test12(cur11) << endl;

	RondomListNode *cur21 = new RondomListNode(1);
	RondomListNode *cur22 = new RondomListNode(2); cur21->next = cur22;
	RondomListNode *cur23 = new RondomListNode(3); cur22->next = cur23;
	RondomListNode *cur24 = new RondomListNode(4); cur23->next = cur24;
	cur21->rand = cur23; cur22->rand = cur24;
	cur23->rand = cur22; cur24->rand = nullptr;
	RondomListNode *head2 = test2(cur21);
}

//7.1.3 KMP算法
int* Get_Next(char *str2)
{
	int len = strlen(str2);
	if (len == 1){ return new int(-1); }

	int *next = new int[len];
	next[0] = -1;
	next[1] = 0;
	for (int i = 2; i < len; ++i)
	{
		if (str2[next[i - 1]] == str2[i - 1])
			next[i] = next[i - 1] + 1;
		else
		{
			int tmp = next[i - 1];
			while (tmp > 0 && str2[next[tmp]] != str2[i - 1])
				tmp = next[tmp];

			next[i] = next[tmp] + 1;
		}
	}
	return next;
}
int Problem_KMP(char *str1, char *str2)
{
	if (!str1 || !str2)return -1;

	int *next = Get_Next(str2);
	int pos1 = 0, pos2 = 0;
	while ( str1[pos1] && str2[pos2])
	{
		if (str1[pos1] == str2[pos2])
			{++pos1; ++pos2;}
		else if (next[pos2] == -1)
			++pos1;
		else
			pos2 = next[pos2];
	}
	delete next;
	return pos2 == strlen(str2) ? pos1 - pos2 : -1;
}
void test_Problem_KMP()
{
	//int *next = Get_Next("abcabd");
	char *str1 = "aaaaaaab";
	char *str2 = "aaab";
	cout << Problem_KMP(str1, str2) << endl;
}

//7.2.4判断一棵树是不是另一棵树的子树

void test_SecondNiuke()
{
	//Find_Maxlength();//1 寻找最长递增子序列
	//Find_Maxlength2();//1
	//test_112();//1 垒二元组问题(俄沙皇问题)
	//Water();//1 数组凹陷装水问题
	//Water2();//1
	//SurroudArea();//1 数组中两个数之间围成的最大面积

	//Find_MaxArr();//2 寻找子数组最大和
	//Find_MaxArrTwo();//2 找出来两个不相容的子数组，使这两个子数组的加和最大
	//Find_Length();//2 在非负数组中，求最长的加和为k的子数组的长度
	//test_Find_length3();//2 在可正可负可零数组中，求最长的加和为k的子数组的长度

	//test_Find_Maxsum();//3 二维数组中寻找子矩阵的最大和
	//test_Surroud_Area();//3 在非负数组中找到所有数左侧离它最近的比该数小的值和右侧离它最近的比该数小的值

	//4（没写） 只用递归函数实现一个栈的逆序
	//test_expression();//4 表达式求结果
	//test_GetMaxWindow(); //4 窗口问题（从头到尾，双端队列维持递减）

	//test_MaxTree();//5 MaxTree问题（从底到顶，栈维持递减）
	//test_NumberSubarr();//5 最大值减去最小值小于或等于num的子数组数量(两个队列，一个维持递增，一个递减)

	//6 判断一个链表是否为回文结构
	//6 复制含有随机指针节点的链表
	//6 两个单链表相交的一系列问题

	//test_TreeToLink();//7 将一棵二叉搜索树转换成一个排序的双向链表。
	//test_linklist();//7 删除单链表中的一个非尾节点
	test_Problem_KMP();//7 KMP算法
	//7 判断一棵树是不是另一棵树的子树
}


//8.1.1 用递归和非递归方式，分别按照二叉树先序、中序和后序打印所有的节点。
//      我们约定：先序遍历顺序为根、左、右；中序遍历顺序为左、根、右；后序遍历顺序为左、右、根。


//8.2.2找到二叉树中的最大搜索二叉子树
//    给定一棵二叉树的头节点 head，已知其中所有节点的值都不一样，找到含有节点最多的搜索二叉子
//    树，并返回这棵子树的头节点。要求：如果节点数为 N，要求时间复杂度为 O(N


//8.2.3二叉树节点间的最大距离问题
//     从二叉树的节点 A 出发，可以向上或者向下走，但沿途的节点只能经过一次，当到达节点 B 时，路
//     径上的节点数叫作 A 到 B 的距离。求整棵树上节点间的最大距离。
//      要求：如果二叉树的节点数为 N，时间复杂度要求为 O(N)


//8.2.4如何较为直观地打印二叉树
//    二叉树可以用常规的三种遍历结果来描述其结构，但是不够直观，尤其是二叉树中有重复值的时候，
//    仅通过三种遍历的结果来构造二叉树的真实结构更是难上加难，有时则根本不可能。给定一棵二叉树
//    的头节点 head，已知二叉树节点值的类型为 32 位整型，请实现一个打印二叉树的函数，可以直观
//    地展示树的形状，也便于画出真实的结构。
//    说明：平时练习二叉树的题目，起码需要一个这样的函数对吧，这样可以方便的查看你调整树之后的样子啊。所以好好练练。


//8.2.5在二叉树中找到累加和为指定值的最长路径长度
//    给定一棵二叉树的头节点 head 和一个 32 位整数 sum，二叉树节点值类型为整型，求累加和为 sum
//    的最长路径长度。路径是指从某个节点往下，每次最多选择一个孩子节点或者不选所形成的节点链。
//    额外空间复杂度为 O(h)，h 为二叉树的高度。


//9.1.1只给二叉树中的某个节点 node，请实现返回 node 的后继节点的函数。(注意,该二叉树结点有指向父节点的指针)
//     后继节点：在二叉树的中序遍历的序列中，node 的下一个节点叫作 node 的后继节点。

//9.1.2遍历二叉树的神级方法：给定一棵二叉树的头节点 head，完成二叉树的先序、中序和后序遍历。
//    如果二叉树的节点数为 N，要求时间复杂度为 O(N)，额外空间复杂度为 O(1)

//9.2.3找到二叉树中符合搜索二叉树条件的最大拓扑结构：给定一棵二叉树的头节点 head，已知所有节点的值都不一样，
//       返回其中最大的、且符合搜索二叉树条件的拓扑结构的节点数。
//   这里的拓扑结构是指，你可以在二叉树中任意选择某些节点，只要这些节点是连在一起的，都叫做二叉树的拓扑结构。


//10.1.1按层打印一个二叉树，每层打印完后要换行，继续打印下一层。
//  方法一：用两个队列     方法二：用一个队列和几个有限的变量

//10.1.2判断一棵树是否是平衡二叉树（注意，不是判断平衡搜索二叉树）

//10.1.3判断一个二叉树是不是完全二叉树
//    方法一:用栈            方法二:用队列(①一个结点有右无左,肯定不是；②按层时,一个结点有左无右或无左无右,那么接下来的结点必须为叶子结点) 

//10.1.4已知一个搜索二叉树中两个结点互换了位置，请找出这两个结点并调换过来（1.换val；2.换结点）

//10.2.5布隆过滤器的讲解
//（哈希函数的四个特点:①输入域是无穷的②输出域是有限的③相同输入,相同输出；不同输入,可能相同输出④大量数据输入时,均匀命中输出域）
//10.2.6一致性哈希


//11.1.1折纸问题：请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折 1 次，压出折痕后
//          展开。此时折痕是凹下去的，即折痕突起的方向指向纸条的背面。如果从纸条的
//          下边向上方连续对折 2 次，压出折痕后展开，此时有三条折痕，从上到下依次是
//         下折痕、下折痕和上折痕。给定一个输入参数 N，代表纸条没次都从下边向上方
//         连续对折 N 次，请从上到下打印所有折痕的方向


//11.1.2旋转字符串:给定一个字符类型的数组 chas 和一个整数 size，请把大小为 size 的左半区整体移到右半区，
//       右半区整体移到左边。
//      举例:如果把 chas 看作字符串为"ABCDE"，size = 3，调整成"DEABC"。
//      要求:如果 chas 长度为 N，两道题都要求时间复杂度为 O(N)，额外空间复杂度为 O(1)
// 方法一:用辅助数组  方法二:调整三次     方法三:块交换

//11.1.3数组先小于等于再大于等于的调整（完美洗牌问题）
//给定数组 arr，请将数组调整成 a <= b >= c <= d >= e <= f...的样子
//【举例】
//arr = { 3, 1, 2 }
//调整之后，arr 可以是{ 1, 3, 2 }. 1 <= 3 >= 2
//调整之后，arr 也可以是{ 2, 3, 1 }. 2 <= 3 >= 1
//arr = { 3, 1, 2, 6 }
//调整之后，arr 可以是{ 1, 6, 2, 3 }. 1 <= 6 >= 2 <= 3
//调整之后，arr 也可以是{ 3, 6, 1, 2 }. 3 <= 6 >= 1 <= 2
//【要求】
//1，如果 arr 长度为 N，要求时间复杂度为 O(N)，额外空间复杂度为 O(1)。
//2，arr 可能会不止一种调整方案，但只要满足要求即可。


//11.2.4在数组中找到第 k 小的数
//       要求:如果 arr 长度为 N，要求时间复杂度为 O(N)，额外空间复杂度为 O(1)。


//12.1.1在字符串的末尾添加字符使得整体都是回文串
//给定一个字符串 str，想通过添加字符的方式使得 str 整体都变成回文字符串，但要求只能在 str 的末尾添加字符，请
//返回在 str 后面添加的最短字符串。
//【举例】
//str = "12"。在末尾添加"1"之后，str 变为"121"，是回文串。在末尾添加"21"之后，str 变为"1221"，也是回文串。
//但"1"是所有添加方案中最短的，所以返回"1"。
//【要求】
//如果 str 的长度为 N，请实现时间复杂度 O(N)的方法


//12.1.2找到字符串的最长无重复字符子串
//给定一个字符串 str，返回 str 的最长无重复字符子串的长度。
//【举例】
//str = "abcd"，返回 4
//str = "aabcb"，最长无重复字符子串为"abc"，返回 3。
//【要求】
//如果 str 的长度为 N，请实现时间复杂度为 O(N)的方法。



//12.1.3拼接所有字符串产生字典顺序最小的大字符串
//给定一个字符串类型的数组 strs，请找到一种拼接顺序，使得将所有的字符串拼接起来组成的大字符串是所有可能性中
//字典顺序最小的，并返回这个大字符串。
//【举例】
//strs = ["abc"，"de"]，可以拼成"abcde"，也可以拼成"deabc"，但前者的字典顺序更小，所以返回"abcde"。
//strs = ["b"，"ba"]，可以拼成"bba"，也可以拼成"bab"，但后者的字典顺序更小，所以返回"bab"。
//【要求】
//如果 str 的长度为 N，请实现时间复杂度 O(N*logN)的方法



//12.2.4最小包含子串的长度
//给定字符串 str1 和 str2，求 str1 的子串中含有 str2 所有字符的最小子串长度。
//【举例】
//str1 = "abcde"，str2 = "ac"。因为"abc"包含 str2 的所有字符，并且在满足这一条件的 str1 的所有子串中，"abc"是最
//短的，返回 3。
//str1 = "12345"，str2 = "344"。最小包含子串不存在，返回 0。
//【要求】
//如果 str1 的长度为 N，str2 的长度为 M，请实现时间复杂度 O(N)的方法。


//13.1.1添加最少字符使字符串整体都是回文字符串
//给定一个字符串 str，如果可以在 str 的任意位置添加字符，请返回在添加字符最少的情况下，让 str
//整体都是回文字符串的一种结果。
//【举例】
//str = "ABA"。str 本身就是回文串，不需要添加字符，所以返回"ABA"。
//str = "AB"。可以在'A'之前添加'B'，使 str 整体都是回文串，故可以返回"BAB"。也可以在'B'之后添
//加'A'，使 str 整体都是回文串，故也可以返回"ABA"。总之，只要添加的字符数最少，只返回其中
//一种结果即可。

//13.1.2根据最长回文子序列得到整体都是回文字符串的一种结果
//给定一个字符串 str，再给定 str 的最长回文子序列字符串 strlps，请返回在添加字符最少的情况下，
//让 str 整体都是回文字符串的一种结果。题目二比题目一多了一个参数，请做到时间复杂度比原问题
//的实现低。
//【举例】
//str = "A1B21C"，strlps = "121"，返回"AC1B2B1CA"或者"CA1B2B1AC"。总之，只要是添加
//的字符数最少，只返回其中一种结果即可。

//13.2.3括号字符串的有效性和最长有效长度
//给定一个字符串 str，判断是不是整体有效的括号字符串。
//【举例】
//str = "()"，返回 true；str = "(()())"，返回 true；str = "(())"，返回 true。
//str = "())"。返回 false；str = "()("，返回 false；str = "()a()"，返回 false。

//13.2.4最长的有效括号子串
//给定一个括号字符串 str，返回最长的有效括号子串。
//【举例】
//str = "(()())"，返回 6；str = "())"，返回 2；str = "()(()()("，返回 4。


//14.0.1给定整数 N，返回斐波那契数列的第 N 项。
//【补充题目 1】
//给定整数 N，代表台阶数，一次可以跨 2 个或者 1 个台阶，返回有多少种走法。
//【举例】
//N = 3，可以三次都跨 1 个台阶；也可以先跨 2 个台阶，再跨 1 个台阶；还可以先跨 1 个台阶，再跨 2 个台阶。所以有三
//种走法，返回 3。
//【补充题目 2】
//假设农场中成熟的母牛每年只会生 1 头小母牛，并且永远不会死。第一年农场有 1 只成熟的母牛，从第二年开始，母牛
//开始生小母牛。每只小母牛 3 年之后成熟又可以生小母牛。给定整数 N，求出 N 年后牛的数量

//14.1.2换钱的最少货币数
//【题目】
//给定数组 arr，arr 中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给
//定一个整数 aim 代表要找的钱数，求组成 aim 的最少货币数。
//【举例】
//arr = [5, 2, 3]，aim = 20。
//4 张 5 元可以组成 20 元，其他的找钱方案都要使用更多张的货币，所以返回 4。
//arr = [5, 2, 3]，aim = 0。
//不用任何货币就可以组成 0 元，返回 0。
//arr = [3, 5]，aim = 2。
//根本无法组成 2 元，钱不能找开的情况下默认返回 - 1。
//【补充题目】
//给定数组 arr，arr 中所有的值都为正数。每个值仅代表一张钱的面值，再给定一个整数 aim 代表要找的钱数，求组成 aim
//的最少货币数。
//【举例】
//arr = [5, 2, 3]，aim = 20。
//5 元、2 元和 3 元的钱各有 1 张，所以无法组成 20 元，默认返回 - 1。
//arr = [5, 2, 5, 3]，aim = 10。
//5 元的货币有 2 张，可以组成 10 元，且该方案所需张数最少，返回 2。
//arr = [5, 2, 5, 3]，aim = 15。
//所有的钱加起来才能组成 15 元，返回 4。
//arr = [5, 2, 5, 3]，aim = 0。
//不用任何货币就可以组成 0 元，返回 0。

//一、最长公共子序列问题
//【题目】
//给定两个字符串 str1 和 str2，返回两个字符串的最长公共子序列。
//【举例】
//str1 = "1A2C3D4B56"，str2 = "B1D23CA45B6A"。
//"123456"或者"12C4B6"都是最长公共子序列，返回哪一个都行。

//二、最长公共子串问题
//【题目】
//给定两个字符串 str1 和 str2，返回两个字符串的最长公共子串。
//【举例】
//str1 = "1AB2345CD"，str2 = "12345EF"，返回"2345"。
//【要求】
//如果 str1 长度为 M，str2 长度为 N，实现时间复杂度为 O(MN)，额外空间复杂度为 O(1)的方法。

//三、最小编辑代价
//【题目】
//给定两个字符串 str1 和 str2，再给定三个整数 ic、dc 和 rc，分别代表插入、删除和替换一个字符的代价，返回将 str1
//编辑成 str2 的最小代价。
//【举例】
//str1 = "abc"，str2 = "adc"，ic = 5，dc = 3，rc = 2。
//从"abc"编辑成"adc"，把'b'替换成'd'是代价最小的，所以返回 2。
//str1 = "abc"，str2 = "adc"，ic = 5，dc = 3，rc = 100。
//从"abc"编辑成"adc"，先删除'b'，然后插入'd'是代价最小的，所以返回 8。
//str1 = "abc"，str2 = "abc"，ic = 5，dc = 3，rc = 2。
//不用编辑了，本来就是一样的字符串，所以返回 0

//四、排成一条线的纸牌博弈问题
//【题目】
//给定一个整型数组 arr，代表数值不同的纸牌排成一条线。玩家 A 和玩家 B 依次拿走每张纸牌，规定玩家 A 先拿，玩家
//B 后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家 A 和玩家 B 都绝顶聪明。请返回最后获胜者的分数。
//【举例】
//arr = [1, 2, 100, 4]。
//开始时玩家 A 只能拿走 1 或 4。如果玩家 A 拿走 1，则排列变为[2, 100, 4]，接下来玩家 B 可以拿走 2 或 4，然后继续轮
//到玩家 A。如果开始时玩家 A 拿走 4，则排列变为[1, 2, 100]，接下来玩家 B 可以拿走 1 或 100，然后继续轮到玩家 A。
//玩家 A 作为绝顶聪明的人不会先拿 4，因为拿 4 之后，玩家 B 将拿走 100。所以玩家 A 会先拿 1，让排列变为[2, 100, 4]，
//接下来玩家 B 不管怎么选，100 都会被玩家 A 拿走。玩家 A 会获胜，分数为 101。所以返回 101。
//arr = [1, 100, 2]。
//开始时玩家 A 不管拿 1 还是 2，玩家 B 作为绝顶聪明的人，都会把 100 拿走。玩家 B 会获胜，分数为 100。所以返回
//100。