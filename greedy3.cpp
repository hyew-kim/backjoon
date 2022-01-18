//최소 그룹수 -> 낮은 공포도부터 결성
//왜냐하면 모든 모험가가 그룹을 결성할 필요X

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N = 0;
	cin >> N;
	vector<int> man(N);
	int group = 0;
	for (int i = 0;i < N;i++)
		cin >> man[i];
	sort(man.begin(), man.end());
	int i = 0;
	int man_cnt = 0;
	while (i < N)
	{
		man_cnt += man[i];
		//greedy는 실제로 실행해보는 편인듯
		if (man_cnt >= man[i])
		{
			man_cnt = 0;
			group++;
		}
		i++;
	}
	cout << group;
}