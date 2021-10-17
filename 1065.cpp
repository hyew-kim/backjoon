#include <iostream>

using namespace std;

bool check(int num)
{
	int digit[3] = { 0 };

	if (num < 100)
		return true;
	else if (num == 1000)
		return false;
	else
	{
		for (int i = 0;i < 3;i++)
		{
			digit[2 - i] = num % 10;
			num /= 10;
		}
		if ((digit[2] - digit[1]) == (digit[1] - digit[0]))
			return true;
		else
			return false;
	}
}

int main(void)
{
	int N = 0;
	int cnt = 0;
	
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		if (check(i))
			cnt++;
	}
	cout << cnt;
	return 0;
}