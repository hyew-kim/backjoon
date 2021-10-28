#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N = 0;
	int sum = 2;
	int layer = 1;

	cin >> N;
	
	while (sum <= N)
	{
		layer++;
		sum += 6 * (layer - 1);
	}
	cout << layer;
	return 0;
}
