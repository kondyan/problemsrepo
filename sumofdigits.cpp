#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve( )
{
	deque<string> result;
	string s; cin >> s;


	for (int i = s.size()-1; i >=0; i--)
	{
		if (s[i] != 0) break;
		s.pop_back();
	}


	result.push_back(s);

	if (stoi(s) <= 9)
	{
		for (auto elem:result )
		{
			cout << elem;
		}
		cout << '\n';
		return;
	}

	while (stoi(s) > 9) {

	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i ++)
	{
		solve();
	}
}