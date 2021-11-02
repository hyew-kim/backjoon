#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> numbers = {"zero","one","two","three",
    "four", "five", "six", "seven", "eight", "nine" };
    string word = "";

    for (char c : s)
    {
        if (isdigit(c))
            answer = answer * 10 + (c - '0');
        else
        {
            vector<string>::iterator it;
            word += c;
            it = find(numbers.begin(), numbers.end(), word);
            if (it != numbers.end()) // 못 찾으면 end()나오는거임
            {
                answer = answer * 10 +(it - numbers.begin());
                word = "";
            }
        }
    }
    return answer;
}

int main(void)
{
    cout << solution("one4seveneight");
}