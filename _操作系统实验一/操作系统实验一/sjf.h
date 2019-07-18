#pragma once


#include<string>
#include<vector>
#include<algorithm>

struct pro
{
	string _name;//������
	int _intime;//�ύʱ��
	int _server;//����ʱ��

	int _finish;//���ʱ��
	int _zztime;//��תʱ��
};

bool comp(const pro& left, const pro& right)//����º�����ʹ���г������ύʱ������
{
	return left._intime < right._intime;
}
bool comp2(const pro& left, const pro& right)//����º�����ʹ���г����շ���ʱ������
{
	return left._server < right._server;
}

void print(const vector<pro> &v)//��ӡ���
{
	printf("������ ����ʱ�� ����ʱ�� ���ʱ�� ��תʱ��\n");
	auto it = v.begin();
	while (it != v.end())
	{
		cout << it->_name << "	" << it->_intime << "	 " << it->_server << "	 " \
			<< it->_finish << "	 " << it->_zztime << "	  " << endl;
		++it;
	}
}
void test_sjf()
{
	cout << "������һ����������" << endl;
	int N = 0;
	cin >> N;

	vector<pro> arr(N);//��Ŀ�������������Щ����Ȼ��������װ������
	for (int i = 0; i < N; ++i)
	{
		printf("��ֱ���������������ύʱ�䣬����ʱ��\n");
		cin >> arr[i]._name;
		cin >> arr[i]._intime;
		cin >> arr[i]._server;

		arr[i]._finish = 0;
		arr[i]._zztime = 0;
	}
	auto begin = arr.begin();
	auto end = arr.end();
	sort(begin, end, comp);//�Ȱ��ճ�����ύʱ������


	int times = 0;//�����ҳ�ʼ��ʱ����
	while (begin != arr.end())
	{
		if (times < begin->_intime)//����ʱ����
			times = begin->_intime + begin->_server;
		else
			times += begin->_server;

		begin->_finish += times;//����begin��������ָ����Ǹ�����
		begin->_zztime = begin->_finish - begin->_intime;

		auto eend = ++begin;//���whileѭ�������ã�������beginָ��ĳ���ʱ����������Щ����Ҳ�Ѿ��ύ����
		while (eend != end && eend->_intime < times)++eend;

		if (begin != arr.end())
			sort(begin, eend, comp2);//���Ѿ��ύ�����ĳ����� ����ʱ������
	}

	print(arr);//���ô�ӡ�����������ӡ��arr����
}

