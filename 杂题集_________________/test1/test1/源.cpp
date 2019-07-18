#include <iostream>
using namespace std;
#include <assert.h>

//void test(int arr[], int len)
//{
//	assert(arr && len > 0);
//	bool flag = false;
//	int count = 0;
//	int count1 = 0;
//	int count2 = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] % 2 == 0 && arr[i] != 0)
//			count2++;
//		if (arr[i] % 2 == 1)
//		{
//			if (arr[i] == 1)
//				count++;
//			else
//				count1++;
//		}
//	}
//	if (count > 0 && count1 == 0 && count2 == 0 && count1 == 0)
//		cout << count << endl;
//	else if ((count1 == 1 && count2 > 0 && count == 0) || (count1 == 0 && count2 > 0 && count == 0))
//		cout << 1 << endl;
//	else
//		cout << 0 << endl;
//}
//
//
//int main()
//{
//	char s[1000] = { '0' };
//	cin >> s;
//	int arr[26] = { 0 };
//	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++)
//	{
//		arr[s[i] - 'a']++;
//	}
//	test(arr, sizeof(arr)/sizeof(arr[0]));
//	return 0;
//}
