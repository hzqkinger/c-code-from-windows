#include"slist.h"



void test()
{
	list<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.Print();
	s1.PushFront(6);
	s1.PushFront(7);
	s1.PushFront(8);
	s1.PushFront(9);
	s1.Print();

	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.Print();
	s1.PopFront();
	s1.PopFront();
	s1.PopFront();
	s1.Print();

	list<int> s2 = s1;
	s2.Print();
	list<int> s3;
	s3 = s1;
	s3.Print();

}
int main()
{
	test();
	system("pause");
	return 0;
}