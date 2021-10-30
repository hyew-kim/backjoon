#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    //compare함수 설정 시 true인 상황을 if로 하기
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
    /*if (a.second < b.second)
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
        return (true);*/
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
        /*앞에서 user가 다 몰렸을경우 뒤에는 0으로 나누는 현상 발생*/
        if (user == 0)
            break;
        int stage_user = e.second;
        e.second /= user;
        user -= stage_user;
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
    for (int e : solution(5, { 1, 1, 1,1 }))
    {
      cout << e;
    }
}