#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, d; cin >> n >> d;
	vector<pair<int,pair<int,int>>> events;

	for (int i  = 0; i < n;i ++)
	{
		int l, r, d; cin >> l >> r >> d; // l = start fish r = end fish d = deepness
		events.push_back({l,{-1,r-l }});
		events.push_back({r, {1, r-l }});
	}
	sort(events.begin(), events.end());

	int ans = 0;
	int currWeight=0;
	for (auto event : events)
	{
		int action = event.second.first;
		int weight = event.second.second;
		if (action == -1) currWeight+=weight;
		if (action == 1) currWeight-=weight;
		ans = max(ans, currWeight);
	}
	cout << ans << '\n';
}