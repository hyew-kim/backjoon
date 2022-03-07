//13164
#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int height[300001];
int diff[300001];
int price;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int i = 0;i < N;i++)
		cin >> height[i];
	for (int i = 1;i < N;i++)
		diff[i] = height[i] - height[i - 1];
	sort(diff, diff + N, greater<int>());
	for (int i = K - 1;i < N;i++)
		price += diff[i];
	cout << price;
}