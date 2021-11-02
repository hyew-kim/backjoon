#include <string>
#include <vector>
#include  <bits/stdc++.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (char c : s)
    {
        if (c != ' ')
        {
            while (n--)
            {
                if (c == 'z' || c == 'Z')
                    c += ('a' - 'z');
                else
                    c += 1;
            }
        }
        answer += c;
    }
    return answer;
}

int main(void)
{
    cout << solution("BC", 1);
}