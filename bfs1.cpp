#include <bits/stdc++.h>

using namespace std;

//1260 
//¾ç¹æÇâ node

int n, m;
int start;
int graph[1003][1003];
bool visted[1003];
queue<int> q;

void dfs(int node)
{
	if (visted[node] == false)
	{
		cout << node << " ";
		visted[node] = true;
		for (int i = 1;i <= n;i++)
		{
			if (graph[node][i])
			{
				dfs(i);
			}
		}
	}
}
void bfs(int node)
{
	q.push(node);
	visted[node] = true;
	while (q.empty() == false)
	{
		int next_node = q.front();
		cout << next_node << " ";
		q.pop();
		for (int i = 1;i <= n;i++)
		{
			if (graph[next_node][i] && visted[i] == false)
			{
				q.push(i);
				visted[i] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;
	for (int i = 0;i < m;i++)
	{
		int node1, node2 = 0;
		cin >> node1 >> node2;
		graph[node1][node2] = 1;
		graph[node2][node1] = 1;
	}
	dfs(start);
	memset(visted, 0, sizeof(visted));
	cout << "\n";
	bfs(start);
}