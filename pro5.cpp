#include <bits/stdc++.h>

using namespace std;

vector<long long> solution(int n, int m)
{
	vector<long long> answer;
	long long mineral_water = 1;
	long long water_supply = 0;

	for (long long i = 2; i <= n; i++)
	{
		if (n % i == 0 && m % i == 0)
		{
			mineral_water = i;
		}
	}
	water_supply = mineral_water * (n / mineral_water) * (m / mineral_water);
	answer.push_back(mineral_water);
	answer.push_back(water_supply);

	return answer;
}

int main(void)
{
	long long a, b;
	cin >> a >> b;
	vector<long long> v = solution(a, b);
	for (long long e : v)
	{
		cout << e << " ";
	}
}