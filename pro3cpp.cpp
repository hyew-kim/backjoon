#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    if (a.second < b.second)
        return (false); 
    // 실패율은 값이 작은게 큰거임
    else if (a.second == b.second)
    {
        if (a.first < b.first)
            return (true);
        else
            return (false);
    }
    else
        return (true);
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> user_state(N);
    int user = stages.size();

    for (int i = 0;i < N; i++)
    {
        user_state[i].first = i + 1;
        user_state[i].second = 0;
    }

    for (int e : stages)
    {
        if (e == N + 1)
            continue;
        user_state[e - 1].second++;
    }
    for (pair<int, double>& e : user_state)
    {
        int stage_user = e.second;
        e.second /= user;
        user -= stage_user;
        cout << e.first<< " user: " << user << "\nfail: " << e.second << "\n";
    }
    sort(user_state.begin(), user_state.end(), compare);
    for (int i = 0;i < user_state.size();i++)
    {
        answer.push_back(user_state[i].first);

    }
    return answer;
}

int main(void)
{
    for (int e : solution(4, { 4, 4, 4, 4}))
    {
      cout << e;
    }
}