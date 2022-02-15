//1717
#include <bits/stdc++.h>

using namespace std;

int n, m;
int group[1000003];


// 대장 찾기
int find(int num)
{
	if (group[num] == num)
		return num;
	//탐색한 node는 가장 상위의 대장으로 갱신
	return (group[num] = find(group[num]));
}

//그룹 연결
void join(int num1, int num2)
{
	 // group작업 전 대장인지 확인
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
	//현재 자기 자신이 그룹 대장
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