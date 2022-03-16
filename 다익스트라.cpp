//1753
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
// first: 가중치, second: node 번호
vector<pair<int, int>> adj[20001];
int cost[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int u, v, w;

int main(void)
{
	cin >> V >> E >> K;
	fill(cost, cost + V + 1, 2147483647);
	for (int i = 0;i < E;++i)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	cost[K] = 0;
	pq.push({cost[K], K});
	while (!pq.empty())
	{//pq에서 거리가 최소인 순으로 정렬되어있음
		auto cur = pq.top();
		pq.pop();
		//cur.first = 거리, cur.second = 정점번호
		if (cur.first != cost[cur.second]) // 최단 거리가 아니면 pass
			continue; 
		for (auto next : adj[cur.second])
		{
			//next.first = 가중치, next.second = 정점번호
			if (cost[next.second] <= cost[cur.second] + next.first)
				continue;
			cost[next.second] = cost[cur.second] + next.first;
			pq.push({ cost[next.second], next.second });
		}
	}
	for (int i=1;i<=V;++i)
	{
		if (cost[i] == 2147483647)
			cout << "INF\n";
		else
			cout << cost[i] << "\n";
	}
}