#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fr(a,b,c)        for(int a=b;a<c;a++)
#define rfr(a,b,c)       for(int a=b;a>c;a--)
#define nl               ("\n")
#define int              long long
#define double           long double
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define vb               vector<bool>
#define vs               vector<string>
#define vc							 vector<char>
#define vvc							 vector<vector<char>>
#define deqi						 deque<int>
#define pb(n)            push_back(n)
#define pbp(a,b)				 push_back({a,b})
#define pf(n)						 push_front(n)
#define pfp(n)					 push_front({a,b})
#define eb(n)            emplace_back(n)
#define mp(a,b)          make_pair(a,b)
#define bitcntll(n)      __builtin_popcountll(n)
#define ff               first
#define ss               second
#define sz(s)            (long long)(s.size())
#define all(v)           (v).begin(),(v).end()
#define sp(n)            cout<<setprecision(n)<<fixed;
#define in(v)            for(auto &item : v) cin>>item;
#define inp(v)           for(auto &item : v) cin>>item.ff>>item.ss;
#define google(T)        cout<< "Case #" << T << ": ";

void setmin(auto &x, auto y) {if (y < x) x = y;}
void setmax(auto &x, auto y) {if (y > x) x = y;}

using pii = pair<int,int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// *find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define db(x)            cerr << #x <<" "; _print(x); cerr << nl;
#define gt(T)            cerr << "Case #" << T << ": " << nl;
#else
#define db(x)
#define gt(T)
#endif

void _print(int t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(bool t) {cerr << ((t)?"true":"false");}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
int modadd(int a,int b,int m){ a %= m;b %= m; return (a + b) % m;}
int modmul(int a,int b,int m){ a %= m;b %= m; return (a * b) % m;}
int modsub(int a,int b,int m){ a %= m;b %= m; return (a - b + m) % m;}
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}
int expo(int a,int n,int md){ int res=1; while(n){ if(n&1) {res = modmul(res,a,md);--n;} else {a = modmul(a,a,md);n >>= 1;}} return res;}
int expo(int a,int n){ int res=1; while(n){ if(n&1) {res *= a;--n;} else {a *= a;n >>= 1;}} return res;}
template <typename T> bool revsort(T a, T b){return a > b;}
vb sieve(int n){vb prime(n+1,1); prime[0] = prime[1] = 0; for(int i=2;i*i<=n;i++){if(prime[i]){for(int j=i*i;j<=n;j+=i) prime[j]=0;}} return prime;}
vs rmspace(string s){ vs toreturn; string tmp = ""; for(auto i : s){ if(i == ' '){ toreturn.pb(tmp); tmp = "";} else tmp += i;} toreturn.pb(tmp); return toreturn;}
/*---------------------------------------------------------------------------------------------------------------------------*/

/*

1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph

*/

int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };

//         { U  , D ,  L  , R , UL  , UR  , DL  , DR }

const double PI = 3.1415926535;
const int inf = 1e18;
const int mod = 1000000007;

auto sum = [](int a, int b) {return (a + b) % mod;};
auto min_fn = [](int a, int b) {return min(a,b);};
auto max_fn = [](int a, int b) {return max(a,b);};


struct Operation
{

	int mul,add, length;
	char m;
	string op;

	int apply(int val)
	{
		if (op == "+") return mul*(val) + (add*length);
		return mul*val + add;
	}
	bool is_identity()
	{
		return length == -1 && mul == 0 && add == 0;
	}
};

struct ST
{
	int n;
	vi tree, a;
	string op;
	int (*func)(int a, int b);






	int left(int x) {return 2 * x + 1;};
	int right(int x ) {return 2 * x + 2;};
	int mid(int l, int r) {return l + (r-l) /2;};



	int genFunc(int a, int b)
	{
		if (a == -1) return b;
		if (b == -1) return a;

		return func(a,b);
	}

	ST(vi &a, int n, string op, int (*func)(int,int)) :n(n), a(a),op(op), func(func)
	{

		tree.resize(4*n);
		lazy.resize(4 * n, identity);
		build(0,0,n);
	}


	Operation identity = {0,0,-1,'.',op};
	vector<Operation> lazy;





	int build(int Node, int l, int r)
	{
		if (l + 1 == r)
		{
			return tree[Node] = a[l];
		}

		int leftNode = left(Node);
		int rightNode = right(Node);
		int m = mid(l,r);

		return tree[Node] = genFunc(build(leftNode,l,m), build(rightNode,m,r));

	}

	int query_range(int Node, int l, int r, int ql, int qr)
	{
		if (r <= ql || qr <= l)
		{
			return -1;
		}
		if (ql <= l && r <= qr)
		{
			return tree[Node];
		}
		propagate(l,r,Node, lazy[Node]);

		int leftNode =left(Node);
		int rightNode =right(Node);
		int m = mid(l,r);

		return genFunc(query_range(leftNode,l,m,ql,qr), query_range(rightNode,m,r,ql,qr));
	}

	int update_range(int Node, int l, int r, int ul, int ur, Operation &operation)
	{

		if (r <= ul || ur <= l)
		{
			return tree[Node];
		}
		if (l + 1 == r)
		{
			operation.length = r-l;
			return tree[Node] = a[l] = operation.apply(tree[Node]);
		}

		if (ul <= l && r <= ur)
		{
			propagate(l,r,Node, lazy[Node]);
			lazy[Node] = operation;
			lazy[Node].length = r - l;
			tree[Node] = lazy[Node].apply(tree[Node]);
			return tree[Node];
		}

		propagate(l,r,Node, lazy[Node]);


		int leftNode = left(Node);
		int rightNode = right(Node);
		int m = mid(l,r);

		return tree[Node] = genFunc(update_range(leftNode,l,m,ul,ur,operation), update_range(rightNode,m,r,ul,ur,operation));
	}

	int update_children(int l, int r, int Node, int ul, int ur, Operation &operation)
	{
		int m = mid(l,r);
		int leftNode = left(Node);
		int rightNode = right(Node);

		return tree[Node] = genFunc(update_range(leftNode,l,m,ul,ur,operation), update_range(rightNode,m,r,ul,ur,operation));
	}

	void propagate(int l, int r, int Node, Operation &operation)
	{
		if (!lazy[Node].is_identity())
		{
			update_children(l,r,Node,l,r, operation);
			lazy[Node] = identity;
		}
	}

	int update_set(int Node, int l, int r, int k, int v)
	{
		if (k < l || r <= k)
		{
			return -1;
		}
		if (l + 1 == r)
		{
			tree[Node] = a[l] = v;
		}
		int leftNode = left(Node);
		int rightNode = right(Node);
		int m = mid(l,r);

		tree[Node] = genFunc(update_set(leftNode,l,m,k,v),update_set(rightNode,m,r,k,v));

	}
};

void solve(int T)
{


	string op, up; cin >> op >> up;
	int n; cin >> n;
	vi a(n); fr(i,0,n) {cin >> a[i];}

	int (*func)(int,int);
	if (op == "+")
	{
		func = sum;
	} else if (op == "min")
	{
		func = min_fn;
	} else
	{
		func = max_fn;
	}

	ST st(a,n,op,func);

	int q; cin >>q;
	fr(i,0,q)
	{
		char x; cin >> x;
		int ql, qr; cin >> ql >> qr;

		Operation operation;
		operation.op=op;

		switch (x)
		{
		case 'q':
			cout << st.query_range(0,0,n,ql,qr) << '\n';
			break;
		case 'a':
			int nv; cin >> nv;
			operation.mul=1;
			operation.add=nv;
			st.update_range(0,0,n,ql,qr,operation);
			break;
		case 's':
			nv; cin >> nv;
			operation.mul=0;
			operation.add=nv;
			st.update_range(0,0,n,ql,qr,operation);
			break;
		case 'm':
			nv; cin >> nv;
			operation.mul=nv;
			operation.add=0;
			st.update_range(0,0,n,ql,qr,operation);
			break;
		}
		// answer queries
	}
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve(0);
}