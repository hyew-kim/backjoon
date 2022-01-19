//14888
#include <bits/stdc++.h>

using namespace std;

int n;
int num[15]; //수
int operators[4]; //연산자 개수
int res_min = 1000000000;
int res_max = -1000000000;

void func(int k, int res)
{
	if (k == n - 1)
	{
		//여기서 최종 값 계산하기
		if (res_min > res)
			res_min = res;
		if (res_max < res)
			res_max = res;
		return;
	}
	for (int i = 0;i < 4;i++)
	{
		if (operators[i])
		{
			operators[i]--;
			if(i == 0)
				func(k + 1, res + num[k + 1]);
			else if(i == 1)
				func(k + 1, res - num[k + 1]);
			else if(i == 2)
				func(k + 1, res * num[k + 1]);
			else
				func(k + 1, res / num[k + 1]);
			operators[i]++;
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> num[i];
	for (int i = 0; i < 4;i++)
		cin >> operators[i];
	func(0, num[0]);
	cout << res_max << "\n" << res_min;
}