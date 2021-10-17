#include <iostream>
#include <queue>
#include <string>

using namespace std;
string yard[250];

bool vis[250][250] = { 0 };

int main(void)
{
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int R = 0, C = 0;
	int walf = 0;
	int sheep = 0;

	cin >> R >> C;
	for (int i = 0;i < R;i++)
		cin >> yard[i];
	for (int i = 0;i < R;i++)
	{
		for (int j = 0;j < C;j++)
		{
			queue<pair<int, int>> q;
			int live_sheep = 0;
			int live_walf = 0;

			if (vis[i][j] || yard[i][j] == '#')
				continue;
			vis[i][j] = true;
			if (yard[i][j] == 'o')
			{
				sheep++;
				live_sheep++;
			}
			else if (yard[i][j] == 'v')
			{
				walf++;
				live_walf++;
			}
			q.push({ i,j });
			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0;dir < 4;dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C)
						continue;
					if (vis[nx][ny] || yard[nx][ny] == '#')
						continue;
					vis[nx][ny] = true;
					if (yard[nx][ny] == 'o')
					{
						sheep++;
						live_sheep++;
					}
					else if (yard[nx][ny] == 'v')
					{
						walf++;
						live_walf++;
					}
					q.push({ nx,ny });
				}
			}
			if (live_sheep <= live_walf)
				sheep -= live_sheep;
			else
				walf -= live_walf;
		}
	}
	cout << sheep << " " << walf;
	return 0;
}