//11779
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, st, ed;
// first: 가중치, second: node 번호
vector<pair<int, int>> adj[1001];
int cost[1001];
int pre[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int u, v, w;

int main(void)
{
	cin >> V >> E;
	fill(cost, cost + V + 1, 2147483647);
	for (int i = 0;i < E;++i)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	cin >> st >> ed;
	cost[st] = 0;
	pq.push({ cost[st], st });
	while (!pq.empty())
	{//pq에서 비용이 최소인 순으로 정렬되어있음
		auto cur = pq.top();
		pq.pop();
		//cur.first = 비용, cur.second = 정점번호
		if (cur.first != cost[cur.second]) // 최소 비용이 아니면 pass
			continue;
		for (auto next : adj[cur.second])
		{
			//next.first = 가중치, next.second = 정점번호
			if (cost[next.second] <= cost[cur.second] + next.first)
				continue;
			cost[next.second] = cost[cur.second] + next.first;
			pre[next.second] = cur.second;
			pq.push({ cost[next.second], next.second });
		}
	}
	int city = ed;
	vector<int> track;
	while (city != st)
	{
		track.push_back(city);
		city = pre[city];
	}
	track.push_back(city);
	cout << cost[ed] << "\n" << track.size() << "\n";
	for (int i = track.size() - 1;i >= 0;--i)
		cout << track[i] << " ";
}