#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m,0));

	pair<int,pair<int,int>> minCell = {INT64_MAX, {0,0}};

	for (int i = 0 ;i<n; i++)
	{
		for (int j = 0 ; j < m; j++)
		{
			int a; cin >> a;
			grid[i][j] = a;
			minCell = min(minCell,{a, {i,j}});
		}
	}

	vector<vector<int>> dp_lahub_start(n+2, vector<int>(m+2,0));
	vector<vector<int>> dp_lahubina_start(n+2,vector<int>(m+2,0));
	vector<vector<int>> dp_lahub_end(n+2, vector<int>(m+2,0));
	vector<vector<int>> dp_lahubina_end(n+2,vector<int>(m+2,0));
	vector<vector<int>> dp(n + 2, vector<int>(m + 2,0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1 ; j <= m;j++)
		{
			dp_lahub_start[i][j] = max(dp_lahub_start[i-1][j],dp_lahub_start[i][j-1]) + grid[i-1][j-1];
		}
	}


	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			dp_lahubina_start[i][j] = max(dp_lahubina_start[i][j-1], dp_lahubina_start[i+1][j]) + grid[i - 1][j-1];
		}
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			dp_lahub_end[i][j] = max(dp_lahub_end[i+1][j], dp_lahub_end[i][j+1]) + grid[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= 1; j--)
		{
			dp_lahubina_end[i][j] = max(dp_lahubina_end[i-1][j], dp_lahubina_end[i][j+1]) + grid[i-1][j - 1];
		}
	}
	// final result

	int res=0;
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < m-1;j++)
		{
			// lah from top to botomm & lahubina from left to right
			int firstOption =dp_lahub_start[i][j+1] + dp_lahub_end[i+2][j+1] + dp_lahubina_start[i+1][j] + dp_lahubina_end[i+1][j+2];
				// lah from left to right & lahubina from top to bottom
			int secondOption =dp_lahubina_start[i+2][j+1] + dp_lahubina_end[i][j+1] + dp_lahub_end[i+1][j+2] + dp_lahub_start[i+1][j];
			dp[i][j] = max(firstOption,secondOption);
			res = max(res, dp[i][j]);
		}
	}


	cout << res << '\n';
	return 0;
}