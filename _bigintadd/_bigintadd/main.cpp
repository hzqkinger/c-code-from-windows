#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

//���ʹ����������
//   left="89498464896131684846865"
// +  right="84848984568489484654555555555555555555548948"
//----------------------------------------------------------------

#include<string>
string addstrings(string num1, string num2)
{
	if (num1.size() < num2.size())//ȷ��num1�ǽϳ����ַ���
		swap(num1, num2);

	int left = num1.size() - 1, right = num2.size() - 1;//left�ǳ��ģ�right�Ƕ̵�
	int flag = 0;//��λ��־
	while (left >= 0)
	{
		if (right >= 0)
			num1[left] += num2[right]-'0' + flag;
		else num1[left] += flag;

		if (num1[left] >'9')
		{
			num1[left] -= 10;
			flag = 1;
		}
		else flag = 0;
		--left; --right;
	}
	if (flag == 1)
		num1.insert(num1.begin(),'1');

	return num1;
}
int main()
{
	string num1 = "9999999999999999999999999999999999999999999999999999999999999999999";
	string num2 = "9";
	cout << num1 << endl;
	cout << addstrings(num1, num2) << endl;

	getchar();
	getchar(); getchar();
	system("pasue");
	return 0;
}