//9095
#include <bits/stdc++.h>
using namespace std;

int D[13];
int n;

int main(void)
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		cin >> n;
		D[1] = 1;
		D[2] = 2;
		D[3] = 4;
		for (int i = 4;i <= n;i++)
			D[i] = D[i - 1] + D[i - 2] + D[i - 3];
		cout << D[n] << "\n";
	}
}

// for을 n의 범위까지 다 돌려놓고 D[n]을 입력 받은대로
//출력하는게 효율적
