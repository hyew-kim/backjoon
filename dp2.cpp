//9095
#include <bits/stdc++.h>
using namespace std;

int D[13];
int n;

int main(void)
{
	int T = 0;
	cin >> T;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4;i < 11;i++)
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	while (T--)
	{
		cin >> n;
		cout << D[n] << "\n";
	}
}

// for�� n�� �������� �� �������� D[n]�� �Է� �������
//����ϴ°� ȿ����
