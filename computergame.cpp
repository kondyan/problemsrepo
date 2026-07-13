#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int q;
	cin >> q;
	int k, n, a, b;

	for (int i = 0; i < q; i++)
	{
		cin >> k >> n >> a >> b;

		int l = -1;
		int r = 1e18;
		while (r - l > 1)
		{
			int mid = l + (r-l)/2;

			if (mid <= n && mid * a + (n-mid) * b < k)
			{
				l = mid;
			} else
			{
				r =  mid;
			}
		}
		cout << l << '\n';

	}



}