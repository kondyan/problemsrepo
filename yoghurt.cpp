#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n; cin >> n; // number of yoghurts
	vector<int> tree;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int> deps(n,0);
	for (int i = 0; i < n;i++)
	{
		int t; cin >> t;
		tree.push_back(t); // expiration dates of all youghurts
		if (i * 2 + 1 < n) deps[i] = 2;
	}

	for (int i = 1; i < n ; i++)
	{
		if ( i == 0) continue;
		tree[i] = min(tree[i], tree[(i - 1)/2] - 1);
		if (i * 2 + 1 >= n) pq.push({tree[i], i});
	}


	int day = 0;
	while (!pq.empty())
	{
		int exparation = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (exparation <= day)
		{
			cout << "no" << '\n';
			return 0;
		}

		// if (idx == 0) continue;
if (idx > 0)
{
	int par = (idx-1)/2;
	if (deps[par] > 0)
	{
		deps[par]--;
		if (deps[par] == 0) pq.push({tree[par],par});
	}
}


		day++;
	}
	cout << "yes" << '\n';
	return 0;
}

