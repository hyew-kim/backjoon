//14502
#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int area = 0;
int areaMax = -9999;
int board[9][9];
int visted[9][9];
queue<pair<int, int>> q;
vector<pair<int, int>> virus;
vector<pair<int, int>> blank;


void bfs(void)
{
	for (int i = 0;i < virus.size();i++)
		q.push(virus[i]);
	while (!q.empty())
	{
		auto current = q.front();
		q.pop();
		visted[current.first][current.second] = 1;
		for (int i = 0;i < 4;i++)
		{
			int x = current.first + dx[i];
			int y = current.second + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= M)
				continue;
			if (visted[x][y] || board[x][y] != 0)
				continue;
			q.push({ x,y });

		}
	}
}

void solve(void)
{
	area = 0;
	memset(visted, 0, sizeof(visted));
	bfs();
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (board[i][j] == 0 && visted[i][j] == 0)
				area++;
		}
	}
	areaMax = max(area, areaMax);
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push_back({ i,j });
			else if (board[i][j] == 0)
				blank.push_back({ i,j });
		}
	}
	// nC3만큼 발생
	for (int i = 0;i < blank.size();i++)
	{
		for (int j = 0; j < i;j++)
		{
			for (int k = 0;k < j;k++)
			{
				board[blank[i].first][blank[i].second] = 1;
				board[blank[j].first][blank[j].second] = 1;
				board[blank[k].first][blank[k].second] = 1;
				solve();
				board[blank[i].first][blank[i].second] = 0;
				board[blank[j].first][blank[j].second] = 0;
				board[blank[k].first][blank[k].second] = 0;
			}
		}
	}
	cout << areaMax;
}