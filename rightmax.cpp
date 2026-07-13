#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve()
{
	int n; cin >> n;
	vector<int> arr;

	int max_v = 0;
	int ans = 0;
	for (int i = 0 ; i < n; i++)
	{
		int a; cin >> a;
		if (a >= max_v)
		{
			ans++;
			max_v = a;
		}
	}
	cout << ans << '\n';


	}





signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
}