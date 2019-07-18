#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>//������ֻ��Ϊ���ó���ͣ���ںڿ��
#include<assert.h>
#include<time.h>//�ṩ��ͷ�ļ���Ϊ��ʹ��time(NULL)������ȡ��ǰʱ��

#define N 20

//˳��ջ�����ݽṹ�������
#define Stack_init_size 100
#define Stack_increment 10
#define DateType int
typedef struct{
	DateType *base;
	DateType *top;
	int stacksize;
}Stack1;
void Initstack(Stack1& s)//��ջ�ĳ�ʼ��
{
	s.base = (DateType*)malloc(Stack_init_size*sizeof(DateType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.stacksize = Stack_init_size;
}
void Push(Stack1& s, DateType e)//�����ݽ�ջ
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
void Pop(Stack1& s, DateType& e)//�����ݳ�ջ
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
void Stackshow(const Stack1 s)//����ʾջ�е�Ԫ��
{
	DateType *tmp = s.base;
	while (tmp < s.top)
		cout << *tmp++ << endl;
}

//�����е����ݽṹ�������
#define eletype int
typedef struct qnode{
	eletype _data;
	struct qnode *_next;
}Qnode;
typedef struct{
	Qnode *front;
	Qnode *rear;
}Qlink;
void InitQueue(Qlink &q)//�ٶ��еĳ�ʼ��
{
	q.front = q.rear = NULL;
}
void EnQueue(Qlink &q, eletype e)//�����ݽ�����
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
eletype DeQueue(Qlink &q, eletype &e)//�����ݳ����У���e�洢������
{
	assert(q.front);
	Qnode *tmp = q.front->_next;
	e = q.front->_data;
	delete q.front;
	q.front = tmp;
	return e;
}
void ShowQueue(const Qlink &q)//����ʾ�����е�����
{
	Qnode *tmp = q.front;
	while (tmp)
	{
		cout << tmp->_data << "->";
		tmp = tmp->_next;
	}
	cout << endl;
}

//1.Ŀ�ģ�����������ջ�Ͷ��е��߼��ṹ������ṹ
//        ��������ɢ�¼�ģ��Ļ�������
//2.Ҫ����ͣ������ֻ��һ����ͣ��n������������ͨ������ֻ��һ�����ſɹ�����������
//        ������ͣ�����ڰ���������ʱ����Ⱥ�˳�������ɱ��������У����������϶ˣ����ȵ���
//        �ĵ�һ����ͣ���ڳ�������ˣ�������������ͣ��n�������������������ֻ��������ı�
//        ���ϵȺ�һ���г����ߣ������ڱ���ϵĵ�һ�������ɿ��룻��ͣ������ĳ����Ҫ�뿪ʱ��
//        ����֮����ĳ����������˳�����Ϊ����·�������������������⣬���������ٰ�ԭ����
//        ���복����ÿ��ͣ���ڳ����ĳ������뿪ͣ����ʱ���밴��ͣ����ʱ�䳤�̽��ɷ��á���Ϊ
//        ͣ�������ư�����Ҫ����й����ģ�����

//���ӿ���������ջδ������ջ��ջ��������
void Car_enter(Stack1 &s1, Qlink &q)
{
	if (Isfull(s1))
		EnQueue(q, time(NULL));
	else
		Push(s1, time(NULL));
}
//�����뿪��Ų�������������Ƚ����ջ��Ȼ����Щ�������ջ��Ȼ������е�һ���������н���ջ��
int Fare(Stack1 &s1, Stack1 &s2, Qlink &q, size_t num)
{
	int e; int d;
	int fare = 10;
	assert(num < s1.top - s1.base);
	while (--num)//Ų�������ĳ���
	{
		Pop(s1, e);
		Push(s2, e);
	}
	Pop(s1, e);//��Ҫ�뿪�ĳ���ջ��Ȼ��Ͻ���ͣ��ʱ�估������Ǯ
	d = time(NULL);
	e = d - e;
	fare = fare * e;
	while (s2.top != s2.base)//���ղ�Ų�����ĳ�����Ų��ȥ
	{
		Pop(s2, e);
		Push(s1, e);
	}
	if (q.front != q.rear)//��������л��г��ӣ�������Ȼ�����ջ
	{
		DeQueue(q, e);
		Push(s1, time(NULL));
	}
	return fare;
}

int main()
{
	size_t num = 2;//��ʾջ���еĵ�num����Ҫ�뿪
	int fare;
	Stack1 sta1, sta2;
	Qlink qlist;

	Initstack(sta1);//��ʼ��ջ�Ͷ���
	Initstack(sta2);
	InitQueue(qlist);
	Car_enter(sta1, qlist);//���ӿ�������ջ���߽�����
	Car_enter(sta1, qlist);//�������ﳵ�ӽ�ջ����һ���������ܣ��������г��ӽ�ջʱ�����һ��
	Sleep(1000);//����˯��һ�룬����ʵ�г��ӽ�ջʱ��ʹ���ͬ�ˣ������������������Ʒѣ�
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);
	Car_enter(sta1, qlist);

	Stackshow(sta1);

	Sleep(5000);//����������һ���������ܣ��������ó�������˯��5����
	fare = Fare(sta1, sta2, qlist, num);//�����뿪������

	printf("%d\n", fare);
	system("pause");
	return 0;
}