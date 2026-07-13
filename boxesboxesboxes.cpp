#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// input

	// n = the total number of boxes
	// next line contains n boxes each number l describes the length of each box

	int n; cin >> n;



	deque<int> boxes(n);
	for (int i = 0 ; i < n; i ++)
	{
		cin >> boxes[i];
	}
	sort(boxes.begin(), boxes.end());

	int box_size = (n + 1) / 2;

	if (box_size % 2 != 0) box_size--;

	if (box_size == 0) box_size = 1;

	vector<vector<int>> tower;

	int i = 0;
	while (box_size > 0 && !boxes.empty())
	{
		tower.push_back({});
		for (int j = 0; j < box_size; j++)
		{
			tower[i].push_back(boxes.back());
			boxes.pop_back();
		}
		box_size/= 2;
		i++;
	}

	if (!boxes.empty())
	{
		tower.push_back({});
		tower[i].push_back(boxes.back());
		boxes.pop_back();
	}

	reverse(tower.begin(),tower.end());

	cout << tower.size() << '\n';
	for (auto box : tower)
	{
		cout << box.size() << ' ';
		for (auto x : box)
		{
			cout << x << ' ';
		}
		cout << '\n';
	}
}