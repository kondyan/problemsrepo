#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;cin>>n;
	unordered_set<int> unique_bars;
	vector<int> occurences(1001,0);
	for (int i = 0 ; i  < n ; i ++)
	{
		int l; cin >> l;
		unique_bars.insert(l);
		occurences[l] ++;
	}

	int ans = 0;
	for (auto num : occurences)
	{
		if (num > ans) ans = num;
	}

	cout << ans << ' ' << unique_bars.size() << '\n';

}