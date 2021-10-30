#include <bits/stdc++.h>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    // 1 ~ n¿« «’: n*(n+1)/2
    long long  total_price = (long long)price * (long long)(count * (count + 1) / 2);
    if (total_price <= money)
        answer = 0;
    else
        answer = total_price - money;
    return answer;
}


int main()
{
    cout << solution(2500, 1000000000, 2500)<<"\n";
}