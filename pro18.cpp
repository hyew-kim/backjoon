#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

string solution(string phone_number) {
    string answer = "";
    int len = phone_number.length();
    int limit = len - 5;

    for (int i = 0;i < len;i++)
    {
        if (i <= limit)
            answer.push_back('*');
        else 
            answer.push_back(phone_number[i]);
    }
    return answer;
}
string solution1(string phone_number) {
    string answer = "";
    //string 메소드의 length() return값은 size_t 자료형
    cout << phone_number.length() - 5; // 이렇게 쓰면 underflow
    for (int i = 0;i < phone_number.length();i++)
    {
        if (i <= phone_number.length() - 5)
            answer.push_back('*');
        else
            answer.push_back(phone_number[i]);
    }
    return answer;
}
int main(void)
{
  cout << solution1("0103");
 
}