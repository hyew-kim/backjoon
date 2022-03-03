//9465
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int score[2][100002];
int d[100002][2];

int main(void)
{
	int T = 0;
	cin >> T;
	while (T-- > 0)
	{
		cin >> N;
		memset(score, 0, sizeof(score));
		memset(d, 0, sizeof(d));
		for (int i = 0;i < 2;i++)
		{
			for (int j = 1;j <= N;j++)
			{
				cin >> score[i][j];
			}
		}
		d[1][0] = score[0][1];
		d[1][1] = score[1][1];
		d[2][0] = score[0][2] + d[1][1];
		d[2][1] = score[1][2] + d[1][0];
		for (int i = 3;i <= N;i++)
		{
			d[i][0] = score[0][i] + max(d[i - 1][1], max(d[i - 2][0], d[i - 2][1]));
			d[i][1] = score[1][i] + max(d[i - 1][0], max(d[i - 2][0], d[i - 2][1]));
		}
		cout << max(d[N][0], d[N][1]) << "\n";
	}
}