#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string type = "";
    cin >> type;

    int res = 1;
    int c = 26;
    int d = 10;

    for (int i = 0;i < type.size();i++)
    {
        if (type[i] == 'c')
        {
            if (i - 1 >= 0 && type[i - 1] == 'c')
                res *= c - 1;
            else
                res *= c;
        }
        else if (type[i] == 'd')
        {
            if (i - 1 >= 0 && type[i - 1] == 'd')
                res *= d - 1;
            else
                res *= d;
        }
    }
    cout << res;
    return 0;
}