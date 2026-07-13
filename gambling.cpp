#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct Value
{
	int max, pre,suf,sum;
	int maxL, maxR; // the best overall range
	int preR; // where the best prefix ends
	int sufL; // where the best suffix starts
};

Value combine(Value const&a, Value const&b)
{
	Value res;
  res.sum = a.sum + b.sum;

	// deciding on prefix
	if (a.pre >= a.sum + b.pre)
	{
		res.pre = a.pre;
		res.preR = a.preR;
	} else
	{
		res.pre = b.pre + a.sum;
		res.preR = b.preR;
	}

	// deciding on suffix

	if (b.suf >= b.sum + a.suf)
	{
		res.suf = b.suf;
		res.sufL = b.sufL;
	} else
	{
		res.suf = b.sum + a.suf;
		res.sufL = a.sufL;
	}


	// deciding overall


	if (a.max >= b.max && a.max >= (a.suf + b.pre))
	{
		res.max = a.max;
		res.maxL = a.maxL; res.maxR = a.maxR;
	} else if (b.max >= (a.suf+b.pre))
	{
		res.max = b.max;
		res.maxR = b.maxR; res.maxL = b.maxL;
	} else
	{
		res.max = a.suf + b.pre;
		res.maxL = a.sufL;
		res.maxR = b.preR;
	}

	return res;

	// return Value {
	// 	max({a.max,b.max, a.suf + b.pre}),
	// 	max(a.pre, a.sum + b.pre),
	// 	max(a.suf + b.sum, b.suf),
	// 	a.sum + b.sum
	// };
}

const Value neutral_element = {INT_MIN, INT_MIN, INT_MIN, 0,-1,-1,-1,-1};


Value divide_conquer (vector<int> &arr, int l, int r)
{
	if (l == r)
	{
		return Value{arr[l], arr[l], arr[l] ,arr[l],l,l,l,l};
	}

	int mid = l + (r-l)/2;
	Value left = divide_conquer(arr, l, mid);
	Value right = divide_conquer(arr, mid+ 1, r);

	return combine (left,right);

}

void solve()
{

	int n; cin >> n; // the number of rounds
	map<int, vector<int>> m;
	vector<int> arr;
	for (int i = 0; i < n;i++)
	{
		int x; cin >> x;
		arr.push_back(x);
		m[x].push_back(i);
	}

	Value res = neutral_element;
	int dice = 0;
	for (auto element : m)
	{
		vector<int> queryArray;
		vector<int> idxes;
		for (int i = 0; i < element.second.size(); i++)
		{
			int idx = element.second[i];
			if (i == 0)
			{
				queryArray.push_back(1);
				idxes.push_back(element.second[i]);
				continue;
			}

			queryArray.push_back(-(element.second[i] - element.second[i-1] - 1));
			queryArray.push_back(1);
			idxes.push_back(-1);
			idxes.push_back(element.second[i]);
		}
		Value currRes = divide_conquer(queryArray, 0, queryArray.size()-1);
		if (currRes.max > res.max)
		{
			res = currRes;
			dice = element.first;

			int realL=idxes[res.maxL];
			int realR =idxes[res.maxR];

			res.maxL = realL;
			res.maxR = realR;
		}
	}

	cout << dice << ' ' << res.maxL + 1 << ' ' << res.maxR +1<< '\n';



}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i<t; i++)
	{
		solve();
	}
}