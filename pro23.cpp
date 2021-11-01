#include <bits/stdc++.h>

using namespace std;
string  step2(string s)
{
    string res = "";
    return res;
}
string step1(string s)
{
    string check = "-_.";
    string res = "";
    bool isappear = false;

    for (char c : s)
    {
        if (isalpha(c) == 0 || isdigit(c) == 0
            || check.find(c) == string::npos)
            continue;
        if (c == '.')
        {
            if (isappear)
                continue;
            isappear = true;
        }
        else
            isappear = false;
        res += toupper(c);
    }
    return res;
}

string solution(string new_id) {
    string answer = "";
    //{'-', '_', '.'}
    if (new_id == "")
        return "a";
    answer = step2(step1(new_id));
    return answer;
}