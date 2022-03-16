//10816
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
vector<int> card;
string res;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	card.resize(N);
	for (int i = 0;i < N;++i)
		cin >> card[i];
	sort(card.begin(), card.end());
	cin >> M;
	for (int i = 0;i < M;++i)
	{
		int num = 0;
		cin >> num;
		if (binary_search(card.begin(), card.end(), num))
			res += "1 ";
		else
			res += "0 ";
	}
	cout << res;
}