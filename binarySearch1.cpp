//10816
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> card;

int _search(int num)
{
	int find = 0;
	int start = 0;
	int end = card.size() - 1;

	while (1)
	{
		int idx = (end + start) / 2 ;
		if (end < start)
			break;
		if (card[idx] == num)
		{
			find++;
			break;
		}
		else if (card[idx] > num)
			end = idx - 1;
		else
			start = idx + 1;
	}
	return find;
	// 8 10 10 10 
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	card.resize(N);
	for (int i = 0;i < N;i++)
		cin >> card[i];
	sort(card.begin(), card.end());
	cin >> M;
	for (int i = 0;i < M;i++)
	{
		int num = 0;
		cin >> num;
		cout << upper_bound(card.begin(), card.end(),num)- lower_bound(card.begin(), card.end(), num) << " ";
	}
}