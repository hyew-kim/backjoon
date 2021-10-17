#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int N = 0;
	set<int> s;

	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int tmp = 0;
		cin >> tmp;
		s.insert(tmp);
	}
	for (auto i = s.begin();i != s.end(); i++)
		cout << *i << "\n";
	return 0;
}