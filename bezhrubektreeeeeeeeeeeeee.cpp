#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve()
{


	int n, k; cin >> n >> k; // n = number of vertices k = number of distinct integers to be choosen
	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < n;i ++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	
}



signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
 }