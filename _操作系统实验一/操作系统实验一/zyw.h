#pragma once 

#define  MAXRESOURSE 100
#define  MAXPROCCESS 100
int Available[MAXRESOURSE];//可利用资源向量
int Max[MAXPROCCESS][MAXRESOURSE];//最大需求矩阵
int Allocation[MAXPROCCESS][MAXRESOURSE];//分配矩阵
int Need[MAXPROCCESS][MAXRESOURSE];//需求矩阵

int Request[MAXPROCCESS][MAXRESOURSE];//请求向量
int Work[MAXRESOURSE];//工作向量
bool Finish[MAXPROCCESS];//表示系统是否有足够的资源分配给进程
int SafeSeries[MAXPROCCESS];//安全序列
int temp_process;//当前输入进程数
int temp_resourse;//当前输入资源量
int init_tag = 0;

void init()//初始化分配规则
{
	cout << "请输入当前进程量：";
	cin >> temp_process;

	cout << "请输入当前资源量：";
	cin >> temp_resourse;

	cout << "请输入当前各个资源可利用资源数目：" << endl;
	for (int i = 0; i<temp_resourse; i++)
	{
		cin >> Available[i];
	}

	cout << "请输入最大需求矩阵：" << endl;
	for (int i = 0; i<temp_process; i++)
	for (int j = 0; j<temp_resourse; j++)
	{
		cin >> Max[i][j];
	}


	cout << "请输入分配矩阵：" << endl;
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

bool isSafe()  //判断Finish序列是否满足安全要求
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
		cout << "系统处于不安全状态！" << endl;
		return false;
	}

}

bool safe(int Need[][MAXRESOURSE], int Allocation[][MAXRESOURSE], int *Available) //当前分配是否满足安全性
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


void request()          //某进程向系统请求资源
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
	//用临时的资源进程储存，方便判断安全性法则是否满足，
	memcpy(tmpAlloc, Allocation, sizeof(int)*MAXPROCCESS*MAXRESOURSE);
	memcpy(tmpAvail, Available, sizeof(int)*MAXRESOURSE);
	memcpy(tmpNeed, Need, sizeof(int)*MAXPROCCESS*MAXRESOURSE);

	cout << "请输入请求资源的进程号:";
	cin >> index;
	cout << "请输入请求进程请求各个资源的数目号：" << endl;;
	for (int ii = 0; ii<temp_resourse; ii++)
	{
		cin >> Request[index][ii];
	}
	//判断此请求是否满足要求
	for (i = 0; i<temp_resourse; i++)
	{
		if (Request[index][i] <= Need[index][i] && Request[index][i] <= Available[i])
		{
			continue;
		}
		else if (Request[index][i]>Need[index][i])
		{
			cout << "进程请求错误！" << endl;
			break;
		}
		else
		{
			cout << "请求不被允许，请等待！" << endl;
			break;
		}
	}
	if (i == temp_resourse)  //满足条件，假设可为index分配资源
	{
		for (int j = 0; j<temp_resourse; j++)
		{
			tmpAvail[j] -= Request[index][j];
			tmpAlloc[index][j] += Request[index][j];
			tmpNeed[index][j] -= Request[index][j];
		}
		if (safe(tmpNeed, tmpAlloc, tmpAvail))
		{
			//如果资源分配满足安全性要求，更改实际的各个资源和进程信息

			memmove(Available, tmpAvail, sizeof(int)*MAXRESOURSE);
			memmove(Allocation, tmpAlloc, sizeof(int)*MAXPROCCESS*MAXRESOURSE);
			memmove(Need, tmpNeed, sizeof(int)*MAXPROCCESS*MAXRESOURSE);
			cout << "满足安全性算法，资源分配成功！" << endl;
		}
		else
		{
			cout << "不满足安全性算法，不分配资源！" << endl;
		}

	}

}

void printSafeSieris()//输出安全序列
{
	for (int i = 0; i<temp_process; i++)
		cout << "p" << SafeSeries[i] << "  ";
	cout << endl;
}
void menu()//菜单系统
{
	cout << "**************************" << endl;
	cout << "欢迎进入菜单系统！" << endl;
	cout << "请选择你要进行的操作！" << endl;
	cout << "1，安全性检测" << endl;
	cout << "2，打印矩阵" << endl;
	cout << "3，系统初始化" << endl;
	cout << "4，进程请求资源" << endl;
	cout << "5，退出" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void Display()  //矩阵显示
{
	int i = 0;
	int j = 0;
	cout << "当前可利用的资源数目" << endl;
	for (i = 0; i < temp_resourse; ++i)
	{
		cout << Available[i] << " ";
	}
	cout << endl;
	cout << "最大需求矩阵" << endl;
	for (i = 0; i < temp_process; ++i)
	{
		for (j = 0; j < temp_resourse; ++j)
		{
			cout << Max[i][j] << " ";
		}
		cout << endl;
	}
	cout << "分配矩阵" << endl;
	for (i = 0; i < temp_process; ++i)
	{
		for (j = 0; j < temp_resourse; ++j)
		{
			cout << Allocation[i][j] << " ";
		}
		cout << endl;
	}
	cout << "需求矩阵" << endl;
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
				cout << "系统还未初始化！error!" << endl;
			}
			break;
		case 2:
			if (init_tag)
			{
				Display();
			}
			else
			{
				cout << "系统还未初始化！error!" << endl;
			}
			break;
		case 3:
			init();
			if (safe(Need, Allocation, Available))
			{
				cout << "初始化成功！" << endl;
			}
			else{
				cout << "初始化失败！" << endl;
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
				cout << "系统还未初始化！error!" << endl;
			}
			break;
		}
	}
}
