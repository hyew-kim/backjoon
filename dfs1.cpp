#include <bits/stdc++.h>

using namespace std;

int N, M;
int mold[1004][1004];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int cnt;

void dfs(int x, int y)
{
    //cout << x << ", " << y << "\n";
    mold[x][y] = 1;
    for (int i = 0;i < 4;i++)
    {
        if ((x + dx[i] >= 0 && x + dx[i] < N) && (y + dy[i] >= 0 && y + dy[i] < M))
        {
            if (mold[x + dx[i]][y + dy[i]] == 0)
            {
                dfs(x + dx[i], y + dy[i]);
            }
        }
    }
}
int main(void)
{
    cin >> N >> M;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            cin >> mold[i][j];
        }
    }
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (mold[i][j] == 0)
            {
                //cout << "START: " << i << ", " << j << "\n";
                cnt++;
                dfs(i, j);
                //dfs 재귀 탈출 = 벽 만남, 새로운 시작점 찾기
            }
        }
    }
    cout << cnt;
}