//2805
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll M;
vector<int> tree;

bool solve(ll H)
{
	ll piece = 0;
	for (auto i = 0;i < N;i++)
	{
		if (tree[i] - H >= 0)
			piece += (tree[i] - H);
	}
	return (piece >= M);
}

int main(void)
{
	cin >> N >> M;
	tree.resize(N);
	for (auto i = 0;i < N;i++)
		cin >> tree[i];
	ll st = 0;
	//ll en = 2000000000;
	ll en = *max_element(tree.begin(), tree.end());
	while (st < en)
	{
		ll mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;
}