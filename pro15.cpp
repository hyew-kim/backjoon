#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int board_len = board[0].size();
    stack<int> basket;

    for (int move : moves)
    {   
        int new_doll = 0;
        for (int i = 0; i < board_len; i++)
        {
            if (board[i][move - 1])
            {   
                new_doll = board[i][move - 1];
                board[i][move - 1] = 0;
                break;
            }
        }
        if (new_doll == 0)
            continue;
        /*Å©·¹ÀÎÀÌ ÇãÅÁ ÃÆÀ» °æ¿ì °Á ³Ñ¾î°¡±â*/
        if (!basket.empty() && new_doll == basket.top())
        {
            basket.pop();
            answer +=2;
        }
        else
            basket.push(new_doll);

    }
    return answer;
}

int main(void)
{
    cout << "res"<<solution({ {0,0,0,0,0},{0,0,1,0,3}, {0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4});
}