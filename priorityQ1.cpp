//1715
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue <int, vector<int>, greater<int>> pq;
int cnt;

//���� �����鳢�� ����� ���������� ���� �ּ��� �񱳸� �ϴ� �� 
//�������� ������ �����ؾ��ϰ� ���� ���� ���� ���� �ʿ��ϴ�
//�켱���� ť�� ���
int main(void)
{
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int tmp = 0;
		cin >> tmp;
		pq.push(tmp);
	}
	while (pq.size() > 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		pq.push(first + second);
		cnt += first + second;
	}
	cout << cnt;
}