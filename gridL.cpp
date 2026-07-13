#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int p, q; cin >> p >> q;

	int S = p + 2*q;
	for (int n = 1; n <= 13000; n++)
	{
		// the m if we have number of edges = n(m+1) + m(n+1) (horizontal and vertical edges/lines)

		int m = (S - n) / (2*n + 1);

		// now we can check if we've used all the edges

		if (m * (n+1) + n*(m+1) == S && p >= abs(n-m))
		{
			cout << n << ' ' << m << '\n';
			return;
		}
	}

	cout << -1 << '\n';
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