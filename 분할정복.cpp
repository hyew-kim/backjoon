//1992
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[65][65];

//x,y 각 구역 시작점
void compress(int cnt, int x,int y)
{
	if (cnt == 1)
	{
		cout << arr[x][y];
     	return;
	}
	for (int i = x;i < x + cnt;i++)
	{
		for (int j = y;j < y + cnt;j++)
		{
			if (arr[i][j] != arr[x][y])
			{
				//분할을 해야할 경우에만 괄호로 표현!
				cout << "(";
				compress(cnt / 2, x, y);
				compress(cnt / 2, x, y + cnt / 2);
				compress(cnt / 2, x + cnt / 2, y);
				compress(cnt / 2, x + cnt / 2, y + cnt / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << arr[x][y];
	return;
}

int main(void)
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0;j < n;j++)
		{
			arr[i][j] = (s[j] - '0');
		}
	}
	compress(n, 0 ,0);
}