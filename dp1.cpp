//1463
#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[1] = 0;
	//2���� n���� 1�� �ɶ� ������ Ƚ���� �̸� ���� ����
	//Ƚ���� �迭�� �����Ͽ� ���� ��� �� ����� �� �ҷ��� ����
	for (int i = 2;i <= n;i++)
	{
		d[i] = d[i - 1] + 1;// 2 = 1 + 1
		//6���� ������ ��� ����Ͽ� ��� if
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
		//cout << i << " " << d[i] << "\n";
	}
	cout << d[n];
}