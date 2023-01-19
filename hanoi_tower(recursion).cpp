//��ȯ �˰��� - �ϳ��� ž
#include <iostream>
using namespace std;

void hanoi_tower(int n, char from, char temp, char to)
{
	if (n == 1)
	{
		cout << from << "���� " << to << "�� ������ �ű��." << endl; //������ ���� ������ ����������
	}
	else
	{
		hanoi_tower(n - 1, from, to, temp); //n-1���� ������ �����
		cout << from << "���� " << to << "�� ������ �ű��." << endl; //���� �Ʒ��� ������ ����������
		hanoi_tower(n - 1, temp, from, to); //�������� ���ǵ� ����������
	}
}

int main()
{
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}