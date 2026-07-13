#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> sieve(int limit)
{
	vector<bool> isPrime(limit+1,true);
	isPrime[0] = isPrime[1] = false;

	for (int i =2 ; i * i <= limit; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i;j<=limit;j+=i)
			{
				isPrime[j] = false;
			}
		}
	}

	vector<int> primes;
for (int i = 2 ; i <= limit;i++)
{
	if (isPrime[i]) primes.push_back(i);
}
	return primes;
}

void solve()
{
	int n ; cin >> n;

	if ( n == 2)
	{
		cout << 2 << ' ' << 1 << '\n';
		return;
	}

	vector<int> primes = sieve(2 * n * log(n));
	int last = primes[0];
	for (int i = 0; i < n;i++)
	{
		if (i == 0 || i == n-1)
		{
			cout << last << ' ';
		} else
		{
			cout << primes[i] * last << ' ';
		}
		last = primes[i];
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