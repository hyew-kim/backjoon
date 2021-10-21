#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int idx = 0;

    for (vector<int> v1 : arr1)
    {
        vector<int> tmp(v1.size());
        answer.push_back(tmp);
        for (int i = 0;i < v1.size();i++)
        {
            answer[idx][i] = v1[i];
        }
        idx++;
    }
    int i = 0;
    for (vector<int> v2 : arr2)
    {
        for (int j = 0;j < v2.size();j++)
        {
            answer[i][j] += v2[j];
        }
        i++;
    }
    return answer;
}
int main(void)
{
    vector<vector<int>> res = solution({ {1,2},{2,3} }, { {3, 4},{5,6 } });
    cout << "res\n";
    for (vector<int>v : res)
    {
        for (int i = 0;i < v.size();i++)
            cout << v[i] << "\n";
        cout << "\n";
    }
}