#include <iostream>
#include <queue>
#include <string.h>

#define X first
#define Y second

using namespace std;

int dist1[1000][1000]; //불
int dist2[1000][1000];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
string board[1000];
	
int main(void)
{
	int R = 0, C = 0;
	queue<pair<int, int>> move;
	queue<pair<int, int>> fire;

	memset(dist1, -1, sizeof(dist1));
	memset(dist2, -1, sizeof(dist2));
	cin >> R >> C;
	for (int i = 0;i < R;i++)
		cin >> board[i];
	for (int i = 0;i < R;i++)
	{
		for (int j = 0;j < C;j++)
		{
			if (board[i][j] == 'J')
			{
				move.push({ i,j });
				dist2[i][j] = 0;
			}
			else if (board[i][j] == 'F')
			{
				fire.push({ i,j });
				dist1[i][j] = 0;
			}
		}
	}
	/*while (!fire.empty())
	{
		auto cur = fire.front();
		fire.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny >= R || ny < 0 || ny >= C)
				continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			fire.push({ nx,ny });
		}
	}*/
	while (!fire.empty()) {
		auto cur = fire.front(); fire.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			fire.push({ nx,ny });
		}
	}
	while (!move.empty())
	{
		auto cur = move.front();
		move.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) // 동시 도착 아니면 이전에 도착
				continue;
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			move.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}