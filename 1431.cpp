#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int	sum(string s)
{
	int res = 0;
	for (int i = 0;i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res += (s[i] - '0');
	}
	return res;
}

bool	cmp(string s1, string s2)
{
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	else 
	{
		if(sum(s1) != sum(s2))
			return (sum(s1) < sum(s2));
	}
	return(s1 < s2);
}
// 해당 조건으로 비교할 수 없다 = 결과값이 같다.
int main(void)
{
	int N = 0;
	
	cin >> N;
	vector<string>v(N);
	for (int i = 0;i < N;i++)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	for (int i = 0;i < N;i++)
		cout << v[i] <<"\n";
	return 0;
}