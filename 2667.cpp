#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string map[25];
vector<int> house;
int cnt = 0;
int idx = 1;
int N = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void	bsf(int x, int y)
{
	cnt++;
	map[x][y] = idx;
	for (int dir = 0;dir < 4;dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (map[nx][ny] != '1')
			continue;
		bsf(nx, ny);
	}
	return;
}
int main(void)
{
	cin >> N;

	for (int i = 0;i < N;i++)
		cin >> map[i];
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			if (map[i][j] == '1')
			{
				cnt = 0;
				idx++;
				bsf(i, j);
				house.push_back(cnt);
			}
		}
	}
	sort(house.begin(), house.end());
	cout << idx - 1<< endl;
	for (int i = 0;i < house.size();i++)
		cout << house[i] << endl;
	return 0;
}