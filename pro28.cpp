#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0;i < numbers.size();i++)
    {
        for (int j = numbers.size() - 1;j > i;j--)
        {
            int sum = numbers[i] + numbers[j];
            if (answer.empty())
                answer.push_back(sum);
            if (find(answer.begin(), answer.end(), sum)== answer.end())
                answer.push_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}