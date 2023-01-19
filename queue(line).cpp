//선형 큐 알고리즘(배열)
//선형 큐 문제점 : 배열에서 front가 증가하기 때문에, 비어있는 배열 자리가 생김
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
			cout << "enqueue() 실패 : 스택 가득참!" << endl;
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
			cout << "dequeue() 실패 : 큐 비어있음!" << endl;
		}
	}
	void peek()
	{
		if (!is_empty())
		{
			cout << "맨 앞의 원소 : " << val[front] << endl;
		}
		else
		{
			cout << "peek() 실패 : 큐 비어있음!" << endl;
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