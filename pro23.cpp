#include <bits/stdc++.h>

using namespace std;
string  step4_7(string s)
{
    string res = "";
    
    if (s[0] == '.')
        s.erase(s.begin()); //중간에 자리나면 알아서 다 떙겨서 자리차지 함
    if (s.length() > 1 && s[s.length() - 1] == '.')
        s.erase(s.length() - 1);
    
    int len = s.length();
    if (s == "")
        s += "a";
    if (len >= 16)
    {
        res = s.substr(0, 15); //시작지점, 길이
        if (res[14] == '.')
            res.erase(14);
    }
    else if (len <= 2)
    {
        char c = len > 1 ? s[len - 1] : s[0];
        while (s.length() < 3)
            s += c;
        res = s;
    }
    else
        res = s;
    return res;
}

string step1_3(string s)
{
    string check = "-_.";
    string tmp = "";
    string res = "";
    bool isappear = false;

    for (char c : s)
    {//isdigit판단할때 '0'~'9'임
        if (!(isalpha(c) || isdigit(c)
            || check.find(c) != string::npos))
            continue;
        tmp += tolower(c);
    }
    for (int i = 0;i < tmp.length(); i++)
    {

        if (tmp[i] == '.')
        {
            if (isappear)
                continue;
            isappear = true;
        }
        else
            isappear = false;
        res += tmp[i];
    }
    return res;
}

string solution(string new_id) {
    string answer = "";
    //{'-', '_', '.'}
    answer += step4_7(step1_3(new_id));
    return answer;
}

int main(void)
{
    cout << solution(".ab.");
}