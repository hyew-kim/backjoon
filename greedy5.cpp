//11399
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N = 0;
	cin >> N;
	vector<int> time(N);
	for (int i = 0;i < N;i++)
		cin >> time[i];
	sort(time.begin(), time.end());
	int res = 0;
	for (int i = 0;i < N;i++)
		res += time[i] * (N - i);
	cout << res;
}