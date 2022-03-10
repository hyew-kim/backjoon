//2579
#include <bits/stdc++.h>
using namespace std;

int stairs;
int d[303];
//int D[303][3]; //i: i계단 도착 시 최대 점수, i무조건 밟음
//j: 현재 j개 계단 밟음
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
	D[1][2] = 0; //1층에 두번 점프에서 못옴
	D[2][1] = S[2]; //2층에 한번에 점프해서 오기
	D[2][2] = S[1] + S[2];
	for (int i = 3; i <= stairs;i++)
	{
		D[i][1] = max(D[i - 2][1], D[i - 2][2]) + S[i];
		D[i][2] = D[i - 1][1] + S[i];
	}
	cout << max(D[stairs][1], D[stairs][2]);
	*/
}