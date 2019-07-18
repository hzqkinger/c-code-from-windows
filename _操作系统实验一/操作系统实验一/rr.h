#pragma once

#include<string>
#include<vector>
#include<algorithm>
#include<queue>

struct rr_pro
{
	string _name;//������
	int _intime;//�ύʱ��
	int _server;//����ʱ��

	//����Ϊʱ��Ƭ��ת���Ȼ�ı�_intime��Ϊ�˺ô�ӡԭ�����ݣ��������_intimetmp��
	int _intimetmp;//�ύʱ��ĸ���
	int _servertmp;//����ʱ��ĸ�����ͬ��

	int _finish;//���ʱ��
	int _zztime;//��תʱ��
};

bool rr_comp(const rr_pro& left, const rr_pro& right)//����º�����ʹ���г������ύʱ������
{
	return left._intime < right._intime;
}

void rr_print(const vector<rr_pro> &v)//��ӡ���
{
	printf("������ ����ʱ�� ����ʱ�� ���ʱ�� ��תʱ��\n");
	auto it = v.begin();
	while (it != v.end())
	{
		cout << it->_name << "	" << it->_intimetmp << "	 " << it->_servertmp << "	 " \
			<< it->_finish << "	 " << it->_zztime << "	  " << endl;
		++it;
	}
}

void test_rr()
{
	printf("��ֱ�����һ���������򣬳������е�ʱ��Ƭ\n");
	int N = 0,Q = 0;
	cin >> N >> Q;

	vector<rr_pro> arr(N);//��Ŀ�������������Щ����Ȼ��������װ������
	for (int i = 0; i < N; ++i)
	{
		printf("��ֱ���������������ύʱ�䣬����ʱ��\n");
		cin >> arr[i]._name >> arr[i]._intime >> arr[i]._server;

		arr[i]._intimetmp = arr[i]._intime;
		arr[i]._servertmp = arr[i]._server;
	}
	auto begin = arr.begin();
	auto end = arr.end();
	sort(begin, end, rr_comp);//���ճ����ύʱ������

	int times = 0;
	while (begin != arr.end())
	{
		if (begin->_server <= Q)//������ʱ��Ƭ�о�ִ������
		{
			if (times < begin->_intime)
				times = begin->_intime + begin->_server;
			else
				times += begin->_server;

			begin->_finish = times;
			begin->_zztime = begin->_finish - begin->_intimetmp;

			++begin;
		}
		else
		{
			begin->_server -= Q;
			times += Q;
			begin->_intime = times;

		}

		auto eend = begin;//���whileѭ�������ã�������beginָ��ĳ���ʱ����������Щ����Ҳ�Ѿ��ύ����
		while (eend != end && eend->_intime <= times)++eend;

		if (eend != begin)
		{
			--eend;
			swap(*begin, *eend);
			++eend;
		}

		if (begin != arr.end())
			sort(begin, eend, rr_comp);//���Ѿ��ύ�����ĳ����� �ύʱ��ʱ������
	}

	rr_print(arr);
}