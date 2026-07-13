#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int counter = 0;
	unordered_map<int, int> m;
	int n;
	cin >>n;



	for (int i = 0; i <n; i++)
	{
		char x;
		cin >> x;
		m[x]++;
	}

	int r=0;
	for (auto [k,v] : m)
	{
		r = max(r, v);
	}



	cout << r << '\n';
}