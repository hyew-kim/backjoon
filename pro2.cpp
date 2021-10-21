#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


bool compare(char a, char b)
{
    if (a <= b)
        return (false);
    else
        return (true);
}

string solution(string s) {
    string answer = "";
    int len = s.length();

    sort(s.begin(), s.end(),compare);
    answer = s;
    return answer;
}

int main(void)
{
    string s;
    cin >> s;
    cout << solution(s);
}