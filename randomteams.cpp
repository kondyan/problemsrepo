#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	// we take the amount of people in the largest group to maximize the pairs
	// calculate amount of possible pairs with N c 2 formula
	int Max = ((n - m + 1) * (n - m + 1 - 1) ) / 2;


	// amount of people in the smaller group
	int other1 = n / m;

	// amount of people in the bigger group
	int other2 = n % m;

	// pairs combinations in the smaller group
	int ans1 = (other1 * (other1-1)) / 2;

	// number of pairs in the larger group (other1 + 1)
	int ans2 = ((other1 + 1) * other1) / 2;

	// total pairs from larger and smaller groups
	int ans3 = (ans1 * (m-other2) + ans2 * other2);

	cout << ans3 << ' ' << Max << '\n';
}