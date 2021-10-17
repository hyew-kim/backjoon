#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int map[8][8];
bool vis[8][8];
vector<pair<int, int>> virus;
vector<pair<int, int>> space;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;

void	dfs(pair<int, int> pos) // 바이러스 실제로 퍼트려보기
{
	for (int dir = 0;dir < 4;dir++)
	{
		int nx = pos.X + dx[dir];
		int ny = pos.Y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (map[nx][ny] != 0 || vis[nx][ny])
			continue;
		vis[nx][ny] = 1;
		dfs({ nx,ny });
	}
	return;
}
int		solve(void) // 안전범위 세기
{
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	
	for (int i = 0;i < virus.size();i++)
	{
		auto pos = virus[i];
		vis[pos.X][pos.Y] = 1;
		dfs(pos);
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (map[i][j] == 0 && vis[i][j] == 0) // 바이러스가 퍼지지 않은 영역 세기
				cnt++;
		}
	}
	return cnt;
}
int main(void)
{
	int cnt_max = 0;

	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i,j });
			else if (map[i][j] == 0)
				space.push_back({ i,j });
		}
	}
	for (int i = 0;i < space.size();i++)
	{
		for (int j = 0;j < i;j++)
		{
			for (int k = 0;k < j;k++)
			{
				map[space[i].X][space[i].Y] = 1;
				map[space[j].X][space[j].Y] = 1;
				map[space[k].X][space[k].Y] = 1;
				cnt_max = max(cnt_max, solve());
				map[space[i].X][space[i].Y] = 0;
				map[space[j].X][space[j].Y] = 0;
				map[space[k].X][space[k].Y] = 0;
			}
		}
	}
	cout << cnt_max;
	return 0;
}