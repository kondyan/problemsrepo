#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i< n; i++)
	{
		int x;
		cin >>x;
		res += x;
	}

	cout << res << '\n';
}