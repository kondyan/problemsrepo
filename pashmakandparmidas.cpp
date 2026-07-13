#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(x) x.begin() x.end();

struct SegTree
{
	vector<int> prefix;
	vector<int> suffix;
	vector<int> tree;

	int left(int node) {return 2 * node + 1;}
	int right(int node) {return 2 * node + 2;}
	int middle(int l, int r) {return l + (r-l) / 2;}


	int query_range(int node, int l, int r, int ql, int qr)
	{
		if (qr < l || r < ql) return 0;
		if (r <= qr && ql <= l) return tree[node];

		int mid = middle(l,r);
		int leftNode = query_range(left(node), l,mid, ql,qr);
		int rightNode = query_range(right(node), mid + 1, r,ql,qr);

		return leftNode+rightNode;
	}

	void update(int node,int l, int r, int idx)
	{
		if (idx < l || r < idx) return;
		if (l == r)
		{
			tree[node]++;
			return;
		}
		int mid = middle(l,r);
		update(left(node), l,mid,idx);
		update(right(node), mid + 1, r,idx);

		tree[node] = tree[left(node)] + tree[right(node)];
	}

	SegTree(int n, vector<int> &arr, vector<int> &prefix, vector<int>&suffix): suffix(suffix), prefix(prefix)
	{
		tree.resize(4*n);

	}


};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);



	int n; cin >> n;
	vector<int> arr;
	vector<int> prefix(n,0);
	vector<int> suffix(n,0);
	vector<int> count(n,0);

	for (int i = 0 ; i < n ; i ++)
	{
		int a; cin >> a;
		arr.push_back(a);
	}

	vector<int> arrCopy = arr;
	sort(arrCopy.begin(), arrCopy.end());
	auto it = unique(arrCopy.begin(), arrCopy.end());
	arrCopy.erase(it, arrCopy.end());


	for (int i = 0; i <n;i++)
	{
		auto idx = lower_bound(arrCopy.begin(),arrCopy.end(), arr[i]) - arrCopy.begin();
		count[idx]++;
		prefix[i] = count[idx];
	}

	count = vector<int>(n,0);
	for (int i = n-1; i >= 0; i--)
	{
		auto idx = lower_bound(arrCopy.begin(),arrCopy.end(), arr[i]) - arrCopy.begin();
		count[idx]++;
		suffix[i] = count[idx];
	}

	SegTree st(n,prefix,suffix,arr);

	int counter=0;
	for (int j = 0; j < n; j++)
	{
		int l = suffix[j];
		counter += st.query_range(0,0,n+1, l + 1, n+1);
		st.update(0,0,n+1,prefix[j]);
	}

	cout << counter << '\n';


}