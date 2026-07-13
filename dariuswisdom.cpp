#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(v) v.begin(), v.end()

void solve()
{
	int n; cin >> n;
	vector<int> arr;
	vector<int> finalArr;
	vector<pair<int,int>> operations;
	int counter = 0;

	int zeroCount = 0;
	set<int> pos1;

	for (int i = 0; i < n ; ++ i)
	{
		int a; cin >> a;
		arr.push_back(a);
		if (a == 0) zeroCount++;
		if (a == 1) pos1.insert(i);
	}

	// get the final wanted result to have a starting point for reconstruction
	finalArr = arr;
	sort(all(finalArr));


  int l = 0;
	int r = n -1;

	while (l <= r) {

		if (arr[l] == 0) {l++;continue;};

		while (r > l && arr[r] != 0) r--;

		if (r <= l) break;

		if (arr[l] == 1)
		{
			swap(arr[l], arr[r]);
			operations.push_back({l+1,r+1});
			counter++;
			pos1.erase(l);
			pos1.insert(r);
		} else
		{
			int j = *pos1.rbegin();
			swap(arr[l], arr[j]);
			swap(arr[l], arr[r]);
			operations.push_back({l+1, j+1});
			operations.push_back({l+1, r+1});
			counter+=2;
			pos1.erase(j);
			pos1.insert(r);
		}

		l++;
	}

	r = n-1;

	while (l <= r)
	{
		if (arr[l] == 1)
		{
			l++;
			continue;
		}
		while (r > l && arr[r] != 1) r--;

		if (r <= l) break;
		swap(arr[l], arr[r]);
		operations.push_back({l+1,r+1});
		counter++;
		l++;
	}


	cout << counter << '\n';

	for (auto [u, v] : operations)
	{
		cout << u << ' ' << v << '\n';
 	}

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}

	return 0;

}