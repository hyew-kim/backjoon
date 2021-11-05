#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		string data;
		stack<char> s;
		string res = "YES";

		cin >> data;
		
		for (char c : data)
		{
			if (c == '(')
			{
				s.push(c);
			}
			else if (c == ')')
			{
				if (s.empty())
				{
					res = "NO";
					break;
				}
				s.pop();
			}
		}
		if (s.empty() == false)
			res = "NO";
		cout << res << "\n";
	}
}