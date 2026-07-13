#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int> balls(n);
	for (int i = 0; i < n; i++)
	{
		cin >> balls[i];
	}

	//
	vector<vector<int>> dp(n+1, vector<int>(n+1,0));
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}

	// consider every length of range [l r]
	for (int len = 2; len <= n; len++)
	{
		// the left pointer
		for (int l = 0; l+len-1 < n; l++)
		{
			// right pointer
			int r = l+len-1;

			// consider the solution
			dp[l][r] = 1 + dp[l+1][r];

			for (int m = l+1; m <= r; m++)
			{
				if (balls[l] != balls[m]) continue;
				dp[l][r] = min(dp[l][r], dp[l+1][m-1] + dp[m+1][r]);
			}
		}


	}

	cout << dp[0][n-1];

}