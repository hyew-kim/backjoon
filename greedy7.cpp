//1052

#include <iostream>
using namespace std;

//������ ����ϴ� ��� ��� �����ص� ���� ���� 2���� �ȵɶ�
int N, K;
int extra;

int addBottle(int n)
{
	int cnt = 0;
	while (n)
	{
		if (n % 2)
			cnt++;
		n >>= 1;
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	while (1)
	{
		//�߰� 0�϶� � ��������°�?
		int cnt = addBottle(N + extra);
		//cout << cnt << " " << extra << "\n";
		if (cnt <= K)
			break;
		extra++;
	}
	cout << extra;
}