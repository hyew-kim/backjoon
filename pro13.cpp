//로또의 최고 순위와 최저 순위

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int current_cnt = 0;
    int zero_cnt = 0;
    int happy_cnt = 0;
    int max_correct = 6;
    vector<bool> visted(6, false);
    /*for (int num : lottos)
    {
        if (num == 0)
            zero_cnt++;
        auto it = find(win_nums.begin(), win_nums.end(), num);
        if (it != win_nums.end())
            current_cnt++;
    }*/
    /*정답을 찾은 번호는 다시 대조해볼 필요 x*/
    for (int i = 0;i < lottos.size();i++) {
        if (lottos[i] == 0)
        {
            zero_cnt++;
            continue;
        }
        for (int j = 0;j < lottos.size(); j++)
        {
            if (visted[j] == true) continue;
            if (lottos[i] == win_nums[j])
            {
                visted[j] == true;
                current_cnt++;
                break;
            }
        }
        //if (visted[i] == false) zero_cnt++;
    }
    
    //current_correct + zero_cnt 6이최대
    if ((happy_cnt = current_cnt + zero_cnt) > max_correct)
        happy_cnt = max_correct;

    int rank = 1;
    while (answer.size() < 2)
    {
        if (max_correct < 2)
            answer.push_back(6);
        else 
        {
            if (happy_cnt == max_correct)
                answer.push_back(rank);
            if (current_cnt == max_correct)
                answer.push_back(rank);
        }
        max_correct--;
        rank++;
    }
     //둘다 cnt가 0 0이면 ?
    //실제 코테에서는 그냥 switch쓰기..ㅎ
    return answer;
}

int main(void)
{
    vector<int> res = solution({ 31, 10, 44, 0, 6, 19 }, { 31, 10, 44, 1, 6, 19 });
    for (int e : res)
        cout << e << " ";
}