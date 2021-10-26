#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int num : arr)
    {
        if (num % divisor == 0)
            answer.push_back(num);
    }
    if (answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}

int main(void)
{
    vector<int> res = solution({ 5,9,7,10 }, 11);

    for (int e : res)
        cout << e << " ";
}