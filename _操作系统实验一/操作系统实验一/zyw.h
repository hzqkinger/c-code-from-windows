#pragma once 

#define  MAXRESOURSE 100
#define  MAXPROCCESS 100
int Available[MAXRESOURSE];//��������Դ����
int Max[MAXPROCCESS][MAXRESOURSE];//����������
int Allocation[MAXPROCCESS][MAXRESOURSE];//�������
int Need[MAXPROCCESS][MAXRESOURSE];//�������

int Request[MAXPROCCESS][MAXRESOURSE];//��������
int Work[MAXRESOURSE];//��������
bool Finish[MAXPROCCESS];//��ʾϵͳ�Ƿ����㹻����Դ���������
int SafeSeries[MAXPROCCESS];//��ȫ����
int temp_process;//��ǰ���������
int temp_resourse;//��ǰ������Դ��
int init_tag = 0;

void init()//��ʼ���������
{
	cout << "�����뵱ǰ��������";
	cin >> temp_process;

	cout << "�����뵱ǰ��Դ����";
	cin >> temp_resourse;

	cout << "�����뵱ǰ������Դ��������Դ��Ŀ��" << endl;
	for (int i = 0; i<temp_resourse; i++)
	{
		cin >> Available[i];
	}

	cout << "����������������" << endl;
	for (int i = 0; i<temp_process; i++)
	for (int j = 0; j<temp_resourse; j++)
	{
		cin >> Max[i][j];
	}


	cout << "������������" << endl;
	for (int i = 0; i<temp_process; i++)
	for (int j = 0; j<temp_resourse; j++)
	{
		cin >> Allocation[i][j];
	}

	for (int i = 0; i<temp_process; i++)
	for (int j = 0; j<temp_resourse; j++)
	{
		Need[i][j] = Max[i][j] - Allocation[i][j];
	}

	for (int i = 0; i<temp_resourse; i++)
	{
		Work[i] = Available[i];
	}
	init_tag = 1;
}

