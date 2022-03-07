#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
//UNION FIND
//집합
/*
int n, m;
vector<int> group;

int find(int node)
{
	if (group[node] == node)
		return node;
	else
		return(group[node] = find(group[node]));
}

void join(int node1, int node2)
{
	group[node2] = node1;
	return;
}

int main(void)
{
	int flag = 0;
	int a = 0;
	int b = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	group.resize(n + 1);
	for (int i = 1;i <= n;i++)
		group[i] = i;
	for (int i = 0;i < m;i++)
	{
		cin >> flag >> a >> b;
		if (flag == 0)
		{
			if (a <= b)
				join(find(a), find(b));
			else
				join(find(b), find(a));
		}
		else
		{
			if (find(a) == find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
}
*/
//BFS
//토마토
/*
int N, M;
int dist[1001][1001];
int board[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

int main(void)
{
	memset(dist, -1, sizeof(dist));
	cin >> M >> N;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				dist[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		auto start = q.front();
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int x = start.first + dx[i];
			int y = start.second + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= M)
				continue;
			if (dist[x][y] >= 0 || board[x][y] != 0)
				continue;
			dist[x][y] = dist[start.first][start.second] + 1;
			q.push({ x,y });
		}
	}
	int day = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (board[i][j] == 0)
			{
				if (dist[i][j] < 0)
				{
					cout << -1;
					return 0;
				}
				else
					day = max(day, dist[i][j]);
			}
		}
	}
	cout << day;
}
*/
/*
//DFS
//단지번호붙이기
int N;
int visted[26][26];
int board[26][26];
int cnt;
vector<int> house;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	cnt++;
	visted[x][y] = 1;
	//cout << x << ", " << y << "\n";
	for (int i = 0;i < 4;i++)
	{
		int _x = x + dx[i];
		int _y = y + dy[i];
		if (_x < 0 || _x >= N || _y < 0 || _y >= N)
			continue;
		if (visted[_x][_y] == 1 || board[_x][_y] != 1)
			continue;
		dfs(_x, _y);
	}
	return;
}

int main(void)
{
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0;j < N;j++)
			board[i][j] = (s[j] - '0');
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (board[i][j] == 1 && visted[i][j] == 0)
			{
				cnt = 0;
				dfs(i, j);
				house.push_back(cnt);
			}
		}
	}
	cout << house.size() << "\n";
	sort(house.begin(), house.end());
	for (int i = 0;i < house.size();i++)
		cout << house[i] << "\n";
}*/


//BFS GOLD
//벽 부수고 이동하기

int N, M;
int board[1001][1001];
int visted[1001][1001];
//queue<pair<pair<int, int>, int>> q;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cnt;
int flag = 1;
vector<int> area; //area[0] -> flag = 1의 총 넓이

void dfs(int x, int y)
{
	cnt++;
	visted[x][y] = flag; // 구역에 따라 index 부여
	for (int i = 0;i < 4;i++)
	{
		int _x = x + dx[i];
		int _y = y + dy[i];
		if (_x < 0 || _x >= N || _y < 0 || _y >= M)
			continue;
		if (visted[_x][_y] || board[_x][_y] != 0)
			continue;
		dfs(_x, _y);
	}
	return;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0;j < M;j++)
			board[i][j] = (s[j] - '0');
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (board[i][j] == 0 && visted[i][j] == 0)
			{
				dfs(i, j);
				flag++;
				area.push_back(cnt % 10);
				cnt = 0;
			}
		}
	}
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (board[i][j] == 1)
			{
				set<int> index;
				int newArea = 0;
				for (int k = 0;k < 4;k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];

					if (x < 0 || x >= N || y < 0 || y >= M)
						continue;
					if (board[x][y] == 0)
					{
						if (index.find(visted[x][y]) == index.end())
						{
							index.insert(visted[x][y]);
							newArea += area[visted[x][y] - 1];
						}
					}
				}
				cout << (newArea + 1) % 10;
			}
			else
				cout << 0;
		}
		cout << "\n";
	}
}
//bfs 다른 심화 문제

//분할정복

//백트래킹