#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    set<int> s;

    for (int e : numbers)
        s.insert(e);
    for (int i = 0;i <= 9;i++)
    {
        if (s.find(i) == s.end())
            answer += i;
    }
        return answer;
}
int main(void)
{
    cout << solution({ 1,2,3,4,6,7,8,0 });
}