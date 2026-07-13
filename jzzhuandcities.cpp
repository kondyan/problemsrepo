#include <bits/stdc++.h>
using namespace std;


void dijkstra(vector<vector<pair<int,int>>> &adj, int n, int start,vector<int>&dist, vector<int> &in_degree)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0 , start});

	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();


		if  (dist[node] != -1 && dist[node] < distance) continue;
		dist[node] = distance;
		in_degree[node] ++;




		for (auto [v, x] : adj[node])
		{
			pq.push({distance + x,v});
		}
	}

}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k; cin >> n >> m >> k; // nodes, edges, trains

	vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
	vector<int> in_degree(n,0);
	for (int i = 0 ; i < m ; i ++)
	{
		int u, v, x; cin >> u >> v >> x; u--; v--;


		adj[u].push_back({v,x});
		// adj[v].push_back({u, x});

	}

	vector<int> dist(n, -1);


	int ans = 0;

	vector<pair<int,int>> train_routes;
	for (int i = 0 ; i < k ; i++)
	{
		int s ,y; cin >> s >> y ; s--;// from capital to s in y time
		train_routes.push_back({y,s});
		adj[0].push_back({s,y});
	}

	dijkstra(adj, n, 0, dist, in_degree);

	vector<vector<pair<int,int>>> new_adj(n, vector<pair<int,int>>());

	for (auto [v,x] : adj[0])
	{
		new_adj[0].push_back({v,dist[v]});
	}

	dist = vector<int>(n,-1);
	in_degree = vector<int>(n,-1);

	dijkstra(new_adj, n, 0, dist, in_degree);


	sort(train_routes.begin(), train_routes.end());
	reverse(train_routes.begin(),train_routes.end());


	for (auto [y, s] : train_routes)
	{
		if (dist[s] != y || in_degree[s] > 1)
		{
			ans++;
			in_degree[s] --;
		}
	}





	cout << ans << '\n';

}