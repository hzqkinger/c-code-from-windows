#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>//其作用只是为了让程序停留在黑框口
#include<assert.h>
#include<time.h>//提供该头文件是为了使用time(NULL)函数获取当前时间

#define N 20

//顺序栈的数据结构及其操作
#define Stack_init_size 100
#define Stack_increment 10
#define DateType int
typedef struct{
	DateType *base;
	DateType *top;
	int stacksize;
}Stack1;
void Initstack(Stack1& s)//①栈的初始化
{
	s.base = (DateType*)malloc(Stack_init_size*sizeof(DateType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.stacksize = Stack_init_size;
}
void Push(Stack1& s, DateType e)//②数据进栈
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (DateType*)realloc(s.base, (s.stacksize + Stack_increment)*sizeof(DateType));
		if (!s.base)
			exit(-1);
		s.top = s.base + s.stacksize;
		s.stacksize += Stack_increment;
	}
	*s.top++ = e;
}
void Pop(Stack1& s, DateType& e)//③数据出栈
{
	if (s.top == s.base)
		exit(-1);
	e = *--s.top;
}
bool Isfull(const Stack1& s)
{
	if (s.base - s.top>=N)
		return true;
	return false;
}
void Stackshow(const Stack1 s)//④显示栈中的元素
{
	DateType *tmp = s.base;
	while (tmp < s.top)
		cout << *tmp++ << endl;
}

//链队列的数据结构及其操作
#define eletype int
typedef struct qnode{
	eletype _data;
	struct qnode *_next;
}Qnode;
typedef struct{
	Qnode *front;
	Qnode *rear;
}Qlink;
void InitQueue(Qlink &q)//①队列的初始化
{
	q.front = q.rear = NULL;
}
void EnQueue(Qlink &q, eletype e)//②数据进队列
{
	Qnode *p = new Qnode;
	p->_next = NULL;
	p->_data = e;
	if (!q.rear)
		q.front = q.rear = p;
	else
		q.rear->_next = p;
	q.rear = p;
}
eletype DeQueue(Qlink &q, eletype &e)//③数据出队列，用e存储该数据
{
	assert(q.front);
	Qnode *tmp = q.front->_next;
	e = q.front->_data;
	delete q.front;
	q.front = tmp;
	return e;
}
void ShowQueue(const Qlink &q)//④显示队列中的数据
{
	Qnode *tmp = q.front;
	while (tmp)
	{
		cout << tmp->_data << "->";
		tmp = tmp->_next;
	}
	cout << endl;
}

//1.目的：①熟练掌握栈和队列的逻辑结构和物理结构
//        ②掌握离散事件模拟的基本方法
//2.要求：设停车场内只有一个可停放n辆汽车的狭长通道，且只有一个大门可供汽车进出。
//        汽车在停车场内按车辆到达时间的先后顺序，依次由北向南排列（大门在最南端，最先到达
//        的第一辆车停放在车场的最北端），若车场内已停满n辆汽车，则后来的汽车只能在门外的便
//        道上等候，一旦有车开走，则排在便道上的第一辆车即可开入；当停车场内某辆车要离开时，
//        在它之后开入的车辆必须先退出车场为它让路，待该辆车开出大门外，其它车辆再按原次序
//        进入车场，每辆停放在车场的车在它离开停车场时必须按它停留的时间长短交纳费用。试为
//        停车场编制按上述要求进行管理的模拟程序。

//车子开过来，①栈未满进①栈；栈满进队列
void Car_enter(Stack1 &s1, Qlink &q)
{
	if (Isfull(s1))
		EnQueue(q, time(NULL));
	else
		Push(s1, time(NULL));
}
//车子离开，挪出来的其他车先进入②栈，然后这些车再入①栈，然后队列中的一辆车出队列进入栈①
int Fare(Stack1 &s1, Stack1 &s2, Qlink &q, size_t num)
{
	int e; int d;
	int fare = 10;
	assert(num < s1.top - s1.base);
	while (--num)//挪开其他的车，
	{
		Pop(s1, e);
		Push(s2, e);
	}
	Pop(s1, e);//让要离开的车出栈，然后赶紧算停留时间及所花的钱
	d = time(NULL);
	e = d - e;
	fare = fare * e;
	while (s2.top != s2.base)//将刚才挪出来的车子再挪回去
	{
		Pop(s2, e);
		Push(s1, e);
	}
	if (q.front != q.rear)//如果队列中还有车子，出队列然后入①栈
	{
		DeQueue(q, e);
		Push(s1, time(NULL));
	}
	return fare;
}

int main()
{
	size_t num = 2;//表示栈①中的第num辆车要离开
	int fare;
	Stack1 sta1, sta2;
	Qlink qlist;

	Initstack(sta1);//初始化栈和队列
	Initstack(sta2);
	InitQueue(qlist);
	Car_enter(sta1, qlist);//车子开过来入栈或者进队列
	Car_enter(sta1, qlist);//由于这里车子进栈是在一个程序中跑，所以所有车子进栈时间基本一样
	Sleep(1000);//这里睡上一秒，（现实中车子进栈时间就大不相同了，所以在这里用秒来计费）
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);

	Stackshow(sta1);

	Sleep(5000);//由于这是在一个程序里跑，所以先让程序在这睡个5秒钟
	fare = Fare(sta1, sta2, qlist, num);//车子离开，结账

	printf("%d\n", fare);
	system("pause");
	return 0;
}