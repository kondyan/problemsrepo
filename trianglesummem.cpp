#include <bits/stdc++.h>
using namespace std;
#define int int64_t
//
// int solve(int i, vector<int> currRow, int length, int n)
// {
// 	if (length  == n) return max(currRow[i], currRow[i+1]);
// 	vector<int> row;
// 	for (int j = 0; j < length + 1; j++)
// 	{
// 		int x;
// 		cin >> x;
// 		row.push_back(x);
// 	}
//
// 	int res= max(solve(i+1, row,length+1, n), solve(i,row, length+1, n)) + currRow[i];
// 	return res;
// }

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >>n;

	if (n == 1)
	{
		int x;
		cin >> x;
		cout << x << '\n';
		return 0;
	}

	vector<int> lastRow(n,0);
	vector<int> row;


	int x;
	cin >> x;
	lastRow[0] = x;

	for (int i = 1; i < n ; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int x;
			cin >> x;


			if (j == 0) {row.push_back(lastRow[j] + x); continue;};
			if (j == i) {row.push_back(lastRow[j-1] + x);continue;};

			row.push_back(max(lastRow[j], lastRow[j-1]) + x);
		}
		lastRow=  row;
		row = vector<int>();
	}

	int res = 0;
	for (auto num : lastRow) res = max(res, num);

	cout << res <<'\n';
	return 0;
}