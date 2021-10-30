#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int Min = *min_element(arr.begin(), arr.end());
    for (auto i = 0;i < arr.size(); i++)
    {
        if (arr[i] == Min)
            arr.erase(i + arr.begin());
    }
    if (arr.empty())
        answer.push_back(-1);
    else
    {
        for (int num : arr)
            answer.push_back(num);
    }
    return answer;
}

int main(void)
{
    vector<int> res = solution({ 4,3,2,1 });
    for(int e: res)
        cout << e;
}