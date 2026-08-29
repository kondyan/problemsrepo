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
#define usi              unordered_set<int>
#define vusi						 vector<unordered_set<int>>
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
using pipii = pair<int, pair<int,int>>;
using vpipii = vector<pipii>;
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
 
int sccCount = 0;
void dfs(vvi&adj,vi&vis,int v,vi&lowlink,vi &ids, vi&stack,int &c)
{
	ids[v] = lowlink[v] = c++;
	stack.pb(v);
	vis[v] =1;
	for (auto u : adj[v])
	{
		if (ids[u] == -1) dfs(adj,vis,u,lowlink,ids,stack,c);
		if (vis[u]) setmin(lowlink[v],lowlink[u]);
	};
	if (ids[v] == lowlink[v])
	{
		for (auto node = stack.back();; node = stack.back())
		{
			stack.pop_back();
			vis[node]=0;
			lowlink[node] = ids[v];
			if (node == v) break;
		}
		sccCount++;
	}
}
 
void reg_dfs(vvi &adj, vi &vis, int v)
{
	if (vis[v])return;
	vis[v]=1;
	for (auto u:adj[v])
	{
		reg_dfs(adj,vis,u);
	}
}
 
void solve(int T)
{
	int n,m; cin >> n >>m ;
	vvi adj(n,vi());
	vusi adjus(n,usi());
	vi stack;
	vi ids(n,-1);
	fr(i,0,m)
	{
		int a, b; cin >> a >> b; a--;b--;
		adj[a].pb(b);
		adjus[a].insert(b);
	}
 
	vi vis(n,0);
	vi lowlink(n,-1);
	int c = 0;
	// first ids the low link values
	fr(i,0,n)
	{
		if (ids[i] != -1)continue;
		dfs(adj,vis,i,lowlink,ids,stack,c);
	}
 
	if (sccCount == 1)
	{
		cout << "YES" << '\n';
		return ;
	}
	cout << "NO" << '\n';
 
	vi ans;
	fr(i,0,n)
	{
		if (lowlink[i] == ids[i]) ans.pb(i);
		if (ans.size() == 2) break;
	}
 
	vis = vi(n,0);
	reg_dfs(adj,vis,ans[0]);
	if (vis[ans[1]])
	{
		cout << ans[1] + 1 << ' ' << ans[0] + 1 << '\n';
	} else
	{
		cout <<ans[0] + 1 << ' ' << ans[1] + 1 << '\n';
	}
 
 
 
 
}
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	solve(0);
}