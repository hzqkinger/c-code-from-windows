#pragma once

#include<stack>

//�ж�Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�
//�磺��ջ�����У�1, 2, 3, 4, 5������ջ����Ϊ��4, 5, 3, 2, 1���ǺϷ����У�
//    ��ջ�����У�1, 2, 3, 4, 5������ջ����Ϊ��1, 5, 3, 2, 4���ǲ��Ϸ�����

bool Islegal(int *arr1,int *arr2,size_t n1,size_t n2)
{
	if (n1 == n2)
	{
		size_t i = 0, j = 0;
		stack<int> s1;

		while (i<n1)
		{
			while (s1.empty() || s1.top() != arr2[j])
			{
				s1.push(arr1[i++]);
			}
			while (!s1.empty() && s1.top() == arr2[j])
			{
				s1.pop();
				j++;
			}
		}
		if (s1.empty())
			return true;
	}
	return false;
}

void testIslegal()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	//int arr2[] = { 4, 5, 3, 2, 1 };
	int arr2[] = { 1, 5, 3, 2, 4 };

	size_t n1 = sizeof(arr1) / sizeof(arr1[0]);
	size_t n2 = sizeof(arr2) / sizeof(arr2[0]);

	cout << Islegal(arr1, arr2, n1, n2) << endl;
}