#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	int n; cin >> n;



	int counter = 1;
	int counterB = n*3;

	while (counter <= n)
	{
		cout << counterB << ' ' << counterB -1 << ' ' << counter << ' ';
		counterB-=2;
		counter++;
	}



	cout << '\n';
	return;

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