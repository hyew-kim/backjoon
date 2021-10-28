#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int start = 0;
    int end = 0;
    int nth = 0;

    for (auto v : commands)
    {
        vector<int> cut_v;
        start = v[0] - 1;
        end = v[1] - 1;
        nth = v[2] - 1;
        // 각 값이 다 벡터 인덱스 내의 값임?
        for (int i = start; i <= end;i++)
        {
            cut_v.push_back(array[i]);
        }
        sort(cut_v.begin(), cut_v.end());
        answer.push_back(cut_v[nth]);
    }
    return answer;
}