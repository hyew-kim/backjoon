#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N = 0;
	int M = 0;

	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	vector<int> C(N + M);
	for (int i = 0;i < N;i++)
		A[i];
	for (int i = 0;i < M;i++)
		B[i];
	int a_idx = 0;
	int b_idx = 0;
	for (int i = 0;i < N + M;i++)
	{
		if (A[a_idx] < B[b_idx])
			C[i] = A[a_idx++];
		else if (N == a_idx)
			C[i] = B[b_idx++];
		else if (M == b_idx)
			C[i] = A[a_idx++];
		else
			C[i] = B[b_idx++];
	}
	
}