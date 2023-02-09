//��ũ�帮��Ʈ(int��) �˰���
#include <iostream>
using namespace std;

class myNode //���
{
public:
	int val;
	myNode* link;
};

class myLinkedList //��带 �����ϴ� ����Ʈ
{
	myNode* head;
	int size;
public:
	myLinkedList()
	{
		head = nullptr;
		size = 0;
	}
	void push(int val)
	{
		myNode* temp = new myNode;
		temp->val = val;
		temp->link = head;
		head = temp;
		size++;
	}
	void pop(int val)
	{
		bool is_exist = true;
		if (head->val == val)
		{
			head = head->link;
			size--;
		}
		else
		{
			myNode* d = head;
			for (int i = 0; i < size; i++, d = d->link)
			{
				if (d->link->val == val)
				{
					break;
				}
				if (size == i + 1)
				{
					cout << "�ش� ���� �������� ����" << endl;
					is_exist = false;
				}
			}
			if (is_exist)
			{
				d->link = d->link->link;
				size--;
			}
		}
	}
	void print_list()
	{
		cout << "| ";
		myNode* d = head;
		for (int i = 0; i < size; i++, d = d->link)
		{
			cout << d->val << " | ";
		}
		cout << endl;
	}
};

int main()
{
	myLinkedList l;
	l.push(1);
	l.print_list();
	l.push(2);
	l.print_list();
	l.push(3);
	l.print_list();
	l.push(4);
	l.print_list();
	l.push(5);
	l.print_list();

	cout << endl;

	l.pop(5);
	l.print_list();
	l.pop(1);
	l.print_list();
	l.pop(3);
	l.print_list();
	l.pop(2);
	l.print_list();
	l.pop(4);
	l.print_list();

	return 0;
}