#include <bits/stdc++.h>
using namespace std;
#define int int64_t

// int left(int i) {return i*2 + 1;}
// int right(int i) {return i*2 + 2;}
// int solve(vector<int> &tree,vector<int>&dp, int node, int n)
// {
// 	// if (dp[node]) return 0;
// 	if (left(node) > 4*n) return dp[node - 1] = tree[node - 1];
// 	if (right(node) > 4*n) return dp[node - 1] = tree[node - 1];
//
//
// 	int leftMax = solve(tree,dp, left(node), n);
// 	int rightMax = solve(tree,dp, right(node),n);
//
//
//   dp[node - 1] = max(dp[left(node) - 1], dp[right(node) - 1]) + tree[node - 1];
// }

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >>n;

	vector<vector<int>> tree(n,vector<int>());
	vector<vector<int>> dp(n, vector<int>());
	for (int i=0; i<  n;i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int x;
			cin >>x;
			tree[i].push_back(x);
			dp[i].push_back(0);
		}

	}

	for (int i =n-1;i >=0 ;i--)
	{
		for (int j = 0; j< tree[i].size(); j++)
		{
			if (i == n-1)
			{
				dp[i][j] = tree[i][j];
				continue;
			};

			dp[i][j] = max(dp[i + 1][j],dp[i+1][j+1]) + tree[i][j];

		}

	}


	cout << dp[0][0] << '\n';
}