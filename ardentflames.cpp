#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool check(int a, int n, int m, vector<int> &healths, vector<int>&positions, int k)
{
	vector<pair<int,int>> events;

	for (int i = 0; i < n;i++)
	{

		if (a == 0) break;
		// MIN DAMAGE PER HIT
		int d = (healths[i] + a - 1) / a;
		// if the total damage per hit for A hits is more than the max amount of single hits we can do, skip the enemy;
		if (d > m) continue;


		int dist = m- d;
		int l = positions[i] - dist;
		int r = positions[i] + dist;

		events.push_back({l, -1});
		events.push_back({r, 1});
	}

	sort(events.begin(),events.end());
	int currRes = 0;

	for (auto [pos, type] : events)
	{
		if (type == -1) currRes++;
		if (type == 1) currRes--;

		if (currRes >= k) return true;
	}
	return false;
}

void solve()
{
	int n, m, k; cin >> n >> m >> k; // n = enemies m = max damage k = enemies to defeat
	vector<int> healths;
	vector<int> positions;
	for (int i = 0; i < n ;i ++)
	{
		int h; cin >> h; // h = health of each enemy
		healths.push_back(h);
	}

	for (int i = 0; i <n;i++)
	{
		int x; cin >> x;
		positions.push_back(x);
	}

	int l = -1;
	int r = 1e18;


	while (r - l > 1)
	{
		// number of attacks A
		int a = l+(r-l)/2;
		if (check(a, n, m, healths, positions,k))
		{
			r = a;
		} else
		{
			l = a;
		}
	}


	if (r != 1e18)
	{
		cout << r << '\n';

	} else
	{
		cout << -1 << '\n';
	}


}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--)
	{
		solve();
	}
}