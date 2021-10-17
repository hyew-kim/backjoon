#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define X first
#define Y second

bool	compare(pair<int, int>pos1, pair<int, int>pos2)
{
	if (pos1.Y == pos2.Y)
		return (pos1.X < pos2.X);
	return (pos1.Y < pos2.Y);
}

int main(void)
{
	int N = 0;

	cin >> N;
	vector<pair<int, int>>v(N);
	for (int i = 0;i < N;i++)
	{
		cin >> v[i].X >> v[i].Y;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0;i < N;i++)
	{
		cout << v[i].X << " " << v[i].Y << endl;
	}
	return 0;
}