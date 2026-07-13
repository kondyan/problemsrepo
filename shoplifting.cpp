#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n; cin >> n;

	// first = time second = price

	vector<pair<int,int>> items;
	vector<int> dp(n+1, INT64_MAX);

	for (int i = 0 ; i <n;i++)
	{
		int t, c; cin >> t >> c;
		items.push_back({t,c});
	}
	dp[0] = 0;

	for (auto [t, c] : items)
	{
		for (int j = n; j >= 0;j--)
		{
			int next_j=min(n, j + t + 1);
			dp[next_j] = min(next_j,dp[j] + c);
		}
	}



	cout << dp[n] << '\n';

}