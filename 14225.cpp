#include <iostream>
#include <set>

using namespace std;
int		N;
int		arr[23];
int		sum_max;
set<int>s;

void	func(int idx, int sum)
{
	if (idx == N)
	{
		s.insert(sum);
		return;
	}
	func(idx + 1, sum);
	func(idx + 1, sum + arr[idx]);
	return;
}

int main(void)
{
		cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
		sum_max += arr[i];
	}
	func(0,0);
	for (int i = 1;i <= sum_max;i++)
	{
		if (s.find(i) == s.end())
		{
			cout << i;
			return 0;
		}
	}
	cout << sum_max + 1;
	return 0;
}