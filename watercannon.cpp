#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> arr;
	for (int i = 0 ; i < n; i ++)
	{
		int a; cin >>a ;
		arr.push_back(a);
	}

	vector<vector<int>> sequences(n,vector<int>());
	vector<int> round_maxes;
	round_maxes.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		auto round = upper_bound(round_maxes.begin(), round_maxes.end(), arr[i],greater<int>());

		int idx = round - round_maxes.begin();
		if (round == round_maxes.end())
		{
			round_maxes.push_back(arr[i]);
		} else
		{
			sequences[idx].push_back(round_maxes[idx]);
			round_maxes[idx] = arr[i];
		}
	}

	for (int i = 0; i < round_maxes.size(); i++)
	{
		sequences[i].push_back(round_maxes[i]);
	}


	cout << round_maxes.size() << '\n';
	for (auto sequence : sequences)
	{
		if (sequence.size()==0) continue;
		for (auto num : sequence)
		{
			cout << num << ' ';
		}
		cout << '\n';
	}

	return 0;




}