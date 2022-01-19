#include <bits/stdc++.h>
using namespace std;

int n, m; //n: 수의 범위, m: 칸의 수
int arr[10];
bool isused[10];

//k: 채워진 자릿수
void func(int k) {
	if (k == m) {
		for (int i = 0;i < m;i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!isused[i])
		{
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
			//cout << i << ' ' << "\n";
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}