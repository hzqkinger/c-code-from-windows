#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<CoreWindow.h>

//��ŵ���ƶ��ĵݹ�˼�����
void process(size_t n, char one, char two, char three)//�ú�����������:��n�����Ӵ�one����two�ƶ���three
{
	if (n == 1)cout << one << "-->" << three << endl;
	else{
		process(n - 1, one, three, two);//��n-1�����Ӵ�one����three�ƶ���two
		cout << one << "-->" << three << endl;//����n�����Ӵ�one�ƶ���three
		process(n - 1, two, one, three);//���n-1�����Ӵ�two����one�ƶ���three
	}
}
void Hanoi(size_t n)
{
	process(n, 'A', 'B', 'C');
}

int main()
{
	size_t n; cin >> n;
	Hanoi(n);

	system("pause");
	return 0;
}