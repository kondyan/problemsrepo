#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool dfs(vector<vector<int>> &adj, vector<int> &visited,vector<int> &coloring, int i, int currColor)
{
  if (visited[i]) return true;
	visited[i] = 1;
	coloring[i] = currColor;

	int nextColor = 1 - currColor;



	for (auto node : adj[i])
	{
		if (coloring[i] == coloring[node]) { return false;};
		if (visited[node] == 1) continue;
		if (!dfs(adj,visited,coloring,node,nextColor)) return  false;

	}
	return true;

}

void solve()
{
	int n; cin >> n;
	unordered_map<int, int > m;
	vector<vector<int>> adj(n+1, vector<int>());
	vector<int> visited(n+1,0);
	vector<int> coloring(n+1,0);
	bool ok = 1;
	for (int i = 0; i < n; i++)
	{
		int a,b; cin >> a >> b;

		if (a == b)
		{
			ok = 0;
		}

		adj[a].push_back(b);
		adj[b].push_back(a);
		m[a]++;
		m[b]++;


		if (m[a] > 2 || m[b] > 2)
		{
			ok = 0;
		}
	}

	if (!ok)
	{
		cout << "NO" << '\n';
		return;
	}

	for (int i = 1; i <= n;i++)
	{
		if (!dfs(adj,visited,coloring, i, -1))
		{
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES" << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0;i < t; i++)
	{
		solve();
	}
}