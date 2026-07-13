#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;
	unordered_map<int,int> s;
	int sum = 0;
	for (int i = 0; i<n;i++)
	{
		int x;
		cin >> x;

		if (x > 0)
		{
			s[x]++;
			sum++;
			cout << "Thank you!" << '\n';
		} else if (x < 0)
		{
			if (s.contains(abs(x)))
			{
				s[abs(x)]--;
				sum--;
				if (s[abs(x)] <= 0)s.erase(abs(x));

				cout << "Here you go!" << '\n';
			} else
			{
				cout << "I am sorry!" << '\n';
			}
		} else
		{
			int sum=0;
			for (auto [k, v] : s)sum += v;
			cout << sum << '\n';
		}
	}
}