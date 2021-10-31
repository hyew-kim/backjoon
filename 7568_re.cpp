#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	vector<pair<int, int>> info;
	int N = 0;
	int rank = 1;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int height, weight = 0;

		cin >> height >> weight;
		info.push_back({ height, weight });
	}
	for (int i = 0; i < N;i++)
	{
		rank = 1;
		for (int j = 0;j < N;j++)
		{
			if (i == j) continue;
			if ((info[i].first > info[j].first)
				&& info[i].second > info[j].second)
				rank++;
			//rank: 자기보다 덩치큰사람 몇명?
		}
		cout << rank << " ";
	}
	return 0;
}