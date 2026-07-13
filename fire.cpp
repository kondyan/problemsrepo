#include <bits/stdc++.h>
//
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

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

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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

struct UF
{
    vector<int> c, size;
    int find(int x) {return x == c[x] ? x : c[x] = find(c[x]);}
    void unite(int a, int b)
    {
        int parentA = find(a);
        int parentB = find(b);

        if (parentA == parentB) return;

        if (size[parentA] > size[parentB]) { swap(parentA,parentB);}
        c[parentA] = parentB;

    }
    UF (int m) : c(m), size(m, 1) {iota(c.begin(),c.end(), 0);}
};

void solve(int T)
{
    // freopen("fire-sub3-upsolve-attempt3.txt", "r", stdin);
    // freopen("fire.txt", "w", stdout);
    int n, m; cin >> n >> m;

    vector<pair<int,pair<int,int>>> fires(m);

    pii left_most ={inf,inf}, right_most = {-inf,-inf}, highest = {inf,inf}, lowest = {-inf,inf};
    fr(i,0,m)
    {
        int x, y; cin >> x >> y;
        fires[i] = {i, {x,y}};
        if (left_most.second > y) left_most = {x,y};
        if (right_most.second < y) right_most = {x,y};
        if (highest.first > x) highest = {x,y};
        if (lowest.first < x) lowest = {x,y};
    }

    int first_line = min(highest.first, n - 1 - right_most.second) - 1;
        int second_line = min(n-1-lowest.first, left_most.second) - 1;
    vector<pair<int,pair<int,int>>> edges;

    for (auto [i,fire] : fires)
    {
        int x = fire.first;
        int y = fire.second;
        for (auto [j,other_fire] : fires)
        {
            if (j == i) continue;
            int other_x = other_fire.first;
            int other_y = other_fire.second;

            int dist = abs(x- other_x) + abs(y-other_y);


            edges.push_back({dist,{i,j}});
        }
    }

    UF uf(m);
    sort(edges.begin(),edges.end());


    int maxDist = -inf;
    for (auto edge : edges)
    {
        int dist = edge.first;
        int x = edge.second.first;
        int y = edge.second.second;

        if (uf.find(x) == uf.find(y)) continue;
        setmax(maxDist, dist);
        uf.unite(x,y);
    }

    int middle = floor((maxDist-1)/2);
    if (middle == 1) middle = 0;

    int ans = max({middle - 1, first_line, second_line});

    cout << "Case #" << T << ": " << ans << '\n';
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve(i);

    }

    return 0;
}