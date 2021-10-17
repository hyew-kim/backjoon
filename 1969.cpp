#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main(void)
{
	int N = 0, M = 0;
	int HD = 0;
	string res;

	cin >> N >> M;
	vector<string>v(N);
	for (int i = 0;i < N;i++)
		cin >> v[i];
	for (int i = 0;i < M;i++)
	{
		int alpha[26] = { 0 };
		int max = 0;
		int cnt = 0;

		for (int j = 0;j < N;j++)
		{
			alpha[v[j][i] - 'A']++;
		}
		for (int k = 0;k < 26;k++)
		{
			if (alpha[k] > cnt)
			{
				cnt = alpha[k]; // 알파값은 알파벳의 빈도수
				max = k;
			}
		}
		HD += (N - cnt);
		res += max + 'A';
	}
	cout << res << "\n" << HD;
	return 0;
}