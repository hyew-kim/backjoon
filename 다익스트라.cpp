//1753
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
// first: ����ġ, second: node ��ȣ
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
	{//pq���� �Ÿ��� �ּ��� ������ ���ĵǾ�����
		auto cur = pq.top();
		pq.pop();
		//cur.first = �Ÿ�, cur.second = ������ȣ
		if (cur.first != cost[cur.second]) // �ִ� �Ÿ��� �ƴϸ� pass
			continue; 
		for (auto next : adj[cur.second])
		{
			//next.first = ����ġ, next.second = ������ȣ
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