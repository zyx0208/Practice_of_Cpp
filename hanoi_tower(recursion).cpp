//순환 알고리즘 - 하노이 탑
#include <iostream>
using namespace std;

void hanoi_tower(int n, char from, char temp, char to)
{
	if (n == 1)
	{
		cout << from << "에서 " << to << "로 원판을 옮긴다." << endl; //마지막 남은 원판을 오른쪽으로
	}
	else
	{
		hanoi_tower(n - 1, from, to, temp); //n-1개의 원판을 가운데로
		cout << from << "에서 " << to << "로 원판을 옮긴다." << endl; //가장 아래의 원판을 오른쪽으로
		hanoi_tower(n - 1, temp, from, to); //나머지의 원판도 오른쪽으로
	}
}

int main()
{
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}