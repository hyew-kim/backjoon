#include <bits/stdc++.h>
using namespace std;

/*배포순서 문제*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    int distribute = 0;
    int total_process = progresses.size();
    vector<int> ready(total_process);

    while (distribute < total_process)
    {
        cnt = 0;//pop되어야만 cnt++;
        int idx = 0;
        for (int& progress : progresses)
        {
            if (progress < 100)
            {
                progress += speeds[idx];
                if (progress >= 100)
                    ready[idx] = 1;
            }
            idx++;
        }
        while (distribute < total_process && ready[distribute])
        {
            distribute++;
            cnt++;
        }

        if (cnt)
            answer.push_back(cnt);
    }
    return answer;
}

int main(void)
{
    vector<int> res = solution({80, 99, 50, 90, 99, 99}, { 1, 1, 1, 1, 1, 1 });
    for (int e : res)
    {
        cout << e;
    }
}