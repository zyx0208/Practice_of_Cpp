//���� ť �˰���(�迭)
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
		if (front == ((rear + 2) % MAXSIZE)) return true; //����� ��ȭ�� �����ϱ� ����, �׻� 1���� ������ ����д�.
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
			cout << "enqueue() ���� : ���� ������!" << endl;
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
	q.enqueue(4);
	q.peek();

	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();

	cout << endl;

	//���� ť�ʹ� �ٸ���, MAX���� 5������ ������ ���´ٸ� ��� ��� ����
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