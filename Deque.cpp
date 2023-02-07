//덱 알고리즘(배열)
#include <iostream>
using namespace std;
#define MAXSIZE 5

template<class T>
class myDeque
{
	int front;
	int rear;
	int size;
	T* val;
public:
	myDeque()
	{
		front = 0;
		rear = 0;
		size = MAXSIZE;
		val = new T[MAXSIZE];
	}
	~myDeque()
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
	void add_front(T item)
	{
		if (!is_full())
		{
			if (front == 0)
			{
				val[front] = item;
				front = MAXSIZE - 1;
			}
			else
			{
				val[front] = item;
				front--;
			}
		}
		else
		{
			cout << "add_front() 실패 : 덱 가득참!" << endl;
		}
	}
	void add_rear(T item)
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
			cout << "add_rear() 실패 : 덱 가득참!" << endl;
		}
	}
	void delete_front()
	{
		if (!is_empty())
		{
			if (front == MAXSIZE - 1)
			{
				front = 0;
				val[front] = NULL;
			}
			else
			{
				front++;
				val[front] = NULL;
			}
		}
		else
		{
			cout << "delete_front() 실패 : 덱 비어있음!" << endl;
		}
	}
	void delete_rear()
	{
		if (!is_empty())
		{
			if (rear == 0)
			{
				rear = MAXSIZE - 1;
				val[rear] = NULL;
			}
			else
			{
				rear--;
				val[rear] = NULL;
			}
		}
		else
		{
			cout << "delete_rear() 실패 : 덱 비어있음!" << endl;
		}
	}
	void get_front()
	{
		if (!is_empty())
		{
			if (front == MAXSIZE - 1)
			{
				cout << "맨 앞 : " << val[0] << endl;
			}
			else
			{
				cout << "맨 앞 : " << val[front + 1] << endl;
			}
		}
		else
		{
			cout << "get_front() 실패 : 덱 비어있음!" << endl;
		}
	}
	void get_rear()
	{
		if (!is_empty())
		{
			if (rear == 0)
			{
				cout << "맨 뒤 : " << val[MAXSIZE - 1] << endl;
			}
			else
			{
				cout << "맨 뒤 : " << val[rear - 1] << endl;
			}
		}
		else
		{
			cout << "get_rear() 실패 : 덱 비어있음!" << endl;
		}
	}
};

int main()
{
	myDeque<int> d;
	d.add_front(1);
	d.get_front();
	d.add_front(2);
	d.get_front();
	d.delete_front();
	d.get_front();
	d.delete_front();
	d.get_front();

	d.add_rear(1);
	d.get_rear();
	d.add_rear(2);
	d.get_rear();
	d.delete_rear();
	d.get_rear();
	d.delete_rear();
	d.get_rear();

	return 0;
}