#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> visted;
vector<vector<int>> virus;
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int R, C;

void increase(int r, int c, int max_virus)
{
    //cout << r << ", " << c << "\n";
    for (int i = 0;i < 4; ++i)
    {
        int _r = r + dr[i];
        int _c = c + dc[i];
        if (_r < 0 || _r >= R || _c < 0 || _c >= C)
            continue;
        if (visted[_r][_c])
            continue;
        visted[_r][_c] = 1;
        if (virus[_r][_c] < max_virus)
            virus[_r][_c]++;
        else
            increase(_r, _c, max_virus);
    }
}

vector<vector<int>> solution(int rows, int columns, int max_virus, vector<vector<int>> queries) {
    R = rows;
    C = columns;
    virus.assign(rows, vector<int>(columns, 0));
    for (auto query : queries)
    {
        visted.assign(rows, vector<int>(columns, 0));
        visted[query[0] - 1][query[1] - 1] = 1;
        if (virus[query[0] - 1][query[1] - 1] < max_virus)
            virus[query[0] - 1][query[1] - 1]++;
        else
            increase(query[0] - 1, query[1] - 1, max_virus);
    }
    return virus;
}
int main(void)
{
    auto a = solution(3, 4, 2, { {3,2},{3,2},{2,2},{3,2},{1,4},{3,2},{2,3},{3,1} });
    for (auto v : a)
    {
        for (int num : v)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
}