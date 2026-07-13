#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &currSearch, vector<int> &costs,unordered_set<int> &supply,vector<int> &dp, int i)
{

	if (visited[i]) return;
	visited[i] = 1;


	if (supply.contains(i))
	{
		dp[i] = 0;
		return;
	}

	if (adj[i].empty()) return;




	visited[i] = 1;
	currSearch[i] = 1;


	int option1=0;
	for (auto node:adj[i])
	{
		if (currSearch[node])continue;
		dfs(adj,visited,currSearch,costs,supply,dp,node);
		option1+=dp[node];
	}
	dp[i] = min(option1, dp[i]);
	currSearch[i] = 0;




}



void solve()
{
	int n, k; cin >> n >> k; // total number of potion types & number of potion types nastya has
	vector<int> costs;
	unordered_set<int> supply;
	vector<vector<int>> adj(n,vector<int>());
	vector<int> visited(n,0);
	vector<int> currSearch(n,0);

	for (int i  =0;i <n;i++)
	{
		int c; cin >> c;
		costs.push_back(c);
	}

	for (int i = 0; i < k; i++)
	{
		int p; cin >> p;
		supply.insert(p-1);
	}

	for (int i = 0; i < n; i++)
	{
		int m; cin >> m;
		for (int j = 0; j < m; j++)
		{
			// build DAG :)
			int e; cin >> e;
			adj[i].push_back(e-1);
		}

	}

	vector<int> dp = costs;
	for (int i = 0; i < n; i++)
	{
		dfs(adj,visited,currSearch,costs,supply,dp,i);
	}


	for (int i =0;i<n;i++)
	{

		if (supply.contains(i))
		{
			cout << 0 << ' ';
			continue;
		}

		cout << dp[i] << ' ';

	};
	cout << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t;
	cin >> t;
	for (int i = 0 ; i < t; i++)
	{
		solve();
	}
}