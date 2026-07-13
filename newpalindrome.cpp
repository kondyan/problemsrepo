#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s; cin >> s;

	bool ans = false;
	for (int i = 1 ; i < s.size() / 2; i ++)
	{
		if (s[i-1] != s[i]) ans = true;
	}

	if (ans)
	{
		cout << "YES" << '\n';
	} else
	{
		cout << "NO" << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}