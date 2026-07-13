#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void bfs (vector<vector<int>> &adj,vector<int> &visited, int start, int target)
{
	queue<pair<int,int>> q;
	q.push({start, 0});

	while (!q.empty())
	{
		pair<int,int> i = q.front();
		q.pop();

		if (visited[i.first]) continue;
		visited[i.first] = i.second;

		for (auto node : adj[i.first])
		{
			if (visited[node]) continue;
			q.push({node, i.second + 1});
		}

	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);



	int n,m,t,q;
	cin >> n >>m >> t >> q;

	vector<vector<int>> adj(n, vector<int>());
	vector<int> visited(n, 0);


	for (int i = 0; i < m ; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
// 890878

  bfs(adj,visited,t, 0);

	for (int i = 0; i < q; i++)
	{
		int s;
		cin >> s;

		if (s == t)
		{
			cout << 0 << '\n';
			continue;
		}

		cout << visited[s] << '\n';
	}

	return 0;
}