#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;


	vector<char> stack;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '[' || s[i] == '(' || s[i] == '{')
		{
			stack.push_back(s[i]);
			continue;
		}

		if (s[i] == ']')
		{
			if (i == 0)
			{
				cout << "imbalanced" << '\n';
				return 0;
			}
			char lastChar = stack.back();
			stack.pop_back();

			if (lastChar != '[')
			{
				cout << "imbalanced" << '\n';
				return 0;
			}
		} else if (s[i] == ')') {
			if (i == 0)
			{
				cout << "imbalanced" << '\n';
				return 0;
			}
			char lastChar = stack.back();
			stack.pop_back();

			if (lastChar != '(')
			{

				cout << "imbalanced" << '\n';
				return 0;
			}
		} else if (s[i] == '}')
		{
			if (i == 0)
			{
				cout << "imbalanced" << '\n';
				return 0;
			}
				char lastChar = stack.back();
				stack.pop_back();

				if (lastChar != '{')
				{
					cout << "imbalanced" << '\n';
					return 0;
				}
		}
	}

	if (stack.size() ==0)
	{
		cout << "balanced" << '\n';
	} else
	{
		cout << "imbalanced" << '\n';
	}
	return 0;
}