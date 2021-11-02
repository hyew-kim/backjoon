#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//������ ���� ��ų�� ����
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0;i < arr1.size();i++)
    {
        int len = n;
        string tmp = "";
        arr1[i] = arr1[i] | arr2[i];
        while (len--)
        {
            if (arr1[i] % 2 == 0) 
                tmp = " " + tmp; //�ڿ��� ���� �� ���ϸ� ���� !
            else 
                tmp = "#" + tmp;
            arr1[i] = arr1[i] >> 1;
            // arr1[i] /= 2;
        }
        answer.push_back(tmp);
    }
    return answer;
}

int main(void)
{
    vector<string>v = solution(6, { 46, 33, 33, 22, 31, 50 }, { 27, 56, 19, 14, 14, 10 });
    for (string e : v)
        cout << e << "\n";
    return 0;
}