#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	vector<int> a;
	vector<int> b;
	int n, m; cin >> n >> m;

	for (int i = 0 ; i < n ; i ++ )
	{
			int x; cin >> x; a.push_back(x);
	}
	for (int i =0; i < m; i ++)
	{
		int x; cin >> x; b.push_back(x);
	}

	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());

	for (auto num : b)
	{
		int idx = lower_bound(a.begin(),a.end(), num, greater<int>()) - a.begin();
		int c = *lower_bound(a.begin(),a.end(), num, greater<int>());

		cout << n -idx << ' ';
	}
	cout << '\n';

	return 0;
}