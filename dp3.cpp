//2579
#include <bits/stdc++.h>
using namespace std;

int stairs;
int d[303];
//int D[303][3]; //i: i��� ���� �� �ִ� ����, i������ ����
//j: ���� j�� ��� ����
int S[103];

int main(void)
{
	cin >> stairs;
	for (int i = 1;i <= stairs;i++)
		cin >> S[i];

	d[1] = S[1];
	d[2] = max(S[1] + S[2], S[2]);
	d[3] = max(S[1] + S[3], S[2] + S[3]);
	for (int i = 4;i <= stairs;++i)
	{
		d[i] = max(d[i - 3] + S[i - 1] + S[i], d[i - 2] + S[i]);
	}
	cout << d[stairs];
	/*
	D[1][1] = S[1];
	D[1][2] = 0; //1���� �ι� �������� ����
	D[2][1] = S[2]; //2���� �ѹ��� �����ؼ� ����
	D[2][2] = S[1] + S[2];
	for (int i = 3; i <= stairs;i++)
	{
		D[i][1] = max(D[i - 2][1], D[i - 2][2]) + S[i];
		D[i][2] = D[i - 1][1] + S[i];
	}
	cout << max(D[stairs][1], D[stairs][2]);
	*/
}