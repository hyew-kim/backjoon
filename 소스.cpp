#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool compare(double a, double b)
{
    if (a > b)
        return (true);
    else
        return (false);
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> state(N);
    int user = stages.size();

    for (int stage : stages)
    {
        if (stage != N + 1)
            state[stage - 1]++;
    }
    for (double& nth_stage : state)
    {
        double fail = nth_stage / user;
        user -= (int)nth_stage;
        nth_stage = fail;
        cout << nth_stage << "\n";
    }
    sort(state.begin(), state.end(), compare);
    for (int i = 0; i < N; i++)
    {
        answer.push_back(i + 1);
    }
    return answer;
}

int main(void)
{
    vector<int>res = solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
    cout << "res: ";
    for (int e : res)
        cout << e;
}