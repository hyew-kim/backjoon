#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int idx)
{
	if (idx == m)
	{
		for (int i = 0;i < m;i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (!isused[i])
		{
			if (idx == 0 || arr[idx - 1] < i)
			{
				arr[idx] = i;
				isused[i] = true;
				func(idx + 1);
				isused[i] = false; // 이거에 조건을 줘도 ㄱㅊ할듯..?
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	func(0);
	return 0;
}