//2579
#include <bits/stdc++.h>
using namespace std;

int stairs;
int D[303][3]; //i: i��� ���� �� �ִ� ����, i������ ����
//j: ���� j�� ��� ����
int S[103];

int main(void)
{
	cin >> stairs;
	for (int i = 1;i <= stairs;i++)
		cin >> S[i];
	if (stairs == 1)
	{
		cout << S[1];
		return 0;
	}
	D[1][1] = S[1];
	D[1][2] = 0; //1���� �ι� �������� ����
	D[2][1] = S[2]; //2���� �ѹ� �����ؼ� ����
	D[2][2] = S[1] + S[2];
	for (int i = 3; i <= stairs;i++)
	{
		D[i][1] = max(D[i-2][1], D[i-2][2]) + S[i];
		D[i][2] = D[i - 1][1] + S[i];
	}
	cout << max(D[stairs][1], D[stairs][2]);
}