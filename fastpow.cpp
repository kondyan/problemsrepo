#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int fastpow(double x, int n)
{
	// x  =base n = exponent
	if (n < 0)
	{
		x =  1 / x;
		n = -n;
	}

	double result  = 1.0;
	double currentproduct = x;

	while (n > 0)
	{
		if (n & 1)
		{
			result *= currentproduct;
		}


		currentproduct *= currentproduct;

		n >>= 1;

	}

	return result;



}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b; cin >> a >> b;

	cout << fastpow(a,b) << '\n';
}