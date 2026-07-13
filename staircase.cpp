#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >>n;

	if (n == 1 || n == 2)
	{
		cout << n << '\n';
		return 0;
	}

	vector<int> dp(n+1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i =3; i<=n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}

	cout << dp[n] << '\n';
	return 0;
}