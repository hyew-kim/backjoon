#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string res = "";
	char input[1000] = { 0 };
	stack<char>s;
	int flag = 0; // 0 단어 1 태그
	int space = 0; // 1 공백 출력 o

	cin.getline(input,1000);
	for (int i = 0;input[i];i++)
	{
		flag = input[i] == '<' ? 1 : 0;
		if (flag == 0)
		{
			while (input[i])
			{
				s.push(input[i]);
				if (input[i + 1] == '<')
				{
					break;
				}
				if (input[i + 1] == ' ')
				{
					space = 1;
					i++;
					break;
				}
				i++;
			}
			while (!s.empty())
			{
				res += s.top();
				s.pop();
			}
			if (space)
			{
				res += ' ';
				space = 0;
			}
		}
		else
		{
			while(input[i])
			{
				res += input[i];
				if (input[i] == '>')
					break;
				i++;
			}
		}
	}
	cout << res;
	return 0;
}