#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(int n) {
    string answer = "";
    int newbase[3] = { 4,1,2 };
    
    while (n)
    {
        answer = to_string(newbase[n % 3]) + answer;
        if (n % 3 == 0)
            n--;
        n /= 3;
    }
    return answer;
}