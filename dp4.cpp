//11726
#include <bits/stdc++.h>

using namespace std;

int D[1004];
int n;

int main(void)
{
	cin >> n;
	D[1] = 1;
	D[2] = 2;
	for (int i = 3;i <= n;i++)
		D[i] = (D[i - 1] + D[i - 2]) % 10007;
	cout << D[n];
	return 0;
}