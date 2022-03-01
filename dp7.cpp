//1149
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v[1002];
int d[1002][3];

int main(void)
{
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		v[i].resize(3); //R G B
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	d[2][0] = (min(v[1][1], v[1][2]) + v[2][0]);
	d[2][1] = (min(v[1][0], v[1][2]) + v[2][1]);
	d[2][2] = (min(v[1][0], v[1][1]) + v[2][2]);
	for (int i = 3;i <= N;i++)
	{
		d[i][0] = v[i][0] + min(d[i - 1][1], d[i - 1][2]);
		d[i][1] = v[i][1] + min(d[i - 1][0], d[i - 1][2]);
		d[i][2] = v[i][2] + min(d[i - 1][0], d[i - 1][1]);
	}
	cout << *min_element(d[N], d[N] + 3);
}