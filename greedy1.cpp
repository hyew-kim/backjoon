//�ִ��� ���� �����⸦ ����
//���缺 : ������ �۾��� �ξ� �� ����
//Ƚ���� ���δ�.

#include <bits/stdc++.h>

using namespace std;

int cnt;
int n, k;

void one()
{
	cnt++;
	n -= 1;
	return;
}
void two()
{
	cnt++;
	n /= k;
	return;
}

int main(void)
{
	cin >> n >> k;
	while (n != 1)
	{
		if (n % k == 0)
			two();
		else
			one();
	}
	cout << cnt;
}
/*
 int n, k, result;
 int main()
 {
	while(true)
	{
		int target = (n / k) * k; 20
		result += (n - target); 
		n = target;
		if (n < k) break;
		result++; 1
		n / = k; 
	}
	result += (n - 1);

 */