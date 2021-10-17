#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int map[100][100] = { 0 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int M = 0, N = 0;
int cnt = 0;
vector<int> area;

void    dfs(int x, int y)
{
    cnt++;
    map[x][y] = -1;
    for (int dir = 0;dir < 4;dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        if (map[nx][ny] != 0)
            continue;
        dfs(nx, ny);
    }
    return;
}

int     main(void)
{
    int K = 0;
    int idx = 0;
    cin >> M >> N >> K;
    for (int i = 0;i < K;i++)
    {
        pair<int, int> pos1;
        pair<int, int> pos2;

        cin >> pos1.X >> pos1.Y >>pos2.X >> pos2.Y;
        for (int x = pos1.X;x < pos2.X;x++)
        {
            for(int y = pos1.Y;y < pos2.Y;y++)
                map[y][x] = 1;
        }
    }
    for (int i = 0;i < M;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (map[i][j] == 0)
            {
                idx++;
                cnt = 0;
                dfs(i, j);
                area.push_back(cnt);
            }
        }
    }
    sort(area.begin(), area.end());
    cout << idx << endl;
    for (size_t i = 0;i < area.size();i++)
        cout << area[i] << " ";
    return 0;
}