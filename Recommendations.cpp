#include <bits/stdc++.h>
using namespace std;
#define int long long


bool customComparison(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
	if (a.first != b.first)
	{
		// sort ascending
		return a.first < b.first;
	} else
	{
		// sort descending
		return a.second.first > b.second.first;
	}
}

bool customComparison2(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
	if (a.second.first != b.second.first)
	{
		// sort descending
		return a.second.first > b.second.first;
	} else
	{
		// sort ascending
		return a.first < b.first;
	}
}
void solve()
{
	int n; cin >> n;
	vector<pair<int,pair<int,int>>> segments(n);

	set<pair<int,int>>skip;
	set<pair<int,int>> seen;
	for (int i =0;i < n; i ++)
	{
		int l, r; cin >> l >> r;
		segments[i] = {l, {r,i}};

		// skip if there are dublicate ranges
		if (seen.contains({l,r}))
		{
			skip.insert({l,r});
		};
		seen.insert({l,r});
	}

	// sort with the first comparison function
	sort(segments.begin(),segments.end(), customComparison);


	set<int> r_s;


	// ans array
	vector<int> ans(n,0);

	for (auto &elem : segments)
	{

		int l = elem.first;
		int r = elem.second.first;
		int i = elem.second.second;


		// find the first R that is lower than the current R
		// this would be the first predictor of the current user because sorting them by L
		// in ascending order ensures that both Ri <= Rj and Li <= Lj
		auto next_r = r_s.lower_bound(r);

		// if no predictor was found insert current R and continue the process
		if (next_r == r_s.end())
		{
			r_s.insert(r);
			continue;
		}

		// get the value of the itterator
		int closest_r = *next_r;


		// if l is equals to r then the current element WILL NEVER be a predictor of a user in the future so skip
		if (l != r)
		{
			r_s.insert(r);
		}

		// if curr user doesnt have dublicates, add the difference between user's R and the earliest predictor's R
		if (!skip.contains({l,r}))
		{
			ans[i] += closest_r - r ;
		}
	}

	// we've solved half the problem because we considered only the right border difference
	// can we cast the problem to the L border. Let's do the opposite


	// save all the L's here to find the first L that is strictly smaller than the current L
	set<int> l_s;


	// sort DESC by R and ASC by L to consider all the predictors from Outside inside
	// exactly the opposite from the first comparison Sorting function
	sort(segments.begin(),segments.end(),customComparison2);

	for (auto &elem : segments)
	{
		int l = elem.first;
		int r = elem.second.first;
		int i = elem.second.second;

		// find the first one that is larger (we decrement iterator by one afterwards)
		// did this to avoid issues with reverse itterators
		auto next_l = l_s.upper_bound(l);

		// check if we found something
		if (next_l == l_s.begin())
		{
			l_s.insert(l);
			continue;
		}

		// get the first smaller (or equal) one
		int closest_l = * --next_l;


		// if the range doesnt have length it cant be a predictor for any user in the future
		if (l != r)
		{
			l_s.insert(l);
		}

		// if it's not dublicate add the diff of the l and the closest predictor's L
		if (!skip.contains({l,r}))
		{
			ans[i] += l - closest_l ;
		}
	}

	// output answer for each user
	for (auto a : ans)
	{
		cout << a << '\n';
	}

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