//�ּ� �׷�� -> ���� ���������� �Ἲ
//�ֳ��ϸ� ��� ���谡�� �׷��� �Ἲ�� �ʿ�X

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
		//greedy�� ������ �����غ��� ���ε�
		if (man_cnt >= man[i])
		{
			man_cnt = 0;
			group++;
		}
		i++;
	}
	cout << group;
}