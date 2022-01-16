// 'x'를 많이 사용하는게 최대 수를 만드는데 유리
//예외) 1, 0 있을 때
#include <bits/stdc++.h>

using namespace std;

string S;

int main(void)
{
	cin >> S;
	int i = 1;
	int res = S[0] - '0';
	while (i < S.length())
	{
		int num = S[i] - '0';
		if (num <= 1 || res <= 1)
			res += num;
		else
			res *= num;
		i++;
		cout << num << "\n";
	}
	cout << res;
}