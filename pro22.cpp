#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    auto it = find(seoul.begin(), seoul.end(), "Kim");
    answer += "김서방은 ";
    answer += to_string(it - seoul.begin());
    // string에 이어 붙이는 작업이니 to_string으로 전환하는게 마즘!
    answer += "에 있다";
    return answer;
}
int main(void)
{
    cout << solution({ "jane" ,"jane", "Kim","jane" });
}