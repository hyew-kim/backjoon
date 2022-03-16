//15650
#include <iostream>
using namespace std;

int N, M;
int num[10];
bool isused[10];

void func(int k, int st)
{
	if (k == M)
	{
		for (int i = 0;i < M;++i)
		cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = st;i <= N;++i)
	{
		if (isused[i])
			continue;
		//중복되지 않으려면 이전의 값보다 큰값만 쓰면됨
		num[k] = i;
		isused[i] = true;
		func(k + 1, i + 1);
		isused[i] = false;
	}
}

int main(void)
{
	cin >> N >> M;
	func(0, 1);
}