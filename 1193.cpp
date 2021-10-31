#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int X = 0;
	int layer = 1;

	cin >> X;
	
	while (X > layer)
	{
		X -= layer;
		layer++;
	}
	if (layer % 2 == 0)
		cout << X << "/" << layer + 1 - X;
	else
		cout << layer + 1 - X << "/" << X;
	return 0;
}