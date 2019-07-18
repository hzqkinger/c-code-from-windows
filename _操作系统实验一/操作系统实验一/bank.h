#pragma once

#define MAXPROCESS 50
#define MAXRESOURCE 100
int AVAILABLE[MAXRESOURCE];
int MAX[MAXPROCESS][MAXRESOURCE];
int ALLOCATION[MAXPROCESS][MAXRESOURCE];
int NEED[MAXPROCESS][MAXRESOURCE];

int REQUEST[MAXPROCESS][MAXRESOURCE];
bool FINISH[MAXPROCESS];

int p[MAXPROCESS];  //��¼����
int m, n;   //m������,n����Դ

void showdata(int n, int m)//��ʾ���ϵͳ��Ϣ
{
	int i, j;
	cout << endl << "-------------------------------------------------------------" << endl;
	cout << "ϵͳ���õ���Դ��Ϊ:    ";
	for (j = 0; j < n; j++)
		cout << "    " << AVAILABLE[j];
	cout << endl << "�����̻���Ҫ����Դ��:" << endl;
	for (i = 0; i < m; i++)
	{
		cout << "    ����" << i << ":";
		for (j = 0; j < n; j++)
			cout << "     " << NEED[i][j];
		cout << endl;
	}
	cout << endl << "�������Ѿ��õ�����Դ��:    " << endl << endl;
	for (i = 0; i < m; i++)
	{
		cout << "    ����" << i << ":";
		for (j = 0; j < n; j++)
			cout << "     " << ALLOCATION[i][j];
		cout << endl;
	}
	cout << endl;
}
bool Safe()//��ȫ�㷨
{
	int i, j, k, l = 0;
	int Work[MAXRESOURCE];    //��������,�������鸳ֵ����AVAILABLE������ͬ
	for (i = 0; i < n; i++)
		Work[i] = AVAILABLE[i];//FINISH���鸳ֵ����ʼΪȫ��false
	for (i = 0; i < m; i++)
		FINISH[i] = false;    //FINISH��¼ÿ�������Ƿ�ȫ

	while (l < m)    //�����Ļ�����ִ��m��
	{

		bool flag = false;

		for (i = 0; i < m; i++)//��ѭ������need���󣬸����ҵ�һ����ȫ���̣������еĻ���
		{
			if (FINISH[i] == true)    //���������̰�ȫ�������һ��ѭ��
				continue;
			for (j = 0; j < n; j++)
				if (NEED[i][j] > Work[j])
					break;

			if (j == n)
			{
				flag = true;
				FINISH[i] = true;
				for (k = 0; k < n; k++)
					Work[k] += ALLOCATION[i][k];
				p[l++] = i;//��¼���̺�    
			}
			else    //�����������ѭ����һ������
				continue;
		}

		if (!flag)//���ѭ��������û���ҵ�һ����ȫ����(��l==init_index)�����ʾϵͳ����ȫ
		{
			cout << "ϵͳ�ǲ���ȫ��" << endl;
			return false;
		}
	}

	cout << "ϵͳ�ǰ�ȫ��" << endl;
	cout << "��ȫ����:" << endl;
	for (i = 0; i < l; i++)
	{
		cout << p[i];
		if (i != l - 1)
			cout << "-->";
	}
	cout << endl;
	return true;
}
void Bank()//���м��㷨
{
	int i, cusneed, flag = 0;    //cousneed��Դ���̺�
	while (1)
	{
		showdata(n, m);
		cout << endl;
		/*������Դ*/
		while (true)
		{
			bool flag = false;

			cout << "������Ҫ������Դ�Ľ��̺�(ע:��1�����̺�Ϊ0,��������)" << endl;
			cin >> cusneed;
			if (cusneed > m)
			{
				cout << "û�иý��̣�����������" << endl;
				continue;
			}
			cout << "���������������ĸ���Դ������" << endl;
			for (i = 0; i < n; i++)
				cin >> REQUEST[cusneed][i];
			for (i = 0; i < n; i++)
			{
				if (REQUEST[cusneed][i] > NEED[cusneed][i])    //����û�ѡ����̵߳ĵ�i����Դ�����������̸߳���Դ���������
				{
					cout << "��������������������̵�������!����������!" << endl;
					flag = true;
					continue;//...
				}
				if (REQUEST[cusneed][i] > AVAILABLE[i])    //����û�ѡ����̵߳ĵ�i����Դ��������ϵͳ���еĵ�i����Դ������
				{
					cout << "�����������������ϵͳ�е���Դ��!����������!" << endl;
					flag = true;
					continue;//...
				}
			}
			if (!flag)
				break;
		}
		/*������������ô��ʼ���м��㷨����*/
		/*�Ƚ��������Դ���з���*/
		for (i = 0; i < n; i++)
		{
			AVAILABLE[i] -= REQUEST[cusneed][i];            //ϵͳ������Դ��ȥ�����˵�
			ALLOCATION[cusneed][i] += REQUEST[cusneed][i];    //�̱߳��������Դ�����������˵�
			NEED[cusneed][i] -= REQUEST[cusneed][i];        //�̻߳���Ҫ����Դ��ȥ������õ���
		}
		/*�жϷ���������Դ���ϵͳ�Ƿ�ȫ���������ȫ�򽫷����������Դ����ϵͳ*/
		if (Safe())    //AVAILABLE  ALLOCATION  NEED�䶯֮���Ƿ�ᵼ�²���ȫ
			cout << "ͬ���������!" << endl;
		else
		{
			cout << "�������󱻾ܾ�!" << endl;
			/*��Դ����ϵͳ*/
			for (i = 0; i < n; i++)
			{
				AVAILABLE[i] += REQUEST[cusneed][i];
				ALLOCATION[cusneed][i] -= REQUEST[cusneed][i];
				NEED[cusneed][i] += REQUEST[cusneed][i];
			}
		}
		//......
		/*�Խ��̵�������Դ�����жϣ��Ƿ���Ҫ��Դ����NEED�����Ƿ�Ϊ0*/
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (NEED[cusneed][i] == 0)
				flag++;
		}
		if (flag == n)    //����ý��̸���Դ�����������������ͷ���Դ
		{
			for (i = 0; i < n; i++)
			{
				AVAILABLE[i] += ALLOCATION[cusneed][i];
				ALLOCATION[cusneed][i] = 0;
				NEED[cusneed][i] = 0;
			}
			cout << "�߳�" << cusneed << " ռ�е���Դ���ͷţ�" << endl;
			flag = 0;
		}
		for (i = 0; i < m; i++)    //��������Ժ󽫽��̵ı�ʶFINISH�ĳ�false
			FINISH[i] = false;
		char again;    //�ж��Ƿ�������룬����¼��һ���ַ������ж��Ƿ����������Դ
		cout << "�������ٴ����������?���밴y/Y,���밴������" << endl;
		cin >> again;
		if (again == 'y' || again == 'Y')
			continue;
		break;
	}
}

void test_bank()
{
	int i, j;
	cout << "��������̵���Ŀ:";
	cin >> m;
	cout << "��������Դ������:";
	cin >> n;
	cout << "������ÿ�������������ĸ���Դ��,����" << m << "x" << n << "��������" << endl;
	for (i = 0; i<m; i++)
	for (j = 0; j<n; j++)
		cin >> MAX[i][j];
	cout << "������ÿ�������ѷ���ĸ���Դ��,Ҳ����" << m << "x" << n << "��������" << endl;
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
	{
		cin >> ALLOCATION[i][j];
		NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
		if (NEED[i][j] < 0)
		{
			cout << "������ĵ�" << i + 1 << "��������ӵ�еĵ�" << j + 1 << "����Դ������,����������:" << endl;
			j--;
			continue;
		}
	}
	cout << "�����������Դ���е���Ŀ:" << endl;
	for (i = 0; i < n; i++)
		cin >> AVAILABLE[i];

	Safe();
	Bank();
}