#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int S[30][30];
vector<int>start(2);
vector<int>link(2);
int N;

int func(void)
{
    int start_sum = 0;
    int link_sum = 0;
    for (int i = 0;i < N / 2;i++)
    {
        for (int j = 0;j < N / 2;j++)
        {
            if (i == j)
                continue;
            start_sum += S[start[i] - 1][start[j] - 1];
            link_sum += S[link[i] - 1][link[j] - 1];
        }
    }
    return (abs(start_sum - link_sum));
}

int main(void)
{
    cin >> N;
    vector<int>v(N);
    int MIN = 99999999;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cin >> S[i][j];
    }
    for (int i = 0;i < N;i++)
    {
        if (i < N / 2)
            v[i] = 0;
        else
            v[i] = 1;
    }
 
    do {
        start.clear();
        link.clear();
        for (int i = 0;i < N;i++)
        {
            if (v[i] == 0)
                start.push_back(i + 1);
            else
                link.push_back(i + 1);
        }
        MIN = min(MIN, func());
    } while (next_permutation(v.begin(), v.end()));
    cout << MIN;
    return 0;
}