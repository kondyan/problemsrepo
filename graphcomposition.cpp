#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct UF
{
	vector<int> c1;
	vector<int> buffer;
	vector<int> c2;
	vector<int> sizec1;
	vector<int> sizec2;
	vector<int> sizebuffer;
	UF (int n): c1(n), c2(n), buffer(n), sizec1(n,1), sizec2(n,1), sizebuffer(n, 1) {iota(c1.begin(), c1.end(), 0); iota(c2.begin(), c2.end(),0); iota(buffer.begin(),buffer.end(), 0);}
	int findc1(int x) {return x == c1[x] ? x : c1[x] = findc1(c1[x]);}
	int findc2(int x) {return x == c2[x] ? x : c2[x] = findc2(c2[x]);}
	int findbuff(int x) {return x == buffer[x] ? x : buffer[x] = findbuff(buffer[x]);}



	void unitec1(int a, int b)
	{
		int rootA = findc1(a);
		int rootB = findc1(b);

		if ( rootA != rootB)
		{
			if (sizec1[rootB] < sizec1[rootA]) swap(rootA, rootB);
			c1[rootA] = rootB;
			sizec1[rootB]+= sizec1[rootA];
		}

	}
	void unitec2(int a, int b)
	{
		int rootA = findc2(a);
		int rootB = findc2(b);

		if ( rootA != rootB)
		{
			if (sizec2[rootB] < sizec2[rootA]) swap(rootA, rootB);
			c2[rootA] = rootB;
			sizec2[rootB]+= sizec2[rootA];

		}
	}
	void unitebuffer(int a, int b) {
		int rootA = findbuff(a);
		int rootB = findbuff(b);

		if ( rootA != rootB)
		{
			if (sizebuffer[rootB] < sizebuffer[rootA]) swap(rootA, rootB);
			buffer[rootA] = rootB;
			sizebuffer[rootB]+= sizebuffer[rootA];

		}
	}

};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m1, m2;
		cin >> n >> m1 >> m2;

		UF uf(n);

		vector<pair<int,int>> firstEdges;
		vector<pair<int,int>> secondEdges;

		for (int j = 0; j<m1; j++)
		{
			int u, v;
			cin >> u >> v;
			uf.unitebuffer(u-1, v-1);
			firstEdges.push_back({u -1,v -1});
		}

		for (int j = 0; j < m2; j++)
		{
			int u, v;
			cin >> u >> v;
			uf.unitec2(u-1, v-1);
			secondEdges.push_back({u-1,v-1});
		}
		int counter = 0;

		for (auto [u, v] : firstEdges)
		{
			if (uf.findc2(u) == uf.findc2(v))
			{
				uf.unitec1(u, v);
				continue;
			}
			counter++;

		}



		for (auto [u, v] : secondEdges)
		{
			if (uf.findc1(u) == uf.findc1(v)) continue;
			uf.unitec1(u,v);
			counter++;
		}




		cout << counter << '\n';
	}
}