	#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n; // number of mountains;
	vector<pair<int,int>> mountains;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y; // coordinates of mountain peak
		mountains.push_back({x,y});
	}
	int m; cin >>m;
	for (int i = 0 ; i < m;i++)
	{
		int a, b; cin >> a >> b; // a = index of the valey b = index of the mountain that should get wet
	}
}