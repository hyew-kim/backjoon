//4179
#include <bits/stdc++.h>

using namespace std;

int r, c;
char Map[1003][1003];
int dist_J[1003][1003];
int dist_F[1003][1003];
queue<pair<int, int>> J;
queue<pair<int, int>> F;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
//J는 only 1, F는 여려개일 수 있음
//F는 없을 수도 있음!!!! 이게 제일 중요
//dist -1로 초기화해서 0부터 시작일 경우 방문표시가 되도록 하자
int main(void)
{
	cin >> r >> c;
	for (int i = 0;i < r;i++)
	{
		fill(dist_J[i], dist_J[i] + c, -1);
		fill(dist_F[i], dist_F[i] + c, -1);
	}
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cin >> Map[i][j]; //#, J, F
			if (Map[i][j] == 'J')
			{
				J.push({ i,j });
				dist_J[i][j] = 0;
			}
			if (Map[i][j] == 'F')
			{
				F.push({ i,j });
				dist_F[i][j] = 0;
			}
		}
	}
	while (!F.empty())
	{
		auto current_F = F.front();
		F.pop();
		for (int i = 0;i < 4;i++)
		{
			int x = current_F.first + dx[i];
			int y = current_F.second + dy[i];
			if (x >= 0 && x < r && y >= 0 && y < c)
			{
				//. && J
				if (Map[x][y] != '#' && dist_F[x][y] < 0)
				{
					dist_F[x][y] = dist_F[current_F.first][current_F.second] + 1;
					F.push({ x,y });
				}
			}
		}
	}
	while (!J.empty())
	{
		auto current_J = J.front();
		J.pop();

		for (int i = 0;i < 4;i++)
		{
			//(x,y) 이동하려는 위치, current_J 현재 위치
			int x = current_J.first + dx[i];
			int y = current_J.second + dy[i];
			if (x < 0 ||  x >= r || y < 0 || y >= c)
			{
				cout << dist_J[current_J.first][current_J.second] + 1 << "\n";
				return 0;
			}
			if (Map[x][y] != '#' && dist_J[x][y] < 0)
			{
				//불이 도착한 적이 없고, 도착했더라도 J 보다 늦게 도착해야함
				if(dist_F[x][y] == -1 || dist_F[x][y] > dist_J[current_J.first][current_J.second] + 1)
				{
					dist_J[x][y] = dist_J[current_J.first][current_J.second] + 1;
					J.push({ x,y });
				}
			}
		}
	}
	cout << "IMPOSSIBLE" <<"\n";
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cout << dist_F[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cout << dist_J[i][j] << " ";
		}
		cout << "\n";
	}
}