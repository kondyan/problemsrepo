#include <bits/stdc++.h>
using namespace std;
#define int int64_t



signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	priority_queue<int>pq;

	for (int i = 0; i < n; i ++) {cin >> a[i];}

	int target = n;
	for (auto snack : a)
	{
		if (snack == target)
		{
			cout << snack << ' ';
			target = snack -1;
			while (!pq.empty() )
			{
				int x = pq.top();
				if (x != target) break;
				target = x-1;
				pq.pop();
				cout << x << ' ';
			}
		} else
		{
			pq.push(snack);
		}

		cout << '\n';
	}



}