#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	set<int> s;
	int N = 0, K = 0;

	cin >> N >> K;
	for (int i = 0;i < N;i++)
	{
		int tmp = 0;
		cin >> tmp;
		s.insert(tmp);
	}
	for (auto it = s.begin();it != s.end();it++)
	{
		if (K == 1)
		{
			cout << *it;
			break;
		}
		K--;
	}
	return 0;
}