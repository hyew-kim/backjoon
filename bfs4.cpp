//5014
//������ �������� �� �� �ִ� �ִܰ��-> bfs
#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
// floor : 1~F
vector<int> visted;
queue<pair<int, int>> q;
int dx[2];

void bfs(int start)
{
	q.push({ S,0 });
	visted[start] = 1;
	while (!q.empty())
	{
		auto node = q.front();
		if (node.first == G)
		{
			cout << node.second;
			return;
		}
		q.pop();
		for (int i = 0;i < 2;i++)
		{
			int next = node.first + dx[i];
			//�湮�� ���� pass�� �ֳ� �ּҷ� ���������ϴϱ�
			if (next < 1 || next > F || visted[next])
				continue;
			visted[next] = 1;
			q.push({ next, node.second + 1 });
		}
	}
	cout << "use the stairs";
	return;
}

int main(void)
{
	cin >> F >> S >> G >> U >> D;
	dx[0] = U;
	dx[1] = -D;
	visted.resize(F + 1);
	bfs(S);
	return 0;
}