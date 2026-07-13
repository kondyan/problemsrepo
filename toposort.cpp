#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int dfs(vector<vector<int>> &adj,int i, vector<int> &visited, vector<int> &currSearch, vector<int> &toposorted)
{
	if (currSearch[i]) return 1;
	if (visited[i]) return 0;
	currSearch[i] = 1;
	visited[i] =1;

	for (auto node: adj[i])
	{
		if (dfs(adj, node, visited, currSearch, toposorted)) return 1;
	}
	currSearch[i] = 0;

	toposorted.push_back(i);

	return 0;
}

vector<int> toposort(vector<vector<int>> &adj, int n)
{
	vector<int> visited(n, 0);
	vector<int> currSearch(n, 0);
	vector<int> toposorted;

	for (int i =0; i<n; i++)
	{
		if (dfs(adj, i, visited, currSearch, toposorted))
		{
			return vector<int>();
		};
	}



	return toposorted;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0 ; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[b].push_back(a);
	}

	vector<int> toposorted = toposort(adj ,n);
	if ( toposorted.size()== 0)
	{
		cout << "IMPOSSIBLE" << '\n';
		return 0;
	}
	cout << "POSSIBLE" << '\n';

  for (auto node: toposorted)
  {
	  cout << node << ' ';
  }
	cout << '\n';

}