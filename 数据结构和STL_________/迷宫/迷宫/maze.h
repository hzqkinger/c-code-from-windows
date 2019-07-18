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
	//壹：解决普通迷宫问题
	bool CheckAccess(position pos)
	{
		//判断边界+判断可以通
		if (pos._x >= 0 && pos._x < N&&pos._y >= 0 && pos._y < N
			&&_arr[pos._x][pos._y] == 0)
		{
			return true;
		}
		return false;
	}
	bool GetPath(position entry,stack<position> &s)//①非递归找到迷宫的一条出路
	{
		s.push(entry);
		while (!s.empty())
		{
			position cur = s.top();
			_arr[cur._x][cur._y] = 2;//走过的路做标记
			if (cur._x == N - 1)//根据具体的图形来写的出口条件
				return true;
			//上
			position next = cur;
			next._x -= 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			//下
			next = cur;
			next._x += 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			//左
			next = cur;
			next._y -= 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			//右
			next = cur;
			next._y += 1;
			if (CheckAccess(next))
			{
				s.push(next);
				continue;
			}
			s.pop();//栈用来回溯
		}
		return false;
	}
	bool GetPath2(position entry)//②递归找到迷宫的一条出路
	{
		_arr[entry._x][entry._y] = 2;//走过的路做标记

		if (entry._x == N - 1)//根据具体的图形来写的出口条件
			return true;

		//上
		position next = entry;
		next._x -= 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		//下
		next = entry;
		next._x += 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		//左
		next = entry;
		next._y -= 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		//右
		next = entry;
		next._y += 1;
		if (CheckAccess(next))
		{
			if (GetPath2(next))
				return true;
		}
		return false;
	}
	//第一个栈用来记录走过的路，第二个栈用来记录找到的最短路径
	void GetPath3(position entry, stack<position> &s, stack<position> &shortpath)//③递归走完迷宫所有可以走的地方
	{
		_arr[entry._x][entry._y] = 2;//走过的路做标记

		s.push(entry);
		if (entry._x == N - 1)//根据具体的图形来写的出口条件
		{
			if (shortpath.empty() || s.size() < shortpath.size())//如果找到出口，将该条路记录在shortpath里面
			{
				shortpath = s;
			}
			//return;
		}
		//上
		position next = entry;
		next._x -= 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s,shortpath);
		}
		//下
		next = entry;
		next._x += 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s, shortpath);
		}
		//左
		next = entry;
		next._y -= 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s, shortpath);
		}
		//右
		next = entry;
		next._y += 1;
		if (CheckAccess(next))
		{
			GetPath3(next, s, shortpath);
		}
		s.pop();
		return;
	}

	//贰：解决带环共用一条出口的迷宫问题
	bool CheckAccess(position cur, position next)
	{
		//判断边界
		//下一个坐标值是零可以通；或下一个坐标值大于当前坐标值可以通
		if (next._x >= 0 && next._x < N&&next._y >= 0 && next._y < N
			&& (_arr[next._x][next._y] == 0 || _arr[next._x][next._y]>_arr[cur._x][cur._y]))
		{
			return true;
		}
		return false;
	}
	void GetPath4(position entry, stack<position>& s, stack<position>& shortpath)
	{
		//_arr[entry._x][entry._y] = 2;//走过的路做标记

		if (!s.empty())
		{
			_arr[entry._x][entry._y] = _arr[s.top()._x][s.top()._y] + 1;
		}
		s.push(entry);

		if (entry._x == N - 1)//根据具体的图形来写的出口条件
		{
			if (shortpath.empty() || s.size() < shortpath.size())//如果找到出口，将该条路记录在shortpath里面
			{
				shortpath = s;
			}
			//s.pop();
			//return;
		}
		//上
		position next = entry;
		next._x -= 1;
		if (CheckAccess(entry, next))
		{
			GetPath4(next, s, shortpath);
		}
		//下
		next = entry;
		next._x += 1;
		if (CheckAccess(entry, next))
		{
			GetPath4(next, s, shortpath);
		}
		//左
		next = entry;
		next._y -= 1;
		if (CheckAccess(entry, next))
		{
			GetPath4(next, s, shortpath);
		}
		//右
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

	//一般的迷宫
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

	//带环共用一条出口的迷宫
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