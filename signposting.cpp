#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void dijkstra(vector<vector<pair<int,int>>> &adj, vector<int> &visited, int start, int target ,int n)
{
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n, -1);
	pq.push({0, start});
	dist[start] = 0;

  while (!pq.empty())
  {
	  int distance = -pq.top().first;
  	int pos = pq.top().second;
  	pq.pop();

    if (dist[pos] != -1 && dist[pos] < distance) continue;

  	for (auto node: adj[pos] )
  	{
  		int weight = node.first;
  		int edge = node.second;

  		if (dist[edge] != 1 && dist[edge] <= )
  	}

  }
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, m, e, c, s; // e= entrance c=  contest room s = stof'ls start point/storage point
	cin >> n >> m >> e >> c >> s;

	vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

	for (int i = 0; i < m; i++)
	{
		int a,b,t;
		cin >> a >> b >> t;
		adj[a].push_back({t, b});
	}
}