bool isSafe()  //�ж�Finish�����Ƿ����㰲ȫҪ��
{
	int i = 0;
	for (i = 0; i<temp_process; i++)
	{
		if (Finish[i] == true)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if (i == temp_process)
	{
		return true;
	}
	else
	{
		cout << "ϵͳ���ڲ���ȫ״̬��" << endl;
		return false;
	}

}

bool safe(int Need[][MAXRESOURSE], int Allocation[][MAXRESOURSE], int *Available) //��ǰ�����Ƿ����㰲ȫ��
{
	int j = 0;
	int tag = 0;
	for (int i = 0; i<temp_process; i++)
		Finish[i] = false;

	for (int i = 0; i<temp_resourse; i++)
	{
		Work[i] = Available[i];
	}
	for (int k = 0; k<temp_process; k++)
	{
		for (int i = 0; i<temp_process; i++)
		{
			if (Finish[i] == true)
			{
				continue;
			}
			for (j = 0; j<temp_resourse; j++)
			{
				if (Need[i][j]>Work[j])
				{
					break;
				}
			}
			if (j == temp_resourse)
			{
				for (j = 0; j<temp_resourse; j++)
					Work[j] += Allocation[i][j];
				Finish[i] = true;
				SafeSeries[tag++] = i;
			}
		}
	}
	if (isSafe())
	{
		return true;
	}
	else return false;
}


void request()          //ĳ������ϵͳ������Դ
{
	int index;
	int i = 0;
	for (int m = 0; m<temp_resourse; m++)
	{
		SafeSeries[m] = 0;
	}
	int tmpAvail[MAXRESOURSE] = { 0 };
	int tmpAlloc[MAXPROCCESS][MAXRESOURSE] = { 0 };
	int tmpNeed[MAXPROCCESS][MAXRESOURSE] = { 0 };
	//����ʱ����Դ���̴��棬�����жϰ�ȫ�Է����Ƿ����㣬
	memcpy(tmpAlloc, Allocation, sizeof(int)*MAXPROCCESS*MAXRESOURSE);
	memcpy(tmpAvail, Available, sizeof(int)*MAXRESOURSE);
	memcpy(tmpNeed, Need, sizeof(int)*MAXPROCCESS*MAXRESOURSE);

	cout << "������������Դ�Ľ��̺�:";
	cin >> index;
	cout << "����������������������Դ����Ŀ�ţ�" << endl;;
	for (int ii = 0; ii<temp_resourse; ii++)
	{
		cin >> Request[index][ii];
	}
	//�жϴ������Ƿ�����Ҫ��
	for (i = 0; i<temp_resourse; i++)
	{
		if (Request[index][i] <= Need[index][i] && Request[index][i] <= Available[i])
		{
			continue;
		}
		else if (Request[index][i]>Need[index][i])
		{
			cout << "�����������" << endl;
			break;
		}
		else
		{
			cout << "���󲻱�������ȴ���" << endl;
			break;
		}
	}
	if (i == temp_resourse)  //���������������Ϊindex������Դ
	{
		for (int j = 0; j<temp_resourse; j++)
		{
			tmpAvail[j] -= Request[index][j];
			tmpAlloc[index][j] += Request[index][j];
			tmpNeed[index][j] -= Request[index][j];
		}
		if (safe(tmpNeed, tmpAlloc, tmpAvail))
		{
			//�����Դ�������㰲ȫ��Ҫ�󣬸���ʵ�ʵĸ�����Դ�ͽ�����Ϣ

			memmove(Available, tmpAvail, sizeof(int)*MAXRESOURSE);
			memmove(Allocation, tmpAlloc, sizeof(int)*MAXPROCCESS*MAXRESOURSE);
			memmove(Need, tmpNeed, sizeof(int)*MAXPROCCESS*MAXRESOURSE);
			cout << "���㰲ȫ���㷨����Դ����ɹ���" << endl;
		}
		else
		{
			cout << "�����㰲ȫ���㷨����������Դ��" << endl;
		}

	}

}

void printSafeSieris()//�����ȫ����
{
	for (int i = 0; i<temp_process; i++)
		cout << "p" << SafeSeries[i] << "  ";
	cout << endl;
}
void menu()//�˵�ϵͳ
{
	cout << "**************************" << endl;
	cout << "��ӭ����˵�ϵͳ��" << endl;
	cout << "��ѡ����Ҫ���еĲ�����" << endl;
	cout << "1����ȫ�Լ��" << endl;
	cout << "2����ӡ����" << endl;
	cout << "3��ϵͳ��ʼ��" << endl;
	cout << "4������������Դ" << endl;
	cout << "5���˳�" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void Display()  //������ʾ
{
	int i = 0;
	int j = 0;
	cout << "��ǰ�����õ���Դ��Ŀ" << endl;
	for (i = 0; i < temp_resourse; ++i)
	{
		cout << Available[i] << " ";
	}
	cout << endl;
	cout << "����������" << endl;
	for (i = 0; i < temp_process; ++i)
	{
		for (j = 0; j < temp_resourse; ++j)
		{
			cout << Max[i][j] << " ";
		}
		cout << endl;
	}
	cout << "�������" << endl;
	for (i = 0; i < temp_process; ++i)
	{
		for (j = 0; j < temp_resourse; ++j)
		{
			cout << Allocation[i][j] << " ";
		}
		cout << endl;
	}
	cout << "�������" << endl;
	for (i = 0; i < temp_process; ++i)
	{
		for (j = 0; j < temp_resourse; ++j)
		{
			cout << Need[i][j] << " ";
		}
		cout << endl;
	}
}


void test_bank()
{
	int m_index = 0;
	while (m_index != 5)
	{
		menu();
		cin >> m_index;
		switch (m_index)
		{
		case 1:
			if (init_tag)
			{
				if (safe(Need, Allocation, Available))
				{
					printSafeSieris();
				}

			}
			else{
				cout << "ϵͳ��δ��ʼ����error!" << endl;
			}
			break;
		case 2:
			if (init_tag)
			{
				Display();
			}
			else
			{
				cout << "ϵͳ��δ��ʼ����error!" << endl;
			}
			break;
		case 3:
			init();
			if (safe(Need, Allocation, Available))
			{
				cout << "��ʼ���ɹ���" << endl;
			}
			else{
				cout << "��ʼ��ʧ�ܣ�" << endl;
				for (int i = 0; i<temp_process; i++)
				for (int j = 0; j<temp_resourse; j++)
				{
					Need[i][j] = 0;
					Available[j] = 0;
					Allocation[i][j] = 0;
					Max[i][j] = 0;
				}
			}
			break;
		case 4:
			if (init_tag)
			{
				request();
			}
			else
			{
				cout << "ϵͳ��δ��ʼ����error!" << endl;
			}
			break;
		}
	}
}
