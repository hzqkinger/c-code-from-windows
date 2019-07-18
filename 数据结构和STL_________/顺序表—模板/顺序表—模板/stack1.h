
#include"seqlist.h"

// template <class T, class Container>
//template <class T, class Container = seqlist<T > > // 缺省参数
template <class T, template <class> class Container = seqlist > // 缺省参数
class Stack
{
public:
	void Push(const T& x)
	{
		_con.PushBack(x);
	}
	void Pop()
	{
		_con.PopBack();
	}
	T & Top()const
	{
		return _con.Top();
	}
	bool Empty()
	{
		return _con.Empty();
	}
private:
	//Container _con;
	Container<T> _con;

};
void Test1()
{
	Stack<string> s1;
	s1.Push("111111");
	s1.Push("222222222222222222222222222");
	s1.Push("333333");
	s1.Push("444444444444444444");

	cout<< s1.Top()<<" ";
	s1.Pop();
	cout << s1.Top() << " ";
	s1.Pop();
	cout << s1.Top() << " ";
	s1.Pop();
	cout << s1.Top() << " ";
	s1.Pop();



	Stack<int, seqlist> s2;
	//// 思考下面这种使用场景会怎样？
	//Stack<int, seqlist< char>> s3;
}