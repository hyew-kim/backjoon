//17070
#include <iostream>
#include <vector>
using namespace std;

int N;
int board[17][17];
int cnt;
//����, ����, �밢��
vector<int> dx[3] = {
	{1, 1},
	{0, 1},
	{1, 0, 1}
};
vector <int> dy[3] = {
	{0, 1},
	{1, 1},
	{0, 1, 1},
};
//status: 0 ���� 1 ���� 2 �밢��
void dfs(int y, int x, int status) //���� ������ ���� ��ǥ
{
	//���� ���� ���� ������ �ȴ�
	//�밢���� �� �������
	if (y == N - 1 && x == N - 1)
		cnt++;
	for (int i = 0;i < dy[status].size();++i)
	{
		int _y = y + dy[status][i];
		int _x = x + dx[status][i];

		if (_y < 0 || _y >= N || _x < 0 || _x >= N)
			continue;
		if (board[_y][_x] == 1)
			continue;
		if (_y == y && _x != x)
			dfs(_y, _x, 0);
		else if (_y != y && _x == x)
			dfs(_y, _x, 1);
		else
		{
			if (y < N - 1 && x < N - 1 && !board[y + 1][x] && !board[y][x + 1])
				dfs(_y, _x, 2);
		}
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;++j)
		{
			cin >> board[i][j];
		}
	}
	dfs(0, 1, 0);
	cout << cnt;
}