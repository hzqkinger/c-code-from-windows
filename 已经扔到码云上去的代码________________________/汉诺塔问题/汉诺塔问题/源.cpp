#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<CoreWindow.h>

//汉诺塔移动的递归思想过程
void process(size_t n, char one, char two, char three)//该函数的意义是:将n个盘子从one借助two移动到three
{
	if (n == 1)cout << one << "-->" << three << endl;
	else{
		process(n - 1, one, three, two);//将n-1个盘子从one借助three移动到two
		cout << one << "-->" << three << endl;//将第n个盘子从one移动到three
		process(n - 1, two, one, three);//最后将n-1个盘子从two借助one移动到three
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