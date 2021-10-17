#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool isused[10];

void	func(int idx, int pre)
{
	//cout << "pre: " << pre << "\n";
	if (idx == M)
	{
		for (int i = 0;i < M;i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1;i <= N;i++)
	{
		if (pre <= i)
		{
			arr[idx] = i;
			func(idx + 1,i);
		}
	}
	return;
}

int		main(void)
{
	cin >> N >> M;
	func(0,0);
}