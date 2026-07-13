#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve()
{
	int n; cin >> n;
	string s; cin >> s;

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'R') res ++;
		if (s[i] == 'L')
		{
			res++;
			break;
		}
	}

	cout << res << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i =0;i < t;i++)
	{
		solve();
	}
}