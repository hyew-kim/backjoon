#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;

    for (char c : s)
    {
        cout << idx << "\n";
        if (c != ' ')
        {
            if (idx % 2 == 0 && (c >= 'a' && c <= 'z'))
                c += ('A' - 'a');
            if (idx % 2 && (c >= 'A' && c <= 'Z'))
                c += ('a' - 'A');
            idx++;
        }
        //�ܾ�� idx ī����, �߿��Ѱ� ������ �ƴ� �κ��̴ϱ�
        else
            idx = 0;
        answer += c;
    }
    return answer;
}

int main(void)
{
    cout << solution("try hello world");
}