#include <iostream>

using namespace std;

void	func(int i, int j,int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << " ";
	else
	{
		if (n == 1)
			cout << "*";
		else
			func(i, j, n / 3);
	}
	return;
}

int		main(void)
{
	int N = 0;

	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			func(i, j, N); // ��ġ�� ���� �� or ������ ��� �Լ�
		}
		cout << "\n";
	}
	return 0;
}