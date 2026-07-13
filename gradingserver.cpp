#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(map<int,int> &events, int X, int d, int s)
{
	int time = 0;
	int evaluations_required = 0;
	int skipped = 0;


	for (auto [t, c] : events)
	{
		int dead_line = t + d;

		evaluations_required = c;

		int shift = max((long long)0,time - t);




		time = max(time, t) + (c + X - 1) / X;

		int evaluated_intime = min(evaluations_required, X * d) - shift * X;

		if (time > dead_line)
		{
			skipped += evaluations_required - evaluated_intime;
		}

	}

	if (skipped > s) return false;

	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, s, d; cin >> n >> s >> d;
	map<int,int> events;
	// vector<pair<int,int>> events;
	for (int i = 0 ; i < n ; i ++)
	{
		int t, c; cin >> t >> c;
		events[t]+=c;
		// events.push_back({t,c});
	}


	int l = 0;
	int r = 1e9;

	while (r - l > 1)
	{
		int m = l + (r-l) / 2;
		if (check(events, m, d, s))
		{
			r = m;
		} else
		{
			l = m;
		}
	}

	cout << r << '\n';
}