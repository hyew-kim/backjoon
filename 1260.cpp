#include <bits/stdc++.h>

using namespace std;

vector<bool>visited(1002);
int board[1002][1002];
int N, M;
void dfs(int start)
{
	visited[start] = true;
	cout << start << " ";
	for (int i = 0;i <= N;i++)
	{
		if (board[start][i] == 1 && visited[i] == false)
			dfs(i); //i가 연결된 지점
	}
	return;
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!(q.empty()))
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int y = 0;y <= N;y++)
		{
			if (board[x][y] == 1 && visited[y] == false)
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
	return;
}

int main(void)
{
	int V;
	cin >> N >> M >> V;
	
	for (int i = 0;i < M;i++)
	{
		int p1, p2;
		cin >> p1 >> p2;
		board[p1][p2] = 1;
		board[p2][p1] = 1;
	}
	dfs(V);
	visited.clear();
	visited.assign(1002, false);
	cout << "\n";
	bfs(V);
	return 0;
}