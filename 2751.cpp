#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N = 0;
	
	cin >> N;
	vector<int>v(N);
	for (int i = 0;i < N;i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0;i < N;i++)
		cout << v[i] <<"\n";
	return 0;
}