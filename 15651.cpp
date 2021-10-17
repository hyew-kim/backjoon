#include<iostream>

using namespace std;

int arr[10];
int n, m;

void func(int idx)
{
	if (idx == m) // 기저 조건
	{
		for (int i = 0;i < m;i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		arr[idx] = i;
		func(idx + 1);// 다음 칸 채우러 ㄱㄱ
	}
	return;
}
int main(void)
{
	cin >> n >> m;
	func(0);
	return 0;
}