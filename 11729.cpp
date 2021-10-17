#include <iostream>
#include <math.h>

using namespace std;

void	move(int a, int b, int n) // n개 판을 a에서 b로 이동
{
	if (n == 1)// 1개 옮김
	{
		cout << a << " " << b << "\n";
		return;
	}
	move(a, 6 - a - b, n - 1); // n-1개 옮김 
	cout << a << " " << b << "\n"; //n개 옮기기도 쌉가능
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