#include <bits/stdc++.h>


using namespace std;

bool compare(pair<int, int>a, pair<int, int>b)
{
    if (a.second < b.second)
        return(false);
    else if (a.second == b.second)
    {
        if (a.first <= b.first)
            return (true);
        else
            return (false);
    }
    else
        return (true);
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>>correct(3);
    int man1[] = { 1,2,3,4,5 };
    int man2[8] = { 2,1,2,3,2,4,2,5 };
    int man3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int idx[3] = { 0 };
    int top_score = 0;

    for (int i = 0;i < 3;i++)
        correct[i].first = i + 1;
    for (int num_answer : answers)
    {
        if (man1[idx[0]] == num_answer)
            correct[0].second++;
        if (man2[idx[1]] == num_answer)
            correct[1].second++;
        if (man3[idx[2]] == num_answer)
            correct[2].second++;
        idx[0] = (idx[0] == 4) ? 0 : idx[0] + 1;
        idx[1] = (idx[1] == 7) ? 0 : idx[1] + 1;
        idx[2] = (idx[2] == 9) ? 0 : idx[2] + 1;
        //for (int i=0;i<answers.size();i++)라면
        //man[i % 5]이런식으로 접근 
    }
    sort(correct.begin(), correct.end(), compare);
    //sort가 아닌 max값을 저장해두고 밑에 내 코드대로 동작시키면
    //어차피 인덱스 순서대로 배치되어있으니 저렇게 복잡한 compare 필요없음
    top_score = correct[0].second;
    for (int i = 0;i < 3;i++)
    {
        if (correct[i].second < top_score)
            break;
        else
            answer.push_back(correct[i].first);
    }
    return answer;
}

int main(void)
{
    vector<int> res = solution({ 1,3,2,4,2 });
    for (int e : res)
        cout << e;
}