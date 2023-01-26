//원형 큐 알고리즘(배열)
#include <iostream>
using namespace std;
#define MAXSIZE 5

template<class T>
class myQueue
{
	int front;
	int rear;
	int size;
	T* val;
public:
	myQueue()
	{
		front = 0;
		rear = 0;
		size = MAXSIZE;
		val = new T[MAXSIZE];
	}
	~myQueue()
	{
		delete[] val;
	}
	bool is_full()
	{
		if (front == ((rear + 2) % MAXSIZE)) return true; //공백과 포화를 구분하기 위해, 항상 1개의 공간을 비워둔다.
		else return false;
	}
	bool is_empty()
	{
		if (front == rear) return true;
		else return false;
	}
	void enqueue(T item)
	{
		if (!is_full())
		{
			if (rear == MAXSIZE - 1)
			{
				val[rear] = item;
				rear = 0;
			}
			else
			{
				val[rear] = item;
				rear++;
			}
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
			if (front == MAXSIZE - 1)
			{
				val[front] = NULL;
				front = 0;
			}
			else
			{
				val[front] = NULL;
				front++;
			}
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
	q.enqueue(4);
	q.peek();

	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();

	cout << endl;

	//선형 큐와는 다르게, MAX값이 5이지만 공간이 남는다면 계속 사용 가능
	q.enqueue(1);
	q.peek();
	q.dequeue();
	q.enqueue(2);
	q.peek();
	q.dequeue();
	q.enqueue(3);
	q.peek();
	q.dequeue();
	q.enqueue(4);
	q.peek();
	q.dequeue();
	q.enqueue(5);
	q.peek();
	q.dequeue();
	q.enqueue(6);
	q.peek();
	q.dequeue();

	return 0;
}