#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n,m; cin >> n >>m;


	vector<int> arr(n);


	for (int i = 0; i < n ; i++)
	{
		cin >> arr[i];
	}

	int longest_equal_subarray = 1;
	int x = 1;

	for (int i = 1; i < n; i ++)
	{
		if (arr[i] == arr[i-1])
		{
			x++;
		}
		else
		{
			longest_equal_subarray = max(longest_equal_subarray, x);
			x = 1;
		}

	}

	longest_equal_subarray = max(longest_equal_subarray, x);


	if (longest_equal_subarray >=m)
	{
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';

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