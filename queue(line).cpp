//���� ť �˰���(�迭)
//���� ť ������ : �迭���� front�� �����ϱ� ������, ����ִ� �迭 �ڸ��� ����
#include <iostream>
using namespace std;
#define MAXSIZE 10

template<class T>
class myQueue
{
	int front;
	int top;
	int size;
	T* val;
public:
	myQueue()
	{
		front = 0;
		top = 0;
		size = MAXSIZE;
		val = new T[MAXSIZE];
	}
	~myQueue()
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
		if (front == top) return true;
		else return false;
	}
	void enqueue(T item)
	{
		if (!is_full())
		{
			val[top] = item;
			top++;
		}
		else
		{
			cout << "enqueue() ���� : ���� ������!" << endl;
		}
	}
	void dequeue()
	{
		if (!is_empty())
		{
			val[front] = NULL;
			front++;
		}
		else
		{
			cout << "dequeue() ���� : ť �������!" << endl;
		}
	}
	void peek()
	{
		if (!is_empty())
		{
			cout << "�� ���� ���� : " << val[front] << endl;
		}
		else
		{
			cout << "peek() ���� : ť �������!" << endl;
		}
	}
};

int main()
{
	myQueue<int> q;
	q.enqueue(1);
	q.peek();
	q.enqueue(2);
	q.peek();
	q.enqueue(3);
	q.peek();

	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();
	return 0;
}