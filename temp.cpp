#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node
{
	int node;
	int a;
};

void solve()
{
	int n,k;cin>>n>>k;

	vector<vector<Node>> adj(n,vector<Node>());
	vector<int> arr;
	for (int i =0;i<n;i++)
	{
		int a; cin >> a; arr.push_back(a);
	}

	for (int i = 0; i < n - 1; i ++)
	{
		int u, v; cin >> u >> v; u--; v--;
		adj[u].push_back(Node(v,arr[v]));
		adj[v].push_back(Node(u, arr[u]));
	}




}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}