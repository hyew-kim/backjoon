#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N = 0;
    int cnt[10000] = { 0 };
    int Max = 0;


    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int nbr = 0;

        cin >> nbr;
        Max = max(Max, nbr);
        cnt[nbr - 1]++;
    }
    for (int i = 0;i < Max;i++)
    {
        if (cnt[i] != 0)
        {
            for (int j = 0;j < cnt[i];j++)
                cout << i + 1 << "\n";
        }
    }
    return 0;
}