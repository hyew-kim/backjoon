#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, M = 0;
	set<int>num;

	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int tmp = 0;
		cin >> tmp;
		num.insert(tmp);
	}
	cin >> M;
	for (int i = 0;i < M;i++)
	{
		int nbr = 0;
		cin >> nbr;
		if (num.find(nbr) != num.end())
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}