#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<long long>> d; //1 + 2 , 2 + 1 다른 경우임
//d[i][j] : i개 수로 j값 만들 수 있는 경우
int main(void)
{
    cin >> n >> k;
    d.assign(k + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; ++i)
        d[1][i] = 1;
    // dp[K][N] = sum (dp[K-1][N-l])
    for (int i = 2;i <= k;++i)
    {
        for (int j = 0;j <= n;++j)
        {
            for (int l = 0;l <= j;++l)
                d[i][j] += d[i - 1][j - l];
            d[i][j] %= 1000000000;
        }
        // d[2][0] += d[1][0]
    }
    cout << d[k][n] % 1000000000;
}