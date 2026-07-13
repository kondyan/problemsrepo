#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 10e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, I , J; cin >> n >> I >> J;

	vector<int> dp(n+1, -1);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i-1] %  MOD + dp[i-2] % MOD;
	}

	cout << (dp[J] - dp[I] + 2) % MOD;
}