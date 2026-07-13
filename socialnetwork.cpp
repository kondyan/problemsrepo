#include <bits/stdc++.h>
using namespace std;
#define int int64_t


struct UF
{
	vector<int> c;
	vector<int> size;
	int n;
	int find(int x){return x == c[x] ? x : c[x] = find(c[x]);}
	int solve(int &spare)
	{
		vector<int> roots;
		for (int i = 0 ; i < n; i++)
		{
			if (c[i] == i) roots.push_back(size[i]);
		}
		sort(roots.begin(),roots.end());
		reverse(roots.begin(),roots.end());
		int totalSize = 0;
		for (int i = 0; i < spare + 1;i++)
		{
			totalSize+=roots[i];
		}
		return totalSize-1;
	}
	void unite(int a, int b, int &spare)
	{
		int parentA = find(a);
		int parentB = find(b);

		if (parentA == parentB)
		{
			spare++;
			return;
		};


		if (size[parentB] < size[parentA]) swap(parentA, parentB);
		c[parentA] = parentB;
		size[parentB] += size[parentA];
	}

	UF(int n): c(n),size(n,1), n(n) {iota(c.begin(),c.end(),0);}

};
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; int d;
	cin >> n >> d;
	UF uf(n);

	int spare =0;
	for (int i = 0; i < d; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		uf.unite(a-1,b-1,spare);
		cout << uf.solve(spare) << '\n';



	}
}