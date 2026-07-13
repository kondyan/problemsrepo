#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> costs;
	int n, s;
	cin >> n >> s;

	int startTotal = 0;
	for (int i =0 ;i < n; i++)
	{
		int a;
		cin >> a;

		costs.push_back(a);
		startTotal += a + (i+1) * n;
	}

	if ( startTotal <= s)
	{
		cout << n << ' ' << startTotal << '\n';
		return 0;
	}



	int l = 0;
	int r = n;
	int maxItems = 0;


	int res= 0;
	int total=0;
	while (r - l > 1)
	{
		int k = l +(r-l) / 2;
		int currTotal = 0;


		vector<int> currCosts(n,0);
		for (int i = 0; i < n; i ++) currCosts[i] = costs[i] + (i + 1) *k; // build actual costs;
		sort(currCosts.begin(), currCosts.end()); //sort everything to get k cheapest items

		for (int i =0; i < k; i++) currTotal+=currCosts[i];






		if (k >= maxItems && currTotal <= s)
		{
			l = k;
			total = currTotal;
			maxItems = k;
		} else
		{
			r = k;
		}

	}

	cout << maxItems << ' ' << total <<  '\n';
}