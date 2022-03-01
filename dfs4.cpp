//1707
#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector <int> graph[20002];
int visted[20002];

bool isBipartited(void)
{
	for (int i = 1;i <= V;i++)
	{
		if (visted[i])
		{
			for (int j = 0;j < graph[i].size();j++)
			{
				int node = graph[i][j];
				if (visted[i] == visted[node])
					return false;
			}
		}
	}
	return true;
}

void dfs(int start)
{
	//1 RED, 2 BLUE
	for (int i = 0;i < graph[start].size();i++)
	{
		int node = graph[start][i];
		if (!visted[node])
		{
			//연결 노드의 색은 시작노드의 색 기준!
			if (visted[start] == 1)
				visted[node] = 2;
			else if (visted[start] == 2)
				visted[node] = 1;
			dfs(node);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	while (K--)
	{
		cin >> V >> E;
		for (int i = 1;i <= V;i++)
			graph[i].clear();
		memset(visted, 0, sizeof(visted));
		for (int i = 0;i < E;i++)
		{
			int node1, node2 = 0;
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
		for (int i = 1;i <= V;i++)
		{
			if (!visted[i])
			{
				//시작은 무조건 red!
				visted[i] = 1;
				dfs(i);
			}
		}
		cout << (isBipartited() ? "YES": "NO")<<"\n";
	}
}