#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;

	if ( n == 1)
	{
		cout << 0 << '\n';
		return 0;
	} else if (n == 2)
	{
		cout << "impossible" << '\n';
		return 0;
	} else if ( n == 3)
	{
		cout << "impossible" << '\n';

	} else if (n==4)
	{
		cout << "1 3 0 2" << '\n';
		return 0;
	} else if (n ==5)
	{
		cout << "1 3 0 2 4"<< '\n';
		return 0;
	}

	cout << 0 << ' ';
	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 0)
		{
			cout << i << ' ';
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (i % 2 != 0)
		{
			cout << i << ' ';
		}

	}
	cout << '\n';
}