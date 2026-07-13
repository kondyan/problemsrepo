#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct SegTree
{

	vector<int> a;
	vector<int> tree;
	int n;

	int left(int node) {return 2 * node + 1;}
	int right(int node) {return 2 * node + 2;}
	int mid (int l, int r ) {return l + (r-l)/ 2;}


	void build(int node, int start, int end)
	{
		if (start == end)
		{
			tree[node] = a[start];
			return;
		}
		int m = mid(start,end);

		build(left(node),start, m);
		build(right(node), m + 1, end);

		tree[node] = max(tree[left(node)], tree[right(node)]);
	}

	void update(int node, int start, int end, int idx, int val)
	{
		if (start > idx || end < idx) return;
		if (start == idx && end == idx)
		{
			tree[node] = val;
			a[idx] = val;
			return;
		}


		int m = mid(start,end);

		update(left(node),start, m,idx,val);
		update(right(node), m + 1, end,idx,val);

		tree[node] = max(tree[left(node)], tree[right(node)]);
	}


	int query_range(int node, int start, int end, int ql, int qr)
	{
		if (end < ql || start > qr) return 0;
		if (ql <= start && end <= qr) return tree[node];
		int m = mid(start,end);

		int leftNode = query_range(left(node),start, m,ql,qr);
		int rightNode = query_range(right(node), m + 1, end,ql,qr);

		return max(leftNode, rightNode);
	}

	SegTree(int n, vector<int> &arr): n(n), a(arr)
	{
		tree.resize(4*n);
		build(0,0,n-1);

	}
};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q; cin >> n >> q;
	vector<int> arr;
	for (int i = 0; i < n;i++)
	{
		int x; cin >> x;
		arr.push_back(x);
	}

	SegTree st(n, arr);

	for (int i = 0 ; i< q; i++)
	{
		string mode; cin >> mode;
		if (mode == "max")
		{
			int l, r; cin >> l >> r;
			cout << st.query_range(0,0,n-1,l,r) <<'\n';
		} else
		{
			int idx, val; cin >> idx >> val;
			st.update(0,0,n-1,idx,val);
		}
	}
}