#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	unordered_set<char> occurences;
  string baguette; cin >> baguette;
	for (int i = 0 ; i < baguette.size(); i ++)
	{
		char centimeter = baguette[i] - 'a';
		occurences.insert(centimeter);
	}
	int res = INT64_MAX;
	for (auto key : occurences)
	{
		int i = 0;
		int local_res = 0;
		while (i < baguette.size())
		{
			char currC=baguette[i] - 'a';
			if (currC == key) {i++;continue;}
			local_res++;
			i+=k;
		}
		res = min(res, local_res);
	}
	cout << res << '\n';

}