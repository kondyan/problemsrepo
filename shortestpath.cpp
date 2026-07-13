#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dijkstra(vector<vector<pair<int,int>>> & adj, int n, int start)
{
	vector<int>dist(n,-1);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({0,start});

	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] != -1 ) continue;
		dist[node] = distance;

		for (auto [v, w]: adj[node])
		{
			pq.push({distance + w,v});
		}

 	}

	return dist;

}
signed main ()
{

	int n, m; cin>>n>>m;

	vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());

	for (int i = 0 ; i < m; i ++)
	{
		int u , v, w; cin >> u >> v >> w; u--; v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});

	}

	vector<int> dist = dijkstra(adj, n, 0);

	for (auto ans : dist)
	{
		if (ans == 11) ans++;
		cout << ans << '\n';

	}
	return 0;
}