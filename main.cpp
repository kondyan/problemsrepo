#include <bits/stdc++.h>
using namespace std;
#define int int64_t
template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;
	vector<int> a;
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	vector<int> ans;
	ans.push_back(a[0]);

	for (int i = 1; i < n; i++)
	{
		if (a[i] > ans.back())
		{
			ans.push_back(a[i]);
		} else
		{
			int first_larger = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
			ans[first_larger] = a[i];
		}
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < i; j++)
	// 	{
	// 		if (a[j] < a[i])
	// 		{
	// 			dp[i] = max(dp[i], dp[j] + 1);
	// 		}
	// 	}
	// }




	cout << ans.size() << '\n';
}