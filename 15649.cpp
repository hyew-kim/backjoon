#include<iostream>

using namespace std;

int arr[10];
bool isused[10];
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
		if (!isused[i])
		{
			arr[idx] = i;
			isused[i] = true;
			func(idx + 1);// 다음 칸 채우러 ㄱㄱ
			//cout << "idx: " << idx << " i: " << i <<"\n";
			isused[i] = false; //이까지 왔다는건 출력하고 return 된 것 채웠던거 차례대로 off
		}
	}
	return;
}
int main(void)
{
	cin >> n >> m;
	func(0);
	return 0;
}