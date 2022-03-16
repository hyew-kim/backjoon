#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int t, n;
unordered_map<string, int> m;

int main(void)
{
	cin >> t;
	while (t-- > 0)
	{
		int res = 1;
		m.clear();
		cin >> n;
		for (int i = 0;i < n;++i)
		{
			string a, b = "";
			cin >> a >> b;
			if (m.find(b) == m.end())
				m.insert({ b ,1 });
			else
				m[b]++;
		}
		//"headgear" : 2
		//"eyewear" : 1
		for (auto type : m)
			res *= (type.second + 1);
		//모든 종류를 다 입어야하지 않음
		//안 입는 경우 +1임
		cout << res - 1 << "\n";
	}
}