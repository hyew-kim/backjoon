#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int N = 0;
	int sum = 0;
	int vis[8001]= { 0 };
	int most_vis_cnt = -1;
	bool not_first = false;
	int most_vis_val = 0;
	cin >> N;
	vector<int>v(N);
	for (int i = 0;i < N;i++)
	{
		cin >> v[i];
		sum += v[i];
		vis[v[i] + 4000]++;
	} 
	sort(v.begin(), v.end());
	for (int i = 0;i < 8001;i++)
	{
		if (vis[i])
		{
			if (most_vis_cnt < vis[i])
			{
				most_vis_cnt = vis[i];
				most_vis_val = i - 4000;
				not_first = true;
			}
			else if (most_vis_cnt == vis[i]) // 최빈값 여러개인 상황
			{
				if (not_first)
				{
					most_vis_val = i - 4000;
					not_first = false;
				}
			}
		}
	}
	cout << round(sum / (double)N) << "\n" << v[round(N / 2)] <<"\n" << most_vis_val << "\n" << v[N - 1] - v[0];
	return 0;
}