#include <iostream>

using namespace std;

int main(void)
{
	int E = 0, S = 0, M = 0;
	int a = 1, b = 1, c = 1;

	cin >> E >> S >> M;
	for (int year = 1;year <= 7980;year++)
	{
		if (a == E && b == S && c == M)
		{
			cout << year;
			return 0;
		}
		a++;
		b++;
		c++;
		if (a > 15) a = 1;
		if (b > 28) b = 1;
		if (c > 19) c = 1;
	}
}