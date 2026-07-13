#include <bits/stdc++.h>
using namespace std;
#define int long long


int bfs(vector<vector<int>> &adj, vector<int> &visited, queue<pair<int,int>> &q, int n)
{
	while (!q.empty())
	{
		int distance = q.front().first;
		int node = q.front().second;
		q.pop();

		if (node == n-1)
		{
			return distance;
		}

		// if (visited[node] == 2) continue;
		visited[node] = distance;

		for (auto child : adj[node])
		{
			if (visited[child]) continue;
			q.push({distance+1, child});
		}
	}
}

int find_to_c(vector<vector<int>> &adj, vector<int> &visited, vector<pair<int,int>> &holes, int c)
{
	queue<pair<int,int>> q;
	q.push({0,0});
	int ans = -1;

	while (!q.empty())
	{
		int distance = q.front().first;
		int node = q.front().second;
		q.pop();

		if (node == c)
		{
			ans = distance;
		}

		// if (visited[node] == 2) continue;
		visited[node] = distance;

		for (auto child : adj[node])
		{
			if (visited[child] == -1) visited[child] = distance + 1;
			if (visited[child]) continue;
			q.push({distance+1, child});
		}
	}

	return ans;
}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, h, c; cin >> n >> m >> h >> c;

	vector<vector<int>> adj(n,vector<int>());
	// 2=holes
	vector<int> visited(n,0);
	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<pair<int,int>> holes;
	for(int i = 0;i < h; i++)
	{
		int v, k; cin >> v >> k;
		visited[v] = -1;
		holes.emplace_back(v,k);
	}

	int to_c = find_to_c(adj,visited,holes,c);

	if (to_c == -1)
	{
		cout << to_c << '\n';
		return 0;
	}

	queue<pair<int,int>> q;

	unordered_map<int,int > times;

	for (auto [v,k] : holes)
	{
		times[visited[v] - k] = visited[v];
	}

	for(int i = 0; i < n; i++)
	{
		if (times.contains(visited[i])) q.push({times[visited[i]], i});
	}
	q.push({visited[c],c});

	visited = vector<int>(n,0);
	int ans = bfs(adj,visited,q,n);

	cout << ans << '\n';
}