#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;
	vector<int> arr;
	// vector<int> dp(n, 1);
	map<int,pair<int,int>> dp;
	deque<int> resultArr;

	for (int i = 0; i<n;i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);

	}

	int res = 1;
	for (int i = 0; i<n;i++)
	{
		// for (int j = i - 1; j >= 0; j--)
		// {
		// 	if (arr[i] - 1 == arr[j])
		// 	{
		// 		dp[i] = dp[j] + 1;
		// 		res = max(res, dp[i]);
		// 		break;
		// 	}

		dp[arr[i]] = {1, i};

		if (dp.contains(arr[i] - 1) && dp[arr[i] - 1].second < dp[arr[i]].second )
		{
			dp[arr[i]].first = dp[arr[i] - 1].first + 1;
			res = max(res, dp[arr[i]].first);
			continue;
		}

		}

		// dp[i] = max(dp[i] - 1, dp[i]);



	for (int i = n-1; i>=0; i--)
	{
		if (dp[arr[i]].first == res)
		{
			int counter=arr[i];
			resultArr.push_front(i + 1);
			for (int j = i; j >=0; j--)
			{
				if (arr[j] == counter - 1)
				{
					resultArr.push_front(j +1);
					counter--;
				}
			}
			break;
		}
	}

	cout << res << '\n';
	for (auto num : resultArr)
	{
		cout << num << ' ';
	}
	cout << '\n';
	return 0;
}