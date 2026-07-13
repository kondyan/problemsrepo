#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct UF
{
	vector<int> c;
	int find(int x) {return x == c[x] ? x : c[x] = find(c[x]);}
	void unite(int a, int b)
	{
		int parA = find(a);
		int parB = find(b);
		if (parA == parB) return;
		c[parA ] = parB;
	}
	UF(int n): c(n) {iota(c.begin(),c.end(),0);}
};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int,pair<int,int>>> edges;

	for (int i = 0; i < m; i++)
	{
		int u, v, c; cin >> u >> v >> c;
		edges.push_back({c,{u,v}});
	}
	UF uf(n);
	sort(edges.begin(),edges.end());
	vector<int> costs;

	int totalCost = 0;
	for (auto edge : edges)
	{
		int cost = edge.first;
		int a = edge.second.first;
		int b = edge.second.second;

		if (uf.find(a) == uf.find(b)) continue;

		uf.unite(a,b);
		totalCost+= cost;
		costs.push_back(cost);
	}

	reverse(costs.begin(),costs.end());

	for (int i = 0; i < k; i++) totalCost-=costs[i];

	if (totalCost < 0) totalCost = 0;
	cout << totalCost << '\n';


}