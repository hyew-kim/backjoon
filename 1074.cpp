#include <iostream>
#include <math.h>

using namespace std;

int func(int n, int r, int c)
{
	if (n == 0)
		return 0;
	int half = (int)pow(2, n - 1);
	if (r < half)
	{
		if (c < half)//0��° �簢��
			return func(n - 1, r, c);
		return func(n - 1, r, c - half) + half * half;// 1��° �簢��
	}
	else
	{
		if (c < half)
			return func(n - 1, r - half, c) + half * half * 2;// 2��° 
		return func(n - 1, r - half, c - half) + half * half * 3;//3��°
	}
}

int main(void)
{
	int r = 0, c = 0, n = 0;
	cin >> n >> r >> c;
	cout << func(n, r, c);
	return 0;
}