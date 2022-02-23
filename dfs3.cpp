//2573
#include <bits/stdc++.h>
using namespace std;

int N, M;
int ice[301][301];
bool visted[301][301];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void dfs(int x, int y)
{
	visted[x][y] = true;
	for (int i = 0;i < 4;i++)
	{
		int _x = x + dx[i];
		int _y = y + dy[i];
		if (_x < 0 || _x >= N || _y < 0 || _y >= M)
			continue;
		if (visted[_x][_y] || ice[_x][_y] == 0)
			continue;
		dfs(_x, _y);
	}
	return;
}
void melt(void)
{
	int tmp[301][301] = {0};
	memcpy(tmp, ice, sizeof(ice));
	for (int i = 1;i < N - 1;i++)
	{
		for (int j = 1;j < M - 1;j++)
		{
			if (ice[i][j] > 0)
			{
				for (int k = 0;k < 4;k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || x >= N || y < 0 || y >= M)
						continue;
					if (tmp[x][y] == 0 && ice[i][j] > 0)
						ice[i][j]--;
				}
			}
		}
	}
	return;
}
int main(void)
{
	//pair<int, int> start;
	int year = 0;
	int max_height = -9999;

	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
			cin >> ice[i][j];
	}
	//여러겹에 쌓인 빙하는 10 이상의 시간이 걸림
	while (1)
	{
		int cnt = 0;
		memset(visted, 0, sizeof(visted));
		for (int i = 1;i < N - 1;i++)
		{
			for (int j = 1;j < M - 1;j++)
			{
				if (ice[i][j] > 0 && visted[i][j] == 0)
				{
					cnt++;
					dfs(i, j);
					if (cnt >= 2)
					{
						cout << year;
						return 0;
					}
				}
			}
		}
		//남은 빙하가 하나도 없당
		if (cnt == 0)
			break;
		melt();
		year++;
	}
	cout << 0;
}