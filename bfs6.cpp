//2206
#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dist[1004][1004][2];
int board[1004][1004];
queue<pair<pair<int, int>, int>> q;

int bfs(void)
{
	q.push({{ 0,0 },0});
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	while (!q.empty()) // 벽을 통과했을때, 안 통과했을 때 모두 q에 담겨서 종료조건 따로 필요함
	{
		auto current = q.front();
		q.pop();
		int current_x = current.first.first;
		int current_y = current.first.second;
		int status = current.second;

		if (current_x == N - 1 && current_y == M - 1)
			return dist[current_x][current_y][status];
		for (int i = 0;i < 4;i++)
		{
			int x = current_x + dx[i];
			int y = current_y + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= M || dist[x][y][status] != -1)
				continue;
			//벽 부순적 없음
			if (status == 0 && board[x][y] == 0)
			{
				dist[x][y][0] = dist[current_x][current_y][0] + 1;
				q.push({ { x,y },0 });
			}
			if (status == 0 && board[x][y] == 1)
			{
				dist[x][y][1] = dist[current_x][current_y][0] + 1;
				q.push({ { x,y },1 });
			}
			//벽 부순적 있음
			if (status && board[x][y] == 0)
			{
				dist[x][y][1] = dist[current_x][current_y][1] + 1;
				q.push({ { x,y },1 });
			}
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		string tmp = "";
		cin >> tmp;
		for (int j = 0;j < M;j++)
			board[i][j] = (tmp[j] - '0');
	}
	memset(dist, -1, sizeof(dist));
	cout << bfs();
}