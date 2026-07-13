#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool check(int R,int K,int n, vector<int> &positions)
{
	int tower = positions[0];
	int counter = 0;
	int i = 0;
	while (i < n)
	{
		counter ++;
		int coverage = tower+R;
		auto  next_tower = upper_bound(positions.begin(),positions.end(),coverage);
		if (next_tower == positions.end()) break;
		i = next_tower - positions.begin();
		tower = *next_tower;
	}

	return counter <= K;

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	vector<int> positions;
	if (k >= n)
	{
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x ;
		positions.push_back(x);
	}
	sort(positions.begin(),positions.end());
	int l = -1;
	int r = 1e18;
	while (r - l > 1)
	{
		int mid = l + (r-l) / 2;


		if (check(mid,k,n,positions))
		{
			r = mid;
		} else
		{
			l = mid;
		}
	}

	if (r % 2 == 0)
	{
		cout << r/2 << '\n';
	} else
	{
		cout << r/2 << ".5" << '\n';
	}
}