#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int k = 0;

	while (true)
	{
		cin >> k;
		if (k == 0)
			return 0;
		vector<int> S(k);
		vector<int> v(k);
		for (int i = 0;i < k;i++)
		{
			cin >> S[i];
			if (i < 6)
				v[i] = 0;
			else
				v[i] = 1;
		}
		do {
			for (int i = 0;i < k;i++)
				if (v[i] == 0)
					cout << S[i] << " ";
			cout << "\n";
		} while (next_permutation(v.begin(), v.end()));
		cout << "\n";
	}
}