#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n ; cin >> n;
	vector<int>arr(n);
	for (int i = 0 ; i < n;i ++)
	{
		cin >> arr[i];
	}

	vector<int> new_arr;
	for (int i = 0 ; i < n - 1; i ++)
	{
		for (int j = 0; j < arr.size() - 1; j++)
		{
			new_arr.push_back(arr[j] ^ arr.back());
		}
		arr = new_arr;
		new_arr = vector<int>();
		sort(arr.begin(),arr.end());
	}

	cout << arr[0] << '\n';
}

signed main()
{
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}