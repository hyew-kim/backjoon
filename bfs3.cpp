//2606
#include <bits/stdc++.h>

using namespace std;

int com, connection;
vector<vector<int>> graph(com + 1);
queue<int> q;
bool visted[103];
int cnt;

void bfs(int start)
{
	q.push(start);
	visted[start] = true;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0;i < graph[node].size();i++)
		{
			int node_new = graph[node][i];
			if (visted[node_new] == false)
			{
				cnt++;
				visted[node_new] = true;
				q.push(node_new);
			}
		}
	}
}

int main(void)
{
	cin >> com >> connection;
	for (int i = 0;i <= com;i++)
		graph.push_back(vector<int>());
	for (int i = 0;i < connection;i++)
	{
		int node1, node2=0;
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	bfs(1);
	cout << cnt <<"\n";
	for (int i = 0;i <= com;i++)
		cout << graph[i].size() << "\n";
	return 0;
}