//11779
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, st, ed;
// first: ����ġ, second: node ��ȣ
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
	{//pq���� ����� �ּ��� ������ ���ĵǾ�����
		auto cur = pq.top();
		pq.pop();
		//cur.first = ���, cur.second = ������ȣ
		if (cur.first != cost[cur.second]) // �ּ� ����� �ƴϸ� pass
			continue;
		for (auto next : adj[cur.second])
		{
			//next.first = ����ġ, next.second = ������ȣ
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