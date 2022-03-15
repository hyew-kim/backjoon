//N으로 표현
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    unordered_set <int> s[8]; // s[i] : i + 1 개로 만들 수 있는 수 모음
    int answer = -1;
    int num = 0;

    for (int i = 0; i < 8;i++)
    {
        num = num * 10 + N;
        s[i].insert(num);
    }

    for (int i = 1;i < 8;i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int a : s[j])
            {
                for (int b : s[i - j - 1])
                {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b)
                        s[i].insert(a / b);
                }
            }
        }
    }
    for (int i = 0;i < 8;i++)
    {
        if (s[i].find(number) != s[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    return answer;
}