#include <iostream>
#include <unordered_set>
using namespace std;

int N, M;
unordered_set<string> s;
int res;

int main(void)
{
	cin >> N >> M;
	for (int i = 0;i < N;++i)
	{
		string word = "";
		cin >> word;
		s.insert(word);
		/*for (int j = 0;j < word.length();++j)
		{
			s.insert(word.substr(j));
			s.insert(word.substr(0, word.length() - j));
		}*/
	}
	for (int i = 0;i < M;++i)
	{
		string word = "";
		cin >> word;
		if (s.find(word) != s.end())
			res++;
	}
	cout << res;
}