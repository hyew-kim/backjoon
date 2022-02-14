//1629
#include <bits/stdc++.h>
using namespace std;

int a, b, c;

long long func(int a, int b, int c)
{
	if (b == 1)
		return a % c;
	long long tmp = func(a, b / 2, c);
	if (b % 2 == 0)
		return (tmp * tmp) % c;
	else
		return ((tmp * tmp )%c * a) % c;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	cout << func(a % c, b, c);
}