//1976
#include <bits/stdc++.h>
using namespace std;

int N, M;
int group[1004];

int find(int city)
{
	if (group[city] == city)
		return city;
	else
		return (group[city] = find(group[city]));
}

void join(int i, int j)
{
	//i, j는 좌표값, city 번호로 바꿔줘야함
	//양방향으로 city가 연결되어있으니 한번만 join하면 된당
	if (i < j)
		group[find(j + 1)] = find(i + 1);
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1;i <= N;i++)
		group[i] = i;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			int city = 0;
			cin >> city;
			if (city)
				join(i, j);
		}
	}
	int department = 0;
	for (int i = 0;i < M;i++)
	{
		int trip = 0;
		cin >> trip;
		if (i == 0)
			department = find(trip);
		else if (department != find(trip))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}