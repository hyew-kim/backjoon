#include <iostream>
#include <string>

using namespace std;

void	func(int n, int k)
{
	string line = "";
	int i = k;
	while (i)
	{
		line += "----";
		i--;
	}
	cout << line << "\"����Լ��� ������?\"" << "\n";
	if (n == 0)
	{
		cout << line << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" <<"\n";
	}
	else
	{
		cout <<line << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." <<"\n";
		cout << line << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���."<<"\n";
		cout << line << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
		func(n - 1,k + 1);
	}
	cout << line << "��� �亯�Ͽ���." << "\n";
	return;
}

int main(void)
{
	int N = 0;
	int K = 0;
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
	func(N,K);
	return 0;
}
