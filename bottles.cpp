#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;
	vector<int> dp(n, 0);


	for (int i = 0; i< n; ++i)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	dp[0] = a[0];
	dp[1] = max(dp[0], a[1]);

	for (int i = 2; i < n; i++)
	{
		dp[i] = max(dp[i-1], dp[i-2] + a[i]);
	}

	cout << dp[n-1] << '\n';
}