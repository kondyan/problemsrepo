#include <bits/stdc++.h>
using namespace std;
#define int int64_t


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);



	int n, k; cin >> n >> k;
	vector<int> arr;
	vector<int> prefix(n+1,0);

	for (int i =0; i < n; i++ )
	{
		int d; cin >> d;
		arr.push_back(d);
	}

	for (int i = 1; i <=n;i++)
	{
		prefix[i] = prefix[i-1] + arr[i-1];
	}

	int res = INT64_MAX;


	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			int a = prefix[n] - prefix[i];

			res = min(res,  abs(prefix[i] - a));
		}
	} else
	{
		for (int i = 0; i <= n; i++)
		{
			int first_cut = prefix[i];
			int curr_res = INT64_MAX;
			for (int j = i + 1; j <=n;j++)
			{
				int second_cut = prefix[j] - first_cut;
				int third_cut = prefix[n] - second_cut -  first_cut;
				curr_res = max({abs(second_cut - first_cut), abs(third_cut - first_cut), abs(third_cut - second_cut)});
				res = min(res, curr_res);
				if (second_cut > third_cut) break;
			}
			}

		}


	cout << res << '\n';

	}

