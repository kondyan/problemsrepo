#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int MOD = 998244353;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> X;
	vector<int> Y;
	vector<int> S;
	vector<int> dp(n,0);
	vector<int> p(n + 1, 0);

	int total_time = 0;
	for (int i = 0; i < n; i ++)
	{
		int x, y, s; // x = where the teleport is y = where it brings you s = the current state (0,1)
		cin >> x >> y >> s;


		X.push_back(x); Y.push_back(y); S.push_back(s);

		int j = lower_bound(X.begin() ,X.end(), y) - X.begin();

		dp[i] = (x - y + p[i] - p[j] + MOD) % MOD;
		p[i + 1] = (p[i] + dp[i]) % MOD;

		if (s == 1) total_time = (total_time + dp[i]) % MOD;
	}
	 total_time = (total_time + X[n-1] + 1) % MOD;




	cout << total_time << '\n';

}