#include <bits/stdc++.h>

using namespace std;

int solution(int N, int A, int B)
{
	int answer = 0;

	while (A != B)
	{
		A = A % 2 == 0 ? A >> 1 : (A + 1) >> 1;
		B = B % 2 == 0 ? B >> 1 : (B + 1) >> 1;
		answer++;
	}
	
	return answer;
}
