#include <bits/stdc++.h>
using namespace std;
#define int int64_t


void dfs(vector<vector<int>> &adj, vector<int> &visited,vector<int> &dp, int i, int n)
{
	if (visited[i]) return;
	visited[i] = 1;


	for (auto u : adj[i])
	{
		if (visited[u]) continue;

		dfs(adj,visited,dp,u,n);
		dp[i] += dp[u];
	}

	dp[i]++;


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >>n ;
	vector<vector<int>> adj(n,vector<int>());
	vector<int> visited(n, 0);
	vector<int> prefix(n, 0);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	dfs(adj,visited,prefix,0, n);

	if (prefix[0] % 2 !=0)
	{
		cout << -1 << '\n';
		return 0;
	}

	int res = 0;

	for (int i = 1; i < n; i++)
	{
		int size = prefix[i];
		if (size % 2 == 0) res ++;
	}

	cout << res << '\n';
}