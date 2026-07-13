#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n; cin >> n;

	set<int> s;
	vector<int> arr;
	int poss = 1;
	for (int i = 0; i < n; i ++)
	{
		int x; cin >> x;
		if (s.contains(x)) poss = 0;

		s.insert(x);
		arr.push_back(x);
	}

	if (!poss) {cout << -1 << '\n'; return;}

	sort(arr.rbegin(),arr.rend());

	for (auto elem : arr)
	{
		cout << elem << ' ';
	}

	cout << '\n';
	return;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}