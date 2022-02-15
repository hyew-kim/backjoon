//1717
#include <bits/stdc++.h>

using namespace std;

int n, m;
int group[1000003];


// ���� ã��
int find(int num)
{
	if (group[num] == num)
		return num;
	//Ž���� node�� ���� ������ �������� ����
	return (group[num] = find(group[num]));
}

//�׷� ����
void join(int num1, int num2)
{
	 // group�۾� �� �������� Ȯ��
	if (num1 > num2)
		group[find(num2)] = find(num1);
	else
		group[find(num1)] = find(num2);
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	//���� �ڱ� �ڽ��� �׷� ����
	for (int i = 1;i <= n;i++)
		group[i] = i;
	for (int i = 0;i < m;i++)
	{
		int a, b, flag = 0;
		cin >> flag >> a >> b;
		if (flag == 0)
			join(a,b);
		else
		{
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}