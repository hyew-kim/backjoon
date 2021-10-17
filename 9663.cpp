#include <iostream>
	
using namespace std;

int N;
int Case;
bool isused1[50]; // 행 상태 
bool isused2[50]; // \방향 대각선 상태
bool isused3[50]; // /방향 대각선 상태

void func(int cur)
{
	if (cur == N)
	{
		Case++;
		return;
	}
	for (int i = 0;i < N;i++)
	{
		if (!isused1[i] && !isused2[i + cur] && !isused3[i - cur + N - 1])
		{
			isused1[i] = true;
			isused2[i + cur] = true;
			isused3[i - cur + N - 1] = true;
			func(cur + 1);
			isused1[i] = false;
			isused2[i + cur] = false;
			isused3[i - cur + N - 1] = false;
		}
	}
	return;
}

int main(void)
{
	cin >> N;
	func(0);
	cout << Case;
	return 0;
}