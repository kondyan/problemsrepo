#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int getOne(int a, int m)
{
	return m/a;
}

int getTwo (int a,int b, int m)
{
	return m /lcm(a,b);
}

int getThree(int a, int b,int c, int m)
{
	return m/lcm(lcm(a,b), c);
}

int get(int a, int b, int c, int m)
{
	int c1 = getOne(a ,m);
	int c2 = getTwo(a,b,m) + getTwo(a,c,m);
	int c3 = getThree(a,b,c,m);
	return (c1 - c2 + c3) * 6 + (c2 - 2 * c3) * 3 + c3 * 2;
}

void solve()
{
	int a, b, c, m; cin >> a >> b >> c >> m;

	cout << get(a,b,c,m) << ' ' << get(b,a,c,m) << ' ' << get(c,a,b,m) <<'\n';

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i=0; i < t; i++)
	{
		solve();
	}
}