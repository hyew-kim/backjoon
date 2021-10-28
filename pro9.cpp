#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int alphabet = 0;
    int cursor = 0;
    vector<int> name_status;
    int idx = 0;

    for (char e : name)
    {
        if (e >= 'A' && e <= 'N')
            alphabet += (e - 'A');
        else
            alphabet += ('Z' - e) + 1;
        if (e != 'A')
            name_status.push_back(idx);
        idx++;
    }
    

    answer = alphabet + cursor;
    return answer;
}