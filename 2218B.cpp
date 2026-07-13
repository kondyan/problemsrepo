#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	vector<int>arr;
	for (int i = 0 ; i < 7;i++)
	{
		int a; cin >> a; arr.push_back(a);
	}
	int res = 0;
	sort(arr.begin(),arr.end());
	for (int i = 0 ; i < 7;i++)
	{
		if (i != 6)
		{
			res += -arr[i];
		} else
		{
			res += arr[i];
		}
	}

	cout << res << '\n';
}

signed main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}