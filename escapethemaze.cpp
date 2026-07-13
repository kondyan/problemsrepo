#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool check(vector<vector<int>> &adj, vector<int> & earliest_friend_dist, vector<int> &vlad_dist , unordered_set<int> &leafs,int start, int n)
{
	queue<int> q;
	vector<int> visited(n,0);
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (visited[node]) continue;
		visited[node] = 1;
		if (leafs.contains(node)) return true;

		for (auto child : adj[node])
		{
			if (earliest_friend_dist[child] <= vlad_dist[child]) continue;
			if (visited[child]) continue;
			q.push(child);
		}
	};
	return false;

}

	void bfs_friend(vector<vector<int>> &adj, vector<int> & earliest_friend_dist, vector<int> &friends, int n)
	{
		queue<pair<int,int>> q;
		vector<int> dist(n,-1);
		vector<int> visited(n,0);
	for (auto x :friends)
	{
		q.push({x,0});
	}
		while (!q.empty())
		{
			int node = q.front().first;
			int distance = q.front().second;
			q.pop();


			if (visited[node]) continue;
			visited[node] = 1;
			dist[node] = distance;
			earliest_friend_dist[node] = min(earliest_friend_dist[node], dist[node]);

			for (auto child : adj[node])
			{
				if (visited[child]) continue;
				q.push({child, distance + 1});
			}

		}
	}

	vector<int> bfs(vector<vector<int>> &adj,unordered_set<int>&leafs, int start, int n)
	{
		queue<pair<int,int>> q;
		vector<int> dist(n,-1);
		vector<int> visited(n,0);
		q.push({start,0});
		while (!q.empty())
		{
			int node = q.front().first;
			int distance = q.front().second;
			q.pop();


			if (visited[node]) continue;
			visited[node] = 1;
			dist[node] = distance;


			for (auto child : adj[node])
			{
				if (visited[child]) continue;
				if (adj[child].size() == 1) leafs.insert(child);

				q.push({child, distance + 1});
			}



		}
		return  dist;
	}


	void solve()
	{
		int n, k; cin >> n >> k; // number of rooms and number of friends
		vector<int> friends;
		vector<vector<int>> adj(n,vector<int>());

		for (int i = 0; i < k; i++)
		{
			int x; cin >> x;x--; friends.push_back(x);
		}

		for (int i = 0; i < n-1; i++)
		{
			int u, v; cin >> u >> v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

	unordered_set<int>leafs;

		vector<int> vlad_dist = bfs(adj,leafs, 0,n);

		vector<int> earliest_friend_dist (n, INT64_MAX);

			bfs_friend(adj, earliest_friend_dist,friends , n);


	if (check(adj, earliest_friend_dist,vlad_dist, leafs, 0, n))
	{
		cout << "YES" << '\n';
	} else
		cout << "NO" << '\n';
	}

	signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);

		int t; cin >> t;
		while (t--) {solve();}

	}
