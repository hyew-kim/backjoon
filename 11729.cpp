#include <iostream>
#include <math.h>

using namespace std;

void	move(int a, int b, int n) // n�� ���� a���� b�� �̵�
{
	if (n == 1)// 1�� �ű�
	{
		cout << a << " " << b << "\n";
		return;
	}
	move(a, 6 - a - b, n - 1); // n-1�� �ű� 
	cout << a << " " << b << "\n"; //n�� �ű�⵵ �԰���
	move(6 - a - b, b, n - 1);
}
int main(void)
{
	int K = 0;
	cin >> K;
	cout << (int)(pow(2, K) - 1) << "\n";
	move(1, 3, K);
	return 0;
}