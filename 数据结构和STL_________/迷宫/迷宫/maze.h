#pragma once


struct position
{
	int _x;
	int _y;
};


template<size_t N>
class maze
{
public:
	maze(int ma[][N])
	{
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < N; ++j)
			{
				_arr[i][j] = ma[i][j];
			}
		}
	}
	//Ҽ�������ͨ�Թ�����
	bool CheckAccess(position pos)
	{
		//�жϱ߽�+�жϿ���ͨ
		if (pos._x >= 0 && pos._x < N&&pos._y >= 0 && pos._y < N
			&&_arr[pos._x][pos._y] == 0)
		{
			return true;
		}
		return false;
	}
	bool GetPath(position entry,stack<position> &s)//�ٷǵݹ��ҵ��Թ���һ����·
	{
		s.push(entry);
		while (!s.empty())
		{
			position cur = s.top();
			_arr[cur._x][cur._y] = 2;//�߹���·�����
			if (cur._x == N - 1)//���ݾ����ͼ����д�ĳ�������
				return true;
			//��
			position next = cur;
			next._x -= 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			//��
			next = cur;
			next._x += 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			//��
			next = cur;
			next._y -= 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			//��
			next = cur;
			next._y += 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			s.pop();//ջ��������
		}
		return false;
	}
	bool GetPath2(position entry)//�ڵݹ��ҵ��Թ���һ����·
	{
		_arr[entry._x][entry._y] = 2;//�߹���·�����

		if (entry._x == N - 1)//���ݾ����ͼ����д�ĳ�������
			return true;

		//��
		position next = entry;
		next._x -= 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		//��
		next = entry;
		next._x += 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		//��
		next = entry;
		next._y -= 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		//��
		next = entry;
		next._y += 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		return false;
	}
	//��һ��ջ������¼�߹���·���ڶ���ջ������¼�ҵ������·��
	void GetPath3(position entry, stack<position> &s, stack<position> &shortpath)//�۵ݹ������Թ����п����ߵĵط�
	{
		_arr[entry._x][entry._y] = 2;//�߹���·�����

		s.push(entry);
		if (entry._x == N - 1)//���ݾ����ͼ����д�ĳ�������
		{
			if (shortpath.empty() || s.size() < shortpath.size())//����ҵ����ڣ�������·��¼��shortpath����
			{
				shortpath = s;
			}
			//return;
		}
		//��
		position next = entry;
		next._x -= 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s,shortpath);
		}
		//��
		next = entry;
		next._x += 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s, shortpath);
		}
		//��
		next = entry;
		next._y -= 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s, shortpath);
		}
		//��
		next = entry;
		next._y += 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s, shortpath);
		}
		s.pop();
		return;
	}

	//���������������һ�����ڵ��Թ�����
	bool CheckAccess(position cur, position next)
	{
		//�жϱ߽�
		//��һ������ֵ�������ͨ������һ������ֵ���ڵ�ǰ����ֵ����ͨ
		if (next._x >= 0 && next._x < N&&next._y >= 0 && next._y < N
			&& (_arr[next._x][next._y] == 0 || _arr[next._x][next._y]>_arr[cur._x][cur._y]))
		{
			return true;
		}
		return false;
	}
	void GetPath4(position entry, stack<position>& s, stack<position>& shortpath)
	{
		//_arr[entry._x][entry._y] = 2;//�߹���·�����

		if (!s.empty())
		{
			_arr[entry._x][entry._y] = _arr[s.top()._x][s.top()._y] + 1;
		}
		s.push(entry);

		if (entry._x == N - 1)//���ݾ����ͼ����д�ĳ�������
		{
			if (shortpath.empty() || s.size() < shortpath.size())//����ҵ����ڣ�������·��¼��shortpath����
			{
				shortpath = s;
			}
			//s.pop();
			//return;
		}
		//��
		position next = entry;
		next._x -= 1;
		if (CheckAccess(entry, next))
		{
			GetPath4(next, s, shortpath);
		}
		//��
		next = entry;
		next._x += 1;
		if (CheckAccess(entry, next))
		{
			GetPath4(next, s, shortpath);
		}
		//��
		next = entry;
		next._y -= 1;
		if (CheckAccess(entry, next))
		{
			GetPath4(next, s, shortpath);
		}
		//��
		next = entry;
		next._y += 1;
		if (CheckAccess(entry, next))
		{
			GetPath4(next, s, shortpath);
		}
		s.pop();
		return;
	}

	void print()
	{
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < N; ++j)
			{
				printf("%3d", _arr[i][j]);
			}
			cout << endl;
		}
		cout << endl;
	}

protected:
	int _arr[N][N];

};

void test1()
{
	position entry;
	entry._x = 2;
	entry._y = 0;
	stack<position> s;
	stack<position> s2;

	//һ����Թ�
	int arr2[10][10] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 0, 0, 1, 1, 1,
		1, 1, 0, 0, 0, 1, 0, 1, 1, 1,
		1, 1, 0, 1, 1, 0, 0, 1, 1, 1,
		1, 1, 0, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 0, 1, 0, 0, 1, 1, 1, 1,
		1, 1, 0, 1, 1, 0, 1, 1, 1, 1,
		1, 1, 0, 1, 1, 0, 0, 0, 1, 1,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1
	};


	maze<10> maz(arr2);
	maz.print();

	//cout << "find the entry of maze:" << maz.GetPath(entry, s) << endl;
	//maz.print();

	//cout << "find the entry of maze:" << maz.GetPath2(entry) << endl;
	//maz.print();

	maz.GetPath3(entry, s, s2);
	maz.print();

	while (!s2.empty())
	{
		printf("[%d][%d]\n", s2.top()._x, s2.top()._y);
		s2.pop();
	}
}

void test2()
{
	position entry;
	entry._x = 2;
	entry._y = 0;
	stack<position> s;
	stack<position> s2;

	//��������һ�����ڵ��Թ�
	int arr2[10][10] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 1, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 0, 1, 1, 1, 1
	};


	maze<10> maz(arr2);
	maz.print();

	maz.GetPath4(entry, s, s2);
	maz.print();

	while (!s2.empty())
	{
		printf("[%d][%d]\n", s2.top()._x, s2.top()._y);
		s2.pop();
	}
}