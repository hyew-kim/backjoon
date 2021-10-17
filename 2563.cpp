#include <iostream>
#include <utility>

#define X first
#define Y second

using namespace std;

int board[101][101]; 

int main(void)
{
	int N = 0;
	int area = 0;
	pair<int, int> pos;

	cin >> N;
	while(N)
	{
		cin >> pos.X >> pos.Y;
		for (int i = pos.X;i < pos.X + 10;i++)
		{
			for (int j = pos.Y;j < pos.Y + 10;j++)
			{	
				if (board[i][j] == 0)
				{
					board[i][j] = 1;
					area++;
				}
			}
		}
		N--;
	}
	cout << area;
	return 0;
}