//조이스틱
#include <bits/stdc++.h>
using namespace std;

//틀린 풀이
int solution(string name) {
    int answer = 0;
    string res = "";
    int current = 0;
    int left = 0;
    int right = 0;
    int len = name.length();

    for (int i = 0;i < len ;++i)
        res += "A";

    while (1)
    {
        int left_cnt = 0;
        int right_cnt = 0;

        answer += min(name[current] - 'A', 'Z' - name[current] + 1);
        res[current] = name[current];

        if (res == name)
            break;
        left = current;
        right = current;
        //다음 타겟 찾기 위해 어디로 가는게 빠른지 check
        while (name[left] == res[left])
        {
            left = left == 0 ? name.length() - 1 : left - 1;
            left_cnt++;
        }
        while (name[right] == res[right])
        {
            right = right == name.length() - 1 ? 0 : right + 1;
            right_cnt++;
        }
        if (left_cnt < right_cnt)
        {
            current = left;
            answer += left_cnt;
        }
        else
        {
            current = right;
            answer += right_cnt;
        }
        cout << answer << "\n";
    }
    return answer;
}
int main(void)
{
    cout << solution("AABAAAAABBB");
}