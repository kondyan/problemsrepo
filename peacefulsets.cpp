#include <bits/stdc++.h>


using namespace std;

#define fr(a,b,c)        for(int a=b;a<c;a++)
#define rfr(a,b,c)       for(int a=b;a>c;a--)
#define nl               ("\n")
#define int              long long
#define double           long double
#define vi               vector<int>
#define vb               vector<bool>
#define vs               vector<string>
#define pb(n)            push_back(n)
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

int ans = 0;
int left_lim;
int right_lim;

void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int curr_left, int curr_right,int x, int y, int n, int m)
{
	if (x < 0 || y < 0|| x >= n || y >= m) return;
	if (grid[x][y] == '*') return;
	if (visited[x][y]) return;
	visited[x][y] = 1;
	ans++;

	if (curr_right < right_lim)
	{
		dfs(grid,visited,curr_left, curr_right+1,x, y+1,n,m);
	}

	if (curr_left<left_lim)
	{
		dfs(grid,visited,curr_left+1,curr_right,x,y-1,n,m);
	}
	dfs(grid,visited,curr_left,curr_right,x+1,y,n,m);
	dfs(grid,visited,curr_left,curr_right,x-1,y,n,m);

}


void solve()
{

	int n,m; cin >> n >> m;

	int r, c; cin >> r >> c; r--; c--;
	int x,y; cin >> x >> y;
	left_lim = x;
	right_lim = y;

	vector<vector<char>> grid(n,vector<char>(m));
	vector<vector<int>> visited(n,vector<int>(m,0));
	fr(i,0,n)
	{
		fr(j,0,m) {cin >> grid[i][j];}
	}

	dfs(grid,visited,0,0,r,c,n,m);

	cout << ans << '\n';
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

		solve();

    return 0;
}