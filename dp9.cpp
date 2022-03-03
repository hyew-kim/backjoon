//2302
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vip;
int d[42]; //fibo(n)°ª ÀúÀå

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int result = 1;

	cin >> N >> M;
	vip.resize(M);
	for (int i = 0;i < M;i++)
		cin >> vip[i];
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3;i <= N;i++)
		d[i] = d[i - 1] + d[i - 2];
	if (M == 0)
	{
		cout << d[N];
		return 0;
	}
	int start = 1;

	for (int i = 0;i < M;i++)
	{
		result *= d[vip[i] - start];
		start = vip[i] + 1;
	}
	result *= d[N - start + 1];
	cout << result;
}