//���� �˰���(�迭)
#include <iostream>
using namespace std;
#define MAXSIZE 10

template<class T>
class myStack
{
	int top;
	int size;
	T* val;
public:
	myStack()
	{
		top = 0;
		size = MAXSIZE;
		val = new T[MAXSIZE];
	}
	~myStack()
	{
		delete[] val;
	}
	bool is_full()
	{
		if (top >= MAXSIZE) return true;
		else return false;
	}
	bool is_empty()
	{
		if (top == 0) return true;
		else return false;
	}
	void push(T item)
	{
		if (!is_full())
		{
			val[top] = item;
			top++;
		}
		else
		{
			cout << "push() ���� : ���� ������!" << endl;
		}
	}
	void pop()
	{
		if (!is_empty())
		{
			val[--top] = NULL;
		}
		else
		{
			cout << "pop() ���� : ���� �������!" << endl;
		}
	}
	void peek()
	{
		if (!is_empty())
		{
			cout << "�� ���� ���� : " << val[top - 1] << endl;
		}
		else
		{
			cout << "peek() ���� : ���� �������!" << endl;
		}
	}
};

int main()
{
	myStack<int> s;
	s.push(1);
	s.peek();
	s.push(2);
	s.peek();
	s.push(3);
	s.peek();

	s.pop();
	s.peek();
	s.pop();
	s.peek();
	s.pop();
	s.peek();
	s.pop();
	s.peek();

	return 0;
}