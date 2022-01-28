//1463
#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[1] = 0;
	//2부터 n까지 1이 될때 까지의 횟수를 미리 구해 놓고
	//횟수를 배열에 저장하여 뒤의 계산 시 저장된 값 불러서 쓰기
	for (int i = 2;i <= n;i++)
	{
		d[i] = d[i - 1] + 1;
		//6으로 나눠질 경우 고려하여 모두 if
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
		//cout << i << " " << d[i] << "\n";
	}
	cout << d[n];
}