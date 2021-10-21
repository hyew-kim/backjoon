#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void change_into_sharp2(string base2, string& answer)
{
    for (int i = 0;i < base2.length();i++)
    {
        if (base2[i] == '1')
        {
            if (answer[i] == ' ')
                answer[i] = '#';
        }
        else
            base2[i] = ' ';
    }
    return ;
}

string change_into_sharp(string base2)
{
    for (int i = 0;i < base2.length();i++)
    {
        if (base2[i] == '1')
            base2[i] = '#';
        else
            base2[i] = ' ';
    }
    return (base2);
}

string basechange(int num)
{
    string s = "00000";
    int i = 0;

    while (num)
    {
        s[i] = (num % 2) + '0';
        num /= 2;
        i++;
    }
    int len = 5;
    for (int idx = 0; idx < len / 2;idx++)
    {
        swap(s[idx], s[(len - 1) - idx]);
    }
    return (s);
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int e : arr1)
    {
        string s = basechange(e);
        answer.push_back(change_into_sharp(s));
    }
    int i = 0;
    for (int e : arr2)
    {
        string s = basechange(e);
        change_into_sharp2(s, answer[i]);
        i++;
    }
    return answer;
}

int main(void)
{
    vector<string>v = solution(5, { 9,20,28,18,11 }, { 1,1,1,1,1 });
    for (string e : v)
        cout << e << "\n";
    return 0;
}