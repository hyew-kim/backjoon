#include <bits/stdc++.h>

using namespace std;

void check(char& c)
{
    if (c == 'z' || c == 'Z')
        c -= 26;
    return;
}

string solution(string s, int n) {
    string answer = s;
    
    while (n--)
    {
        for (char& alpha : answer)
        {
            check(alpha);
            if (alpha == ' ')
                continue;
            else
                alpha = alpha + 1;
        }
    }

    return answer;
}