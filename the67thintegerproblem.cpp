#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int x; cin >> x;
	if (x == 67)
	{
		cout << 67 << '\n';
		return;
	}
	cout << x + 1 << '\n';
	return ;
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