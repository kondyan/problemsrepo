#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n, k; cin >> n >> k;
	string s; cin >> s;
	deque<int> deq(n);
	for (int i = 0; i < n; i++)
	{
		deq[i] = (int) (s[i] - '0');
	}


	for (auto lamp : deq)
	{
		if (lamp == 1) break;
		deq.pop_front();
	}
	reverse(deq.begin(),deq.end());

	for (auto lamp : deq)
	{
		if (lamp == 1) break;
		deq.pop_front();
	}

	reverse(deq.begin(),deq.end());
	int ans = 0;

	int curr_dist = 1;
	for (int i = 1; i < deq.size();i++)
	{
		int lamp = deq[i];

		if (lamp == 1 && curr_dist != k) ans++;
		if (lamp == 1 && curr_dist == k) curr_dist = 0;
		curr_dist++;
	}

	cout << ans << '\n';
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}