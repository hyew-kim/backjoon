#include <bits/stdc++.h>

using namespace std;

int N;
int height[102][102];
bool safe[102][102];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int area;
int min_height = 1000;
int max_height = -1000;

void dfs(int x, int y)
{
	//cout << x << ", " << y << "\n";
	safe[x][y] = 0;
	for (int i = 0;i < 4;i++)
	{
		int x1 = x + dx[i];
		int y1 = y + dy[i];

		if (x1 >= 0 && x1 < N && y1 >= 0 && y1 < N)
		{
			if (safe[x1][y1] == 1)
				dfs(x1, y1);
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> height[i][j];
			if (max_height < height[i][j])
				max_height = height[i][j];
		}
	}

	int current_height = 0;
	//모든 지역1, 비 안옴 생각해보셈 ㅎ
	while (current_height < max_height)
	{
		memset(safe, 0, sizeof(safe));
		int area_tmp = 0;

		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				if (height[i][j] > current_height)
					safe[i][j] = 1;
			}
		}
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				if (safe[i][j] == 1)
				{
					//cout << "START: " << i << ", " << j << "\n";
					dfs(i, j);
					area_tmp++;
					if (area < area_tmp)
						area = area_tmp;
				}
			}
		}
		current_height++;3
	}
	cout << area;
}
