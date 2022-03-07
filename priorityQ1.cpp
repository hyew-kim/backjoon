//1715
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue <int, vector<int>, greater<int>> pq;
int cnt;

//작은 묶음들끼리 섞어야 최종적으로 가장 최소의 비교를 하는 것 
//오름차순 정렬을 유지해야하고 가장 작은 묶음 값이 필요하니
//우선순위 큐를 사용
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