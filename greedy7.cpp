//1052

#include <iostream>
using namespace std;

//물병을 사야하는 경우 어떻게 조합해도 같은 물병 2개가 안될때
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
		//추가 0일때 몇개 만들어지는가?
		int cnt = addBottle(N + extra);
		//cout << cnt << " " << extra << "\n";
		if (cnt <= K)
			break;
		extra++;
	}
	cout << extra;
}