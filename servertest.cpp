#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n; // events
	vector<pair<int,int>> events;
	for (int i = 0 ; i < n ; i++)
	{
		int a, b; cin >> a >> b; // a = login b = logout
		events.push_back({a, -1});
		events.push_back({b,1});
	}

	sort(events.begin(),events.end());


	int ans = 0;
	int counter = 0;
	for (auto [time, event] : events)
	{
		if (event == -1) counter++; // login
		if (event == 1) counter--; // logout
		ans = max(ans,counter);
	}
	cout << ans << '\n';
}