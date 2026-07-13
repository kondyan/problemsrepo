#include <bits/stdc++.h>
using namespace std;
#define int int64_t

pair<int,int> dfs(vector<vector<int>> &adj, int parent, vector<int> &arr ,int u)
{

	int max_pos = 0;
	int max_neg = 0;
	if (adj[u].empty())
	{
		if (arr[u] < 0)
		{
			max_pos += abs(arr[u]);
		} else
		{
			max_neg += arr[u];
		}
		return {max_pos, max_neg};
	}


	for (auto v : adj[u])
	{
		if (v == parent)continue;
		pair<int,int> child = dfs(adj,u,arr,v);

		max_pos = max(max_pos, child.first);
		max_neg = max(max_neg,child.second);



	}
	int currValue = arr[u] + max_pos -	max_neg;
	if (currValue < 0)
	{
		max_pos+=abs(currValue);
	} else
	{
		max_neg+= currValue;
	}

	return {max_pos,max_neg};
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int>arr;
	vector<vector<int>> adj(n,vector<int>());
	for (int i = 0; i < n-1;i++)
	{
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int v; cin >> v;
		arr.push_back(v);
	}


	pair<int,int> res  = dfs(adj,-1,arr,0);

	cout << res.first + res.second << '\n';
}