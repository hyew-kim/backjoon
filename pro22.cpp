#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    auto it = find(seoul.begin(), seoul.end(), "Kim");
    answer += "�輭���� ";
    answer += to_string(it - seoul.begin());
    // string�� �̾� ���̴� �۾��̴� to_string���� ��ȯ�ϴ°� ����!
    answer += "�� �ִ�";
    return answer;
}
int main(void)
{
    cout << solution({ "jane" ,"jane", "Kim","jane" });
}