#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve(int T)
{
	int A;cin >> A;

	int n; cin >> n;
	set<int> s;

	for (int i = 0; i < n; i++) {int d; cin >> d; s.insert(d); }
	string a = to_string(A);



	int flag = 1;
	for (auto c : a)
	{
		if (!s.contains(c - '0'))
		{
			flag = 0; break;
		};
	}

	if (flag)
	{
		cout << 0 << '\n';
		return;
	}

	string first_smaller;

	// 2 cases
	// 1st case we have a.size() - 1 numbers, in this case fill them up with s.rbegin()
	// 2nd case we have a.size() numbers, then we need to get first number smaller than a[i] and fill the rest with s.rbegin()


	for (int i = 0; i < a.size(); i++)
	{
		auto p = s.lower_bound(a[i] - '0');

		if (s.contains(a[i] - '0'))
		{
			first_smaller.push_back(a[i]);
		} else
		{
			if (p-- != s.begin())
			{
				first_smaller.push_back(*p + '0');
				for (int j = i; j < a.size() -1 ; j++)
				{
					first_smaller.push_back(*s.rbegin() + '0');
				}
			} else
			{
				
			}



				break;
		}

	}
	// if satisfied the second case falls out


	string first_larger;

	// 2 cases
	// 1st case we have a.size() + 1 numbers, in this case fill them up with s.begin()
	// 2nd case we have a.size() numbers, get the first number larger than a[i] and fill the rest with s.begin()

	for (int i = 0; i < a.size(); i++)
	{
		auto p = s.lower_bound(a[i] - '0');

		if (s.contains(a[i] - '0'))
		{
			first_larger.push_back(a[i]);
		} else
		{
			if (p != s.end())
			{
				first_larger.push_back(*p + '0');
				for (int j = i; j < a.size() -1 ; j++)
				{
					first_larger.push_back(*s.begin() + '0');
				}
			}  else
			{
				for (int j = i; j < a.size() ; j++)
				{
					first_larger.push_back(*s.begin() + '0');
				}
			}

			break;
		}
	}


	if (first_larger.empty())
	{
		first_larger = first_smaller;
	}
	if (first_smaller.empty())
	{
		first_smaller = first_larger;
	}
	int b2 = stoll(first_larger);
	int b1 = stoll(first_smaller);
	int ans1 = abs(A - b1);
	int ans2 = abs(A - b2);

	int ans = min(ans1,ans2);
	cout << ans << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		solve(t);
	}




}