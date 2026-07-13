#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 1e9 + 7;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, k;
	cin >> a >> b >> k;
	vector<vector<int>> dp(a+2,vector<int>(b+2, 0));
	set<pair<int,int>> cameras;
	for (int i = 0; i< k; i++)
	{
		int x, y;
		cin >> x >> y;
		cameras.insert(make_pair(y,x));
	}

	dp[1][1] = 1;
	// for (int i = 0; i < a;i++) dp[1][i] = 1;
	// for (int i = 0; i < b;i++) dp[i][1] = 1;

	for (int i = 1; i <= a+1; i++)
	{
		for (int j = 1; j <=b+1; j++)
		{
			if (i == 1 && j == 1) continue;

			if (cameras.contains({j-1,i-1})) continue;

			dp[i][j] = (dp[i-1][j]  + dp[i][j-1] )% MOD;
		}
	}

	int res = dp[a+1][b+1];

	cout << res << '\n';

}