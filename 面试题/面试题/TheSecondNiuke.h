#pragma once
#include"DefineNode.h"

//1.1.1.��һ��������Ѱ������������еĳ���  eg. 2 1 6 4 5 2 7 4 �����������2457����1457��������4
// ����һO(NlgN)������һ����������help,��help[0] = v[0],��v[i]��help����Ƚϣ��ҵ���һ����v[i]�����help[index],��
//       help[index]�滻�������û�б�v[i]��ģ���ôֱ�ӽ�v[i]��ӵ�helpĩβ
//������O(N^2)�� ����һ����������help��help[i]�ĺ�������v[i]Ϊĩβ������µ�������г���
#include<vector>
void Find_Maxlength()//O(NlgN)
{
	//1.��������Ԫ�ظ�����������������Ԫ��
	//2.����һ����������help��������������help���в���
	size_t n; cin >> n;//�������ݵĸ���
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	vector<int> help; help.push_back(v[0]);//help[j]�ĺ����Ǵ��������ԭ�����i������ʱ�򳤶�j+1�ĵ�����������Сĩβ
	for (size_t i = 1; i < n; ++i)
	{
		if (v[i]>help[help.size() - 1]){ help.push_back(v[i]); continue; }//�޸���Сĩβ

		int start = 0, end = help.size() - 1, mid;
		while (start <= end)//�ö��ֲ��ҵ�һ����v[i]�����help[j]
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
	size_t n; cin >> n;//�������ݵĸ���
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }
	vector<int> v2(n, 1);//�������飬v2[i]�ĺ�������v[i]Ϊĩβ�ĵ��������еĳ���
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

//1.1.2.һ�Ѷ�Ԫ��[a1,b1],[a2,b2],...[an,bn],�����ݶ�Ԫ�飬Ҫ��ai>ai+1,bi>bi+1��(��ɳ�����⣬leetcode354��)
//  ������(�������:a��С�����ţ���aһ��ʱb�Ӵ�С�ţ�����һ������������b��ֵ)
//        ���ź���֮�󣬿���һ����������help,help����ֻ��b��ֵ�����������������ⷽ��һ��ͬ
struct dou{
	int a;
	int b;
};
struct Com{
	bool operator()(dou i, dou j)
	{
		//if (i.a < j.a)return true;                    //��a��С��������
		//else if (i.a == j.a && i.b > j.b)return true; //��a���ʱ,��b�Ӵ�С����
		//else return false;

		if (i.a == j.a)return i.b > j.b;
		return i.a < j.a;
	}
}Com;
#include<algorithm>
int Find_Maxlength3(vector<dou>& arr)//O(NlgN)
{
	//1.�Ƚ�a��С��������,aֵһ��ʱ����bֵ�Ӵ�С����
	//2.���ٸ�������help��ֻ��b��ֵ
	sort(arr.begin(), arr.end(), Com);//1.

	vector<int> help(1); help[0] = arr[0].b;//2.
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (arr[i].b>help[help.size() - 1]){ help.push_back(arr[i].b); continue; }//�޸���Сĩβ

		int start = 0, end = help.size() - 1, mid;
		while (start <= end)//�ö��ֲ��ҵ�һ����v[i]�����help[j]
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

//1.1.3.��Ŀ��������һ����ŷǸ����������飬�󰼽�ȥ�ĵط���װ����ˮ
//  ��������ͷָ�����⣬��������[0,1,0,2,1,0,1,3,2,1,2,1]
void Water()
{
	size_t n; cin >> n;//�������ݵĸ�����
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	//���������i��λ�õĴ�ˮ��
	int left = v[0], right = v[n - 1];//���Ž⣺left����������ֵ��right�����Ҳ����ֵ
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
	size_t n; cin >> n;//�������ݵĸ���
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	//���������i��λ�õĴ�ˮ��
	vector<int> vl(n), vr(n);//vl[i]���������ߵ�iλ�õ����ֵ��vr[i]�����iλ�õ����ұߵ����ֵ
	//ps:�Ż���������һ����������vl(n)���飬��Ϊǰ�涼��������֪������iλ�õ����ֵ
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

//1.1.4.��һ���洢�Ǹ��������飬��������֮��Χ�ɵ���������ֵ��
//    eg.2 1 6 4 5 2 7 4Χ�ɵ����ֵ��18����ͷָ�����⣩������ߵ�2<���ұߵ�4����ôΧ�ɵ������2*5=10
void SurroudArea()
{
	size_t n; cin >> n;//�������ݵĸ���
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


//2.1.1��һ��������Ѱ������������͡�eg. 3 -2 1 -5 4 -2 3 6 -1 ���������������4-2+3+6=11
//    ����������������val,max;
void Find_MaxArr()
{
	size_t n; cin >> n;//�������ݵĸ���
	if (n < 1)return;//���������û��Ԫ�أ�ֱ�ӷ���
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	int max = v[0]; val = v[0];
	for (size_t i = 1; i < n; ++i)
	{
		val = val < 0 ? 0 : val;//ȷ��val�Ǳ�����������
		val += v[i];
		if (val > max) max = val;//max����ԭ����[0,i]��Χ�ڵ����������Ӻ�
	}
	cout << max;
}

//2.1.2��һ��δ�������飬���԰������ֳ����ܶ������飬�ҳ������������ݵ������飬ʹ������������ļӺ����
void Find_MaxArrTwo()//3 -2 1 -5 4 -2 3 6 -1
{
	size_t n; cin >> n;//�������ݵĸ���
	if (n < 2)return;//���������Ԫ�ظ���С��2����ô�����������������ݵ������飬ֱ�ӷ���
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }

	vector<int> vl(n);//vl[i]����ԭ����[0,i]��Χ�ڵ�����������Ӻ�   ps:�Ż�ʱ������һ��������¼
	vector<int> vr(n);//vr[i]����ԭ����(i,n-1]��Χ�ڵ�����������Ӻ�
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

//2.1.3��һ���洢�Ǹ�����δ�������飬����һ��kֵ������ļӺ�Ϊk�������飬������ĳ��ȣ�˫ָ�����⣩
void Find_Length()
{
	size_t n; cin >> n;//�������ݵĸ���
	if (n < 1)return;//���������û��Ԫ�أ�ֱ�ӷ���
	vector<int> v(n); int val;
	for (size_t i1 = 0; i1 < n; ++i1){ cin >> val; v[i1] = val; }
	cout << "������kֵΪ��"; cin >> val;/////////////////

	int i = -1, j = 0, len = 0, sum = v[0];

	while (j < n)
	{
		if (sum == val)len = len < j - i ? j - i : len;

		if (sum <= val){ ++j; if (j < n)sum += v[j]; }
		else { ++i; sum -= v[i]; }
	}
	cout << len;
}
//4.3.1��һ�������ɸ������δ�����������ۼӺ�Ϊ������ֵ���������ϵ������
//1������һ����������arr������Ԫ�ؿ����ɸ����㣬����һ������k����arr�������������ۼӺ͵���k��������鳤��
//2������һ����������arr������Ԫ�ؿ����ɸ����㣬��arr�����������������븺��������ȵ�������鳤��  (��������Ϊ1,������Ϊ-1,����ֵ0��������鳤��)
//3������һ����������arr����������Ԫ��ֻ��0��1����arr������������0��1������ȵ�������鳤��  ����0�ĳ�-1������ֵ0��������鳤�ȣ�
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
//��һ�������ɸ������δ�����������ۼӺ�С�ڵ��ڸ�����ֵ���������ϵ������
//4.3.2����һ����������arr������Ԫ�ؿ����ɸ����㣬����һ������k����arr�������������ۼӺ�С�ڻ����k��������鳤��
int Find_length3(vector<int>& v,int k)
{
	if (v.size() < 1)return 0;

	vector<int>help(v.size() + 1);//help��һ�������ĵ�������
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
		if (sum <= k){ maxlength = i + 1; continue; }//��һ��ܹؼ�

		int left = 0, right = help.size() - 1;
		while (left < right)//�ҵ���һ�����ڵ���target����
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


//3.1.1��һ����ά������Ѱ���Ӿ�������͡�eg. 3 -2  1 -5 4 
//                                        1  2 -3 -4 5 ��a[2][1]+a[2][2]+a[3][1]+a[3][2] = 13��
//                                       -2  3  6 -1 2
//                                       -3  6 -2 -3 -3 ���Ӿ����������13
int Find_Maxsum(int arr[][5], const int M, const int N)
{
	int val, max = arr[0][0];//���������ռ�

	for (int i = 0; i < M; ++i)
	{
		vector<int> arr2(N, 0);//һ����������
		for (int j = i; j < M; ++j)
		{
			for (size_t a = 0; a < N; ++a){ arr2[a] += arr[j][a]; }val = arr2[0];

			for (int k = 1; k < N; ++k)
			{
				//if (max < 0 && val < 0)//����������ȫΪ����������������������������ݶ�Ϊ��������ô����ִ�����漸�仰��
				//{max = max<val ? val>arr2[k] ? val : arr2[k] : max; val = arr2[k]; continue;}

				val = val < 0 ? 0 : val;//��ֹ��������������Ϊ���������������������ȽϺã�
				val += arr2[k];//���������в�ȫ�Ǹ��������
				//val = val < 0 ? 0 : val;//�����ۼӺ��val����Ǹ���������
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

//��һ���洢�Ǹ��������飬�ҵ������������������ıȸ�����(С)��ֵ���Ҳ���������ıȸ�����(С)��ֵ
//3.1.4��һ���洢�Ǹ��������飬����ÿ����Ϊ��������������eg.2 1 6 4 5 2 7 4��������12
//�����2Ϊ�������εĳ�Ϊ1����ô�����2�������1Ϊ�������εĳ�Ϊ8����ô�����8
#include<stack>
int Surroud_Area(vector<int>& v)
{
	v.push_back(0);//�ⲽ�ܹؼ����������ж�ѹһ���㣬��ô����Ĳ����ܱ�֤ջ���

	size_t max = 0; stack<size_t> help;//һ��ջά�ִ�ջ�׵�ջ�����εݼ�
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


//4.1.4ֻ�õݹ麯��ʵ��һ��ջ��������ʾ:��Ϊ�ݹ���ջ�ǵȼ۵ģ������ȿ��Ǽ���������һ��ջʱ������ô����


//4.1.5ʵ�ּ���������ı��ʽ���㣬������С����
//�ٿ�����Ϊ�������ַ���һ������ȷ�ı��ʽ��������Ҫ��str����ʽ��Ч�Լ��
//������Ǹ���������Ҫ������������������"4*(-3)"�������������Ϊ��ʽ�Ŀ�ͷ�����Ų��ֵĿ�ͷ��
//  �����û�����ţ�����"-3*4"��"(-3*4)"���ǺϷ��ġ�
//�۲��ÿ��Ǽ�������лᷢ������������
//�������˼��:���õݹ麯�������С���ŶԱ��ʽ��Ӱ�죬���������š�
//              ���������ž͸��Լ����ӹ��̣������������žͷ�����һ���н�������±��ӻظ��ϲ�
//             �ڲ��ҳ˳��ڽ�����֮ǰ�ͽ��㣩
#include<ctype.h>
#include<queue>
int AddSum(queue<int>& qu)//����ֻ�мӼ�������
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
int Expression(char *str, int& index)//������мӼ��˳������ŵ�����ת��Ϊֻ�мӼ�������
{
	if (!str || str[index] == 0)return 0;

	queue<int> qu;
	if (str[index] == '-')//�����һ����
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

//4.2.2���ɴ������ֵ����
//����Ŀ����һ����������arr��һ����СΪw�Ĵ��ڴ����������߻������ұߣ�����ÿ�����ұ߻�һ��λ�á�
//	���磬����Ϊ[4,3,5,4,3,3,6,7]��
//		���ڴ�СΪ3ʱ��[435]43367
//		���������ֵΪ54[354]3367
//		���������ֵΪ543[543]367
//		���������ֵΪ5435[433]67
//		���������ֵΪ44354[336]7
//		���������ֵΪ643543[367]
//		���������ֵΪ7������鳤��Ϊn�����ڴ�СΪw����һ������n-w+1�����ڵ����ֵ��
//		��ʵ��һ�����������룺��������arr�����ڴ�СΪw��
//		�����һ������Ϊn-w+1������res��res[i]��ʾÿһ�ִ���״̬�µ����ֵ��
//		�Ա���Ϊ�������Ӧ�÷���{5,5,5,4,6,7}
#include<vector>
#include<deque>
vector<int> GetMaxWindow(vector<int>& arr, size_t k)
{
	if (arr.size() <= k)
		return vector<int>();

	size_t left = 0, right = 0;
	int first_max_index = 0;
	for (right = 1; right < k; ++right)//�����ҵ���һ�����ڵ����ֵ�±�
	{
		if (arr[first_max_index] <= arr[right])
			first_max_index = right;
	}
	deque<int> de; de.push_back(first_max_index);
	vector<int> dst; dst.push_back(arr[de.front()]);

	for (; right < arr.size(); ++right)//������ָ��ֱ������һλ���Ա�֤���ڴ�С����[left,right)
	{
		if (de.front() < ++left)//�ж϶�ǰ�洢���±��Ƿ����
			de.pop_front();

		while (!de.empty() && arr[de.back()] <= arr[right])//�ҵ����ʵĲ���λ��
			de.pop_back();
		de.push_back(right);

		dst.push_back(arr[de.front()]);//��ǰ��Ԫ����Զ���Ǵ������ֵ
	}
	return dst;
}
void test_GetMaxWindow()
{
	vector<int> arr = { 4, 3, 5, 4, 3, 3, 6, 7 };
	vector<int> dst = GetMaxWindow(arr, 3);
	for (auto&r : dst){ cout << r << " "; }cout << endl;
}

//5.2.1 maxtree(����ҵ������������Ҳ���������ı����������ps��ջά�ֵ�����ݼ�)
//һ�������MaxTree�������¡��������û���ظ�Ԫ�ء�MaxTree��һ�ö������������ÿһ��ֵ��Ӧһ���������ڵ㡣
//����MaxTree�������������е�ÿһ�������ϣ�ֵ���Ľڵ㶼������ͷ������һ��û���ظ�Ԫ�ص�����arr��
//д��������������MaxTree�ĺ�����Ҫ��������鳤��ΪN����ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�ΪO(N)��
#include<stack>
TreeThreeLinkNode *MaxTree(vector<int> &arr)
{
	vector<TreeThreeLinkNode *> dst(arr.size());
	for (size_t i = 0; i < arr.size(); ++i)
		dst[i] = new TreeThreeLinkNode(arr[i]);

	stack<TreeThreeLinkNode *> sta;
	for (size_t i = 0; i < dst.size(); ++i)
	{
		while (!sta.empty() && sta.top()->val < dst[i]->val)//����Ԫ��ʱ������
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
		sta.push(dst[i]);//ÿ��Ԫ�ض�ֻ��ջһ��
	}

	TreeThreeLinkNode *head = NULL;
	while (!sta.empty())//����ʱ����
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

//5.2.2�Ҵ������ֵ����Сֵ��ps:ά��˫�˶��е�����ݼ���
//���ֵ��ȥ��СֵС�ڻ����num������������
//����Ŀ����������arr������num���������ж��ٸ��������������������max(arr[i..j]) - min(arr[i..j]) <= num
//max(arr[i..j])��ʾ������arr[i..j]�е����ֵ��
//min(arr[i..j])��ʾ������arr[i..j]�е���Сֵ��
//��Ҫ��������鳤��ΪN����ʵ��ʱ�临�Ӷ�ΪO(N)�Ľⷨ��
#include<deque>
int NumberSubarr(vector<int> &arr, int target)
{
	if (arr.size() <= 0)return 0;

	deque<int> mindeq, maxdeq;
	size_t left = 0, right = 0, count = 0;
	while (right < arr.size())
	{
		while (!mindeq.empty() && arr[mindeq.back()] >= arr[right])//�ҵ����ʵĲ���λ��
			mindeq.pop_back();
		mindeq.push_back(right);//�ö��ж�ͷ�洢������Сֵ

		while (!maxdeq.empty() && arr[maxdeq.back()] <= arr[right])//�ҵ����ʵĲ���λ��
			maxdeq.pop_back();
		maxdeq.push_back(right);//�ö��ж�ͷ�洢�������ֵ

		if (arr[maxdeq.front()] - arr[mindeq.front()] <= target){
			++right;
			count += right - left;
		}else{
			++left;
			if (left > right)right = left;//��֤right���Ǵ��ڵ���left���ܹؼ�

			if (mindeq.front() < left)//�ж϶�ǰ�洢���±��Ƿ����
				mindeq.pop_front();
			if (maxdeq.front() < left)//�ж϶�ǰ�洢���±��Ƿ����
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

//6.2.1�ж�һ�������Ƿ�Ϊ���Ľṹ
//����Ŀ������һ�������ͷ�ڵ�head�����жϸ������Ƿ�Ϊ���Ľṹ��
//���磺1->2->1������true��1->2->2->1������true��15->6->15������true��1->2->3������false��
#include<stack>
bool test1(FlistNode*head)//�����head��û�п�
{
	std::stack<int> s;//����һ:��Ҫ����n���ռ�
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
	std::stack<int> s2;//������:��Ҫ����n/2���ռ�
	FlistNode *slow = head, *fast = head;
	while (fast->next){
		slow = slow->next;//��ָ����һ��
		fast = fast->next; if (fast->next)fast = fast->next;//��ָ��������
	}
	while (slow->next){//����ָ��ָ��Ԫ�صĺ�һ����㿪ʼһֱѹջ
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
	FlistNode *slow2 = head, *fast2 = head; bool flag = false;//������,ֻ��Ҫ����ָ�����
	while (fast2->next){
		slow2 = slow2->next;//��ָ����һ��
		fast2 = fast2->next; if (fast2->next)fast2 = fast2->next;//��ָ��������
	}
	FlistNode *prev = nullptr, *cur = slow2, *next = cur->next;//��ָ�����
	while (cur){
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	prev = head, next = fast2;
	while (prev && next){//�ж��ǲ��ǻ���
		if (prev->val == next->val){ prev = prev->next; next = next->next; }
		else break;
	}
	if (!(prev && next))flag = true;
	prev = nullptr; cur = fast2; next = cur->next;
	while (cur){//���ָ��Ļ���
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	return flag;
}

//6.2.2���ƺ������ָ��ڵ������ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�O(1)
RondomListNode* test2(RondomListNode *head)
{
	if (!head)return NULL;//ͷ����ǿ�ֱ�ӷ���

	RondomListNode *cur = head, *next = head->next;//�ɢ٢ڢ۱�ɢ٢٢ڢڢۣۢ������Ƴ����Ľ������ָ�붼ָ���
	while (cur){
		RondomListNode *tmp = new RondomListNode(cur->val);
		cur->next = tmp; tmp->next = next;
		cur = next; if (next)next = next->next;
	}
	cur = head; next = cur->next;//�����ָ��ָ����ȷ��λ��
	while (cur){
		next->rand = cur->rand ? cur->rand->next : NULL;
		cur = next->next; if (cur)next = cur->next;
	}
	cur = head; next = cur->next;//���¾�������뿪
	RondomListNode *tmp = next;
	while (cur){
		cur->next = next->next; cur = next->next;
		if (cur){ next->next = cur->next; next = cur->next; }
		else next->next = NULL;
	}
	return tmp;//���ظ��Ƴ������������ͷ���
}

//6.2.3�����������ཻ��һϵ������
//����Ŀ���ڱ����У�����������л���Ҳ�����޻������������������ͷ�ڵ�head1��head2����������������ཻ��
//Ҳ���ܲ��ཻ����ʵ��һ��������������������ཻ���뷵���ཻ�ĵ�һ���ڵ㣻������ཻ������null���ɡ�
//��Ҫ���������1�ĳ���ΪN������2�ĳ���ΪM��ʱ�临�Ӷ���ﵽO(N + M)������ռ临�Ӷ���ﵽO(1)
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
		FlistNode *cur1 = pHead1, *cur2 = pHead2;//������cur1����ָ�򳤵������ȼ���pHead1�Ƚϳ�
		while (cur1 != end){ count1++; cur1 = cur1->next; }
		while (cur2 != end){ count2++; cur2 = cur2->next; }

		if (count1 < count2){ cur1 = pHead2; cur2 = pHead1; }
		else{ cur1 = pHead1; cur2 = pHead2; }

		for (int i = 0; i < abs(count1 - count2); ++i)//��cur1���߼���
			cur1 = cur1->next;

		while (cur1 != end){
			if (cur1 == cur2)return cur1;

			cur1 = cur1->next; cur2 = cur2->next;
		}
		return NULL;
	}
	FlistNode* FindFirstCommonNode(FlistNode* pHead1, FlistNode* pHead2) {
		if (!pHead1 || !pHead2)return NULL;//�п�

		bool flag1 = IsCycle(pHead1);
		bool flag2 = IsCycle(pHead2);

		if ((flag1 == true && flag2 == false) || (flag1 == false && flag2 == true))//����һ������������һ��������
			return NULL;
		else if (flag1 == false && flag2 == false)//������������
		{
			return FindCommonNode(pHead1, pHead2, NULL);
		}
		else//����������
		{
			//1.���������ཻ  2.�������ڻ����ཻ  3.�������ڻ����ཻ
			FlistNode *enter1 = FindEnterNode(pHead1);
			FlistNode *enter2 = FindEnterNode(pHead2);

			if (enter1 == enter2)//���2
			{
				return FindCommonNode(pHead1, pHead2, enter1->next);
			}
			else//���1�����3
			{
				FlistNode *tmp = enter1->next;
				while (tmp != enter2)//̽���ǲ������3
				{
					if (tmp == enter1)return NULL;//˵�������1
					tmp = tmp->next;
				}
				//���ߵ����˵���������3
				return enter1;//����return enter2;
			}
		}
	}
};
//7.1.1��һ�ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㡣
TreeNode *_TreeToLink(TreeNode *root)
{
	if (!root)return NULL;//�ݹ鷵������

	TreeNode *left = _TreeToLink(root->left);//left����ߵ������������
	TreeNode *right = _TreeToLink(root->right);//right���ұߵ������������

	TreeNode *left_to_right;//��ߵ���������ҽ��
	left_to_right = left ? left->left : NULL;
	TreeNode *right_to_right;//�ұߵ���������ҽ��
	right_to_right = right ? right->left : NULL;

	root->left = left_to_right;//��������
	if (left_to_right)left_to_right->right = root;
	root->right = right;//�����Һ���
	if (right)right->left = root;

	if (!left)left = root;
	left->left = right ? right_to_right : root;

	return left;
}
TreeNode *TreeToLink(TreeNode *root)//�ݹ�˼·
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
	head4->left = head3; head4->right = head6;//��
	head3->left = head1;//������
	head1->right = head2;
	head6->left = head5; head6->right = head8;//������
	head8->left = head7;

	TreeNode *head = TreeToLink(head4);
	TreeNode *cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->right;
	}cout << endl;
}

//7.1.2 ɾ���������е�һ����β�ڵ�
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

//7.1.3 KMP�㷨
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

//7.2.4�ж�һ�����ǲ�����һ����������

void test_SecondNiuke()
{
	//Find_Maxlength();//1 Ѱ�������������
	//Find_Maxlength2();//1
	//test_112();//1 �ݶ�Ԫ������(��ɳ������)
	//Water();//1 ���鰼��װˮ����
	//Water2();//1
	//SurroudArea();//1 ������������֮��Χ�ɵ�������

	//Find_MaxArr();//2 Ѱ������������
	//Find_MaxArrTwo();//2 �ҳ������������ݵ������飬ʹ������������ļӺ����
	//Find_Length();//2 �ڷǸ������У�����ļӺ�Ϊk��������ĳ���
	//test_Find_length3();//2 �ڿ����ɸ����������У�����ļӺ�Ϊk��������ĳ���

	//test_Find_Maxsum();//3 ��ά������Ѱ���Ӿ��������
	//test_Surroud_Area();//3 �ڷǸ��������ҵ������������������ıȸ���С��ֵ���Ҳ���������ıȸ���С��ֵ

	//4��ûд�� ֻ�õݹ麯��ʵ��һ��ջ������
	//test_expression();//4 ���ʽ����
	//test_GetMaxWindow(); //4 �������⣨��ͷ��β��˫�˶���ά�ֵݼ���

	//test_MaxTree();//5 MaxTree���⣨�ӵ׵�����ջά�ֵݼ���
	//test_NumberSubarr();//5 ���ֵ��ȥ��СֵС�ڻ����num������������(�������У�һ��ά�ֵ�����һ���ݼ�)

	//6 �ж�һ�������Ƿ�Ϊ���Ľṹ
	//6 ���ƺ������ָ��ڵ������
	//6 �����������ཻ��һϵ������

	//test_TreeToLink();//7 ��һ�ö���������ת����һ�������˫������
	//test_linklist();//7 ɾ���������е�һ����β�ڵ�
	test_Problem_KMP();//7 KMP�㷨
	//7 �ж�һ�����ǲ�����һ����������
}


//8.1.1 �õݹ�ͷǵݹ鷽ʽ���ֱ��ն�������������ͺ����ӡ���еĽڵ㡣
//      ����Լ�����������˳��Ϊ�������ң��������˳��Ϊ�󡢸����ң��������˳��Ϊ���ҡ�����


//8.2.2�ҵ��������е����������������
//    ����һ�ö�������ͷ�ڵ� head����֪�������нڵ��ֵ����һ�����ҵ����нڵ���������������
//    �������������������ͷ�ڵ㡣Ҫ������ڵ���Ϊ N��Ҫ��ʱ�临�Ӷ�Ϊ O(N


//8.2.3�������ڵ�������������
//     �Ӷ������Ľڵ� A �������������ϻ��������ߣ�����;�Ľڵ�ֻ�ܾ���һ�Σ�������ڵ� B ʱ��·
//     ���ϵĽڵ������� A �� B �ľ��롣���������Ͻڵ��������롣
//      Ҫ������������Ľڵ���Ϊ N��ʱ�临�Ӷ�Ҫ��Ϊ O(N)


//8.2.4��ν�Ϊֱ�۵ش�ӡ������
//    �����������ó�������ֱ��������������ṹ�����ǲ���ֱ�ۣ������Ƕ����������ظ�ֵ��ʱ��
//    ��ͨ�����ֱ����Ľ�����������������ʵ�ṹ�������ϼ��ѣ���ʱ����������ܡ�����һ�ö�����
//    ��ͷ�ڵ� head����֪�������ڵ�ֵ������Ϊ 32 λ���ͣ���ʵ��һ����ӡ�������ĺ���������ֱ��
//    ��չʾ������״��Ҳ���ڻ�����ʵ�Ľṹ��
//    ˵����ƽʱ��ϰ����������Ŀ��������Ҫһ�������ĺ����԰ɣ��������Է���Ĳ鿴�������֮������Ӱ������Ժú�������


//8.2.5�ڶ��������ҵ��ۼӺ�Ϊָ��ֵ���·������
//    ����һ�ö�������ͷ�ڵ� head ��һ�� 32 λ���� sum���������ڵ�ֵ����Ϊ���ͣ����ۼӺ�Ϊ sum
//    ���·�����ȡ�·����ָ��ĳ���ڵ����£�ÿ�����ѡ��һ�����ӽڵ���߲�ѡ���γɵĽڵ�����
//    ����ռ临�Ӷ�Ϊ O(h)��h Ϊ�������ĸ߶ȡ�


//9.1.1ֻ���������е�ĳ���ڵ� node����ʵ�ַ��� node �ĺ�̽ڵ�ĺ�����(ע��,�ö����������ָ�򸸽ڵ��ָ��)
//     ��̽ڵ㣺�ڶ���������������������У�node ����һ���ڵ���� node �ĺ�̽ڵ㡣

//9.1.2�������������񼶷���������һ�ö�������ͷ�ڵ� head����ɶ���������������ͺ��������
//    ����������Ľڵ���Ϊ N��Ҫ��ʱ�临�Ӷ�Ϊ O(N)������ռ临�Ӷ�Ϊ O(1)

//9.2.3�ҵ��������з�������������������������˽ṹ������һ�ö�������ͷ�ڵ� head����֪���нڵ��ֵ����һ����
//       �����������ġ��ҷ����������������������˽ṹ�Ľڵ�����
//   ��������˽ṹ��ָ��������ڶ�����������ѡ��ĳЩ�ڵ㣬ֻҪ��Щ�ڵ�������һ��ģ������������������˽ṹ��


//10.1.1�����ӡһ����������ÿ���ӡ���Ҫ���У�������ӡ��һ�㡣
//  ����һ������������     ����������һ�����кͼ������޵ı���

//10.1.2�ж�һ�����Ƿ���ƽ���������ע�⣬�����ж�ƽ��������������

//10.1.3�ж�һ���������ǲ�����ȫ������
//    ����һ:��ջ            ������:�ö���(��һ�������������,�϶����ǣ��ڰ���ʱ,һ������������һ���������,��ô�������Ľ�����ΪҶ�ӽ��) 

//10.1.4��֪һ��������������������㻥����λ�ã����ҳ���������㲢����������1.��val��2.����㣩

//10.2.5��¡�������Ľ���
//����ϣ�������ĸ��ص�:��������������Ģ�����������޵Ģ���ͬ����,��ͬ�������ͬ����,������ͬ����ܴ�����������ʱ,�������������
//10.2.6һ���Թ�ϣ


//11.1.1��ֽ���⣺���һ��ֽ�����ŷ��������ϣ�Ȼ���ֽ�����±����Ϸ����� 1 �Σ�ѹ���ۺۺ�
//          չ������ʱ�ۺ��ǰ���ȥ�ģ����ۺ�ͻ��ķ���ָ��ֽ���ı��档�����ֽ����
//          �±����Ϸ��������� 2 �Σ�ѹ���ۺۺ�չ������ʱ�������ۺۣ����ϵ���������
//         ���ۺۡ����ۺۺ����ۺۡ�����һ��������� N������ֽ��û�ζ����±����Ϸ�
//         �������� N �Σ�����ϵ��´�ӡ�����ۺ۵ķ���


//11.1.2��ת�ַ���:����һ���ַ����͵����� chas ��һ������ size����Ѵ�СΪ size ������������Ƶ��Ұ�����
//       �Ұ��������Ƶ���ߡ�
//      ����:����� chas �����ַ���Ϊ"ABCDE"��size = 3��������"DEABC"��
//      Ҫ��:��� chas ����Ϊ N�������ⶼҪ��ʱ�临�Ӷ�Ϊ O(N)������ռ临�Ӷ�Ϊ O(1)
// ����һ:�ø�������  ������:��������     ������:�齻��

//11.1.3������С�ڵ����ٴ��ڵ��ڵĵ���������ϴ�����⣩
//�������� arr���뽫��������� a <= b >= c <= d >= e <= f...������
//��������
//arr = { 3, 1, 2 }
//����֮��arr ������{ 1, 3, 2 }. 1 <= 3 >= 2
//����֮��arr Ҳ������{ 2, 3, 1 }. 2 <= 3 >= 1
//arr = { 3, 1, 2, 6 }
//����֮��arr ������{ 1, 6, 2, 3 }. 1 <= 6 >= 2 <= 3
//����֮��arr Ҳ������{ 3, 6, 1, 2 }. 3 <= 6 >= 1 <= 2
//��Ҫ��
//1����� arr ����Ϊ N��Ҫ��ʱ�临�Ӷ�Ϊ O(N)������ռ临�Ӷ�Ϊ O(1)��
//2��arr ���ܻ᲻ֹһ�ֵ�����������ֻҪ����Ҫ�󼴿ɡ�


//11.2.4���������ҵ��� k С����
//       Ҫ��:��� arr ����Ϊ N��Ҫ��ʱ�临�Ӷ�Ϊ O(N)������ռ临�Ӷ�Ϊ O(1)��


//12.1.1���ַ�����ĩβ����ַ�ʹ�����嶼�ǻ��Ĵ�
//����һ���ַ��� str����ͨ������ַ��ķ�ʽʹ�� str ���嶼��ɻ����ַ�������Ҫ��ֻ���� str ��ĩβ����ַ�����
//������ str ������ӵ�����ַ�����
//��������
//str = "12"����ĩβ���"1"֮��str ��Ϊ"121"���ǻ��Ĵ�����ĩβ���"21"֮��str ��Ϊ"1221"��Ҳ�ǻ��Ĵ���
//��"1"��������ӷ�������̵ģ����Է���"1"��
//��Ҫ��
//��� str �ĳ���Ϊ N����ʵ��ʱ�临�Ӷ� O(N)�ķ���


//12.1.2�ҵ��ַ���������ظ��ַ��Ӵ�
//����һ���ַ��� str������ str ������ظ��ַ��Ӵ��ĳ��ȡ�
//��������
//str = "abcd"������ 4
//str = "aabcb"������ظ��ַ��Ӵ�Ϊ"abc"������ 3��
//��Ҫ��
//��� str �ĳ���Ϊ N����ʵ��ʱ�临�Ӷ�Ϊ O(N)�ķ�����



//12.1.3ƴ�������ַ��������ֵ�˳����С�Ĵ��ַ���
//����һ���ַ������͵����� strs�����ҵ�һ��ƴ��˳��ʹ�ý����е��ַ���ƴ��������ɵĴ��ַ��������п�������
//�ֵ�˳����С�ģ�������������ַ�����
//��������
//strs = ["abc"��"de"]������ƴ��"abcde"��Ҳ����ƴ��"deabc"����ǰ�ߵ��ֵ�˳���С�����Է���"abcde"��
//strs = ["b"��"ba"]������ƴ��"bba"��Ҳ����ƴ��"bab"�������ߵ��ֵ�˳���С�����Է���"bab"��
//��Ҫ��
//��� str �ĳ���Ϊ N����ʵ��ʱ�临�Ӷ� O(N*logN)�ķ���



//12.2.4��С�����Ӵ��ĳ���
//�����ַ��� str1 �� str2���� str1 ���Ӵ��к��� str2 �����ַ�����С�Ӵ����ȡ�
//��������
//str1 = "abcde"��str2 = "ac"����Ϊ"abc"���� str2 �������ַ���������������һ������ str1 �������Ӵ��У�"abc"����
//�̵ģ����� 3��
//str1 = "12345"��str2 = "344"����С�����Ӵ������ڣ����� 0��
//��Ҫ��
//��� str1 �ĳ���Ϊ N��str2 �ĳ���Ϊ M����ʵ��ʱ�临�Ӷ� O(N)�ķ�����


//13.1.1��������ַ�ʹ�ַ������嶼�ǻ����ַ���
//����һ���ַ��� str����������� str ������λ������ַ����뷵��������ַ����ٵ�����£��� str
//���嶼�ǻ����ַ�����һ�ֽ����
//��������
//str = "ABA"��str ������ǻ��Ĵ�������Ҫ����ַ������Է���"ABA"��
//str = "AB"��������'A'֮ǰ���'B'��ʹ str ���嶼�ǻ��Ĵ����ʿ��Է���"BAB"��Ҳ������'B'֮����
//��'A'��ʹ str ���嶼�ǻ��Ĵ�����Ҳ���Է���"ABA"����֮��ֻҪ��ӵ��ַ������٣�ֻ��������
//һ�ֽ�����ɡ�

//13.1.2��������������еõ����嶼�ǻ����ַ�����һ�ֽ��
//����һ���ַ��� str���ٸ��� str ��������������ַ��� strlps���뷵��������ַ����ٵ�����£�
//�� str ���嶼�ǻ����ַ�����һ�ֽ������Ŀ������Ŀһ����һ��������������ʱ�临�Ӷȱ�ԭ����
//��ʵ�ֵ͡�
//��������
//str = "A1B21C"��strlps = "121"������"AC1B2B1CA"����"CA1B2B1AC"����֮��ֻҪ�����
//���ַ������٣�ֻ��������һ�ֽ�����ɡ�

//13.2.3�����ַ�������Ч�Ժ����Ч����
//����һ���ַ��� str���ж��ǲ���������Ч�������ַ�����
//��������
//str = "()"������ true��str = "(()())"������ true��str = "(())"������ true��
//str = "())"������ false��str = "()("������ false��str = "()a()"������ false��

//13.2.4�����Ч�����Ӵ�
//����һ�������ַ��� str�����������Ч�����Ӵ���
//��������
//str = "(()())"������ 6��str = "())"������ 2��str = "()(()()("������ 4��


//14.0.1�������� N������쳲��������еĵ� N �
//��������Ŀ 1��
//�������� N������̨������һ�ο��Կ� 2 ������ 1 ��̨�ף������ж������߷���
//��������
//N = 3���������ζ��� 1 ��̨�ף�Ҳ�����ȿ� 2 ��̨�ף��ٿ� 1 ��̨�ף��������ȿ� 1 ��̨�ף��ٿ� 2 ��̨�ס���������
//���߷������� 3��
//��������Ŀ 2��
//����ũ���г����ĸţÿ��ֻ���� 1 ͷСĸţ��������Զ����������һ��ũ���� 1 ֻ�����ĸţ���ӵڶ��꿪ʼ��ĸţ
//��ʼ��Сĸţ��ÿֻСĸţ 3 ��֮������ֿ�����Сĸţ���������� N����� N ���ţ������

//14.1.2��Ǯ�����ٻ�����
//����Ŀ��
//�������� arr��arr �����е�ֵ��Ϊ�����Ҳ��ظ���ÿ��ֵ����һ����ֵ�Ļ��ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ��ٸ�
//��һ������ aim ����Ҫ�ҵ�Ǯ��������� aim �����ٻ�������
//��������
//arr = [5, 2, 3]��aim = 20��
//4 �� 5 Ԫ������� 20 Ԫ����������Ǯ������Ҫʹ�ø����ŵĻ��ң����Է��� 4��
//arr = [5, 2, 3]��aim = 0��
//�����κλ��ҾͿ������ 0 Ԫ������ 0��
//arr = [3, 5]��aim = 2��
//�����޷���� 2 Ԫ��Ǯ�����ҿ��������Ĭ�Ϸ��� - 1��
//��������Ŀ��
//�������� arr��arr �����е�ֵ��Ϊ������ÿ��ֵ������һ��Ǯ����ֵ���ٸ���һ������ aim ����Ҫ�ҵ�Ǯ��������� aim
//�����ٻ�������
//��������
//arr = [5, 2, 3]��aim = 20��
//5 Ԫ��2 Ԫ�� 3 Ԫ��Ǯ���� 1 �ţ������޷���� 20 Ԫ��Ĭ�Ϸ��� - 1��
//arr = [5, 2, 5, 3]��aim = 10��
//5 Ԫ�Ļ����� 2 �ţ�������� 10 Ԫ���Ҹ÷��������������٣����� 2��
//arr = [5, 2, 5, 3]��aim = 15��
//���е�Ǯ������������� 15 Ԫ������ 4��
//arr = [5, 2, 5, 3]��aim = 0��
//�����κλ��ҾͿ������ 0 Ԫ������ 0��

//һ�����������������
//����Ŀ��
//���������ַ��� str1 �� str2�����������ַ���������������С�
//��������
//str1 = "1A2C3D4B56"��str2 = "B1D23CA45B6A"��
//"123456"����"12C4B6"��������������У�������һ�����С�

//����������Ӵ�����
//����Ŀ��
//���������ַ��� str1 �� str2�����������ַ�����������Ӵ���
//��������
//str1 = "1AB2345CD"��str2 = "12345EF"������"2345"��
//��Ҫ��
//��� str1 ����Ϊ M��str2 ����Ϊ N��ʵ��ʱ�临�Ӷ�Ϊ O(MN)������ռ临�Ӷ�Ϊ O(1)�ķ�����

//������С�༭����
//����Ŀ��
//���������ַ��� str1 �� str2���ٸ����������� ic��dc �� rc���ֱ������롢ɾ�����滻һ���ַ��Ĵ��ۣ����ؽ� str1
//�༭�� str2 ����С���ۡ�
//��������
//str1 = "abc"��str2 = "adc"��ic = 5��dc = 3��rc = 2��
//��"abc"�༭��"adc"����'b'�滻��'d'�Ǵ�����С�ģ����Է��� 2��
//str1 = "abc"��str2 = "adc"��ic = 5��dc = 3��rc = 100��
//��"abc"�༭��"adc"����ɾ��'b'��Ȼ�����'d'�Ǵ�����С�ģ����Է��� 8��
//str1 = "abc"��str2 = "abc"��ic = 5��dc = 3��rc = 2��
//���ñ༭�ˣ���������һ�����ַ��������Է��� 0

//�ġ��ų�һ���ߵ�ֽ�Ʋ�������
//����Ŀ��
//����һ���������� arr��������ֵ��ͬ��ֽ���ų�һ���ߡ���� A ����� B ��������ÿ��ֽ�ƣ��涨��� A ���ã����
//B ���ã�����ÿ�����ÿ��ֻ��������������ҵ�ֽ�ƣ���� A ����� B �������������뷵������ʤ�ߵķ�����
//��������
//arr = [1, 2, 100, 4]��
//��ʼʱ��� A ֻ������ 1 �� 4�������� A ���� 1�������б�Ϊ[2, 100, 4]����������� B �������� 2 �� 4��Ȼ�������
//����� A�������ʼʱ��� A ���� 4�������б�Ϊ[1, 2, 100]����������� B �������� 1 �� 100��Ȼ������ֵ���� A��
//��� A ��Ϊ�����������˲������� 4����Ϊ�� 4 ֮����� B ������ 100��������� A ������ 1�������б�Ϊ[2, 100, 4]��
//��������� B ������ôѡ��100 ���ᱻ��� A ���ߡ���� A ���ʤ������Ϊ 101�����Է��� 101��
//arr = [1, 100, 2]��
//��ʼʱ��� A ������ 1 ���� 2����� B ��Ϊ�����������ˣ������ 100 ���ߡ���� B ���ʤ������Ϊ 100�����Է���
//100��