#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int day = 0;
    string arr[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU" };
    int month = 1;

    while (month < a)
    {
        if (month < 8)
        {
            if (month % 2 == 1)
                day += 31;
            else if (month == 2)
                day += 29;
            else
                day += 30;
        }
        else {
            if (month % 2 == 1)
                day += 30;
            else
                day += 31;
        }
        cout << day << " "<< month<<"\n";
        month++;
    }
    day += (b - 1);
    cout << day << "\n";
    answer = arr[day % 7];
    return answer;
}
int main(void)
{
    cout << solution(2, 24);
}