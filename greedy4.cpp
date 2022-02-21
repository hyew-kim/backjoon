//1541
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	string s;

	cin >> s;
	string num = "";
	bool flag = false;
	int res = 0;
	for (int i = 0;i <= s.length();i++)
	{
		if (isdigit(s[i]))
			num += s[i];
		else
		{
			if (num != "")
			{
				res = flag ? res - stoi(num) : res + stoi(num);
				num = "";
			}
			if (s[i] == '-')
				flag = true;
		}
	}
	cout << res;
}