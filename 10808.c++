#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string S;
	vector<int> v(26);

	for (int i = 0; i < v.size();i++)
		v[i] = 0;
	cin >> S;
	for (int i = 0; i < S.length(); i++)
		v[S[i] - 'a']++;
	for (int i = 0; i < v.size();i++)
		cout << v[i] << ' ';
	return 0;
}