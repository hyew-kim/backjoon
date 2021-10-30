#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
bool cmp(const string& a, const string& b)
{
    return (a + b > b + a);
    //string형으로 인수를 받아야 덧셈할 수 있움!
}

string solution(vector<int> numbers) {
    string answer = "";
    int max_len = 0;
    vector<string> temp;
    for (int num : numbers)
    {
        temp.push_back(to_string(num));
    }
    //6 10 2-> 6210
    //0만 있을때 예외처리
    sort(temp.begin(), temp.end(), cmp);
    //temp.at(0) == "0" 
    // temp[0] == "0"
    if (temp.front() == "0")
        return answer += "0";
    for (auto e : temp)
    {
        answer += e;
    }
    return answer;
}
int main(void)
{
    cout << solution({ 0,0,0,0});
}