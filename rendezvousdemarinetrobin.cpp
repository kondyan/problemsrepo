#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<vector<int>> dijkstra(vector<vector<pair<int,int>>> &adj, int start, int target, int n, unordered_set<int> &horses)
{
	priority_queue<tuple<int,int,int>> pq;
	vector<vector<int>> dist(2,vector<int>(n, INT64_MAX));
	pq.push({0, start, 0});


	while (!pq.empty())
	{
		auto [d,v, s]  = pq.top(); pq.pop();
		if (dist[s][v] != INT64_MAX) continue;
		dist[s][v] = -d;
		for (auto [u, w ]: adj[v])
		{
			pq.push({-(w + dist[s][v]), u, 0});
			if (horses.contains(v) || s == 1)pq.push({-(w/2 + dist[s][v]), u, 1});

		}
	}

	return dist;
}

void solve()
{
	int n, m, h; cin >> n >> m >> h;
	unordered_set<int> horses;
	// pair.first == pointer to next node pair.second = weight
	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

	for (int i = 0; i< h;i++)
	{
		int a; cin >> a;
		horses.insert(a-1);
	}

	for (int i = 0 ; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w; u--; v--;

		adj[u].push_back({v,w});
		adj[v].push_back({u,w});


	}


	vector<vector<int>> marinaDis = dijkstra(adj, 0, n-1,n,horses);
	vector<vector<int>> robinDis = dijkstra(adj, n-1, 0,n,horses);

	int res = INT64_MAX;

	for (int i =0; i < n;i++)
	{
		int marinasTime = min(marinaDis[0][i], marinaDis[1][i]);
		int robinsTime = min(robinDis[0][i], robinDis[1][i]);


		if (marinasTime == INT64_MAX||robinsTime == INT64_MAX) continue;

		int buffer = max(marinasTime,robinsTime);

		res = min(res,buffer);

	}

	if (res == INT64_MAX)
	{
		cout << -1 << '\n';
		return;
	}

	cout << res << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0 ; i<t; i++)
	{
		solve();
	}
	return 0;
}