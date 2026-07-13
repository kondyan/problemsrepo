#include <bits/stdc++.h>
using namespace std;
#define int long long


struct SegTree
{
	vector<int> treeSum;
	vector<int> treeMax;
	int left(int Node) {return 2 * Node + 1;}
	int right(int Node) {return 2 * Node + 2;}
	int mid(int l, int r) {return l + (r-l) / 2;}

	void buildMax(int Node, int l, int r, vector<int>&a)
	{
		if (l == r)
		{
			treeMax[Node] = a[l];
			return;
		}

		int m = mid(l,r);
		buildMax(left(Node), l, m, a);
		buildMax(right(Node), m + 1, r, a);


		treeMax[Node] = max(treeMax[left(Node)], treeMax[right(Node)]);
	}

	void buildSum(int Node, int l, int r,vector<int>&a)
	{
		if (l == r)
		{
			treeSum[Node] = a[l];
			return;
		}

		int m = mid(l,r);
		buildSum(left(Node), l, m,a);
		buildSum(right(Node), m + 1, r,a);


		treeSum[Node] = treeSum[left(Node)] + treeSum[right(Node)];
	}

	int queryMax(int Node, int l, int r, int ql, int qr)
	{
		if (r < ql || l > qr)
		{
			return 0;
		}
		if (l >= ql && r <= qr)
		{
			return treeMax[Node];
		}


		int m = mid(l,r);

		int leftNode = queryMax(left(Node),l, m, ql, qr);
		int rightNode = queryMax(right(Node), m+1,r, ql,qr);

		return max(leftNode,rightNode);
	}



	int querySum(int Node, int l, int r, int ql, int qr)
	{
		if (r < ql || l > qr)
		{
			return 0;
		}

		if (l >= ql && r <= qr)
		{
			return treeSum[Node];
		}


		int m = mid(l,r);

		int leftNode = querySum(left(Node),l, m, ql, qr);
		int rightNode = querySum(right(Node), m+1,r, ql,qr);

		return leftNode + rightNode;
	}

	SegTree(vector<int> &arr, int n)
	{
		treeMax.resize(4*n);
		treeSum.resize(4*n);
		buildMax(0, 0, n-1,arr);
		buildSum(0, 0, n-1,arr);
	}
};

void solve()
{
	int n;cin>>n;

	vector<int> arr(n);
	vector<int> positive;
	for (int i =0 ; i <n ;i++)
	{
		cin >> arr[i];
		if (arr[i] >= 0) positive.push_back(i);
	}

	SegTree st(arr, n);

	for (int i = 0 ; i < positive.size(); i++)
	{
		int ql = positive[i];
		for (int j = i + 1; j <= positive.size(); j++)
		{
			int qr = positive[j];
			if (st.queryMax(0,0,n-1, ql,qr) < st.querySum(0,0,n-1,ql,qr))
			{
				cout << "NO" << '\n';
				return;
			};
		}
	}

	cout << "YES" << '\n';
	return;

	//


}

signed main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		solve();
	}
}