#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	vector<int> flag(n,0); // -1, 0, 1
	vector<int> degrees(n,0); // degrees of every edge
	vector<vector<int>> adj(n,vector<int>());
	vector<pair<int,int>> edges;
	for (int i = 0 ; i < m ;i ++)
	{
		int u, v; cin >> u >> v; u--; v--;
		edges.push_back({u,v});
		adj[u].push_back(v);
		adj[v].push_back(u);
		degrees[u]++; degrees[v]++;
	}

	//





}