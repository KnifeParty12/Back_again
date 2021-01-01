#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define loop(i, a, b) for (int i = a; i < b; i++)
#define sloop(str, i, a) for (int i = a; str[i] != '\0'; i++)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int, int>
#define MAX 1000005
#define inf 1000000000000000LL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
using namespace std;

//auto inside = [&](){
//cout<<"nigga";
//};
//inside();

template <typename T>
string to__string(T x)
{
    ostringstream ss;
    ss << x;
    return ss.str();
}

int fast_expo(ll a, ll b)
{

    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a, ans -= mod;
        a *= a, a %= mod;
        b /= 2;
    }
    return ans;
}

ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a >= b)
        return b;
    return a;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*--------GLOBAL BOIS--------------- */

int n, e; // no. of vertices
vector<int> adj[MAX];
vector<vector<int>> res;

void dfs(int sv, int ev, vector<int> temp)
{
    if (sv == ev)
    {
        temp.pb(sv);
        res.pb(temp);
        return;
    }

    for (auto it : adj[sv])
    {
        temp.pb(sv);
        dfs(it, ev, temp);
        temp.pop_back(); // BACKTRACK
    }
}

void solve()
{
    cin >> n >> e;
    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        adj[f].pb(s);
    }
    int sv = 0;     // starting
    int ev = n - 1; // ending

    vector<int> temp;
    dfs(sv, ev, temp);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    fast_io int tc = 1;
    //  cin >> tc;
    while (tc--)
        solve();
    return 0;
}
