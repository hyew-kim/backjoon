#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    for (int num : arr)
    {
        answer += (double)num;
    }
    answer /= (double)(arr.size());
    return answer;
}