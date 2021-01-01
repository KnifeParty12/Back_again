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

int n, k;
vector<int> adj[16]; // max n is 15
int dp[1 << 16];

vector<int> get_indeg(int mask)
{

    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)))
        {
            for (auto it : adj[i])
                indeg[it]++;
        }
    }
    return indeg;
}

int get_courses_with_indeg_0(int mask, vector<int> &indeg)
{

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)) && indeg[i] == 0)
            x |= (1 << i);
    }
    return x;
}

int getbits(int mask)
{

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            cnt++;
    }
    return cnt;
}

int solver(int mask)
{

    if (mask == (1 << n) - 1)
        ; // all courses alloted

    if (dp[mask] != -1)
        return dp[mask];

    vector<int> indeg = get_indeg(mask);
    int submask = get_courses_with_indeg_0(mask, indeg);
    int cnt = getbits(submask);
    if (cnt <= k)
        dp[mask] = 1 + solver(mask | submask);

    else
    {
        int res = INT_MAX;
        for (int i = submask; i > 0; i = submask & (i - 1))
        { // to set rightmost set bit off
            if (getbits(i) == k)
                res = min(1 + solver(mask | i), res);
        }
        dp[mask] = res;
    }
    return dp[mask];
}

void solve()
{
    int e;
    cin >> n >> e; // number of courses indexed 1 and  edges
    vector<vector<int>> dependencies;
    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        dependencies.pb({f, s});
    }
    cin >> k; // maximum permittable courses in 1 sem
    for (int i = 0; i < e; i++)
    {
        f = dependencies[i][0] - 1;
        s = dependencies[i][1] - 1;
        adj[f].pb(s);
    }
    // steps
    // create adjacency list
    // now we create a mask of length n where ith bit represents that particular course
    // if ith bit is set then we have already done that course
    // now for a particular mask we gotta find unset courses with indeg == 0
    // count such courses if > k  then need to choose from that particular submask otherwise gucci

    memset(dp, -1, sizeof dp);

    cout << solver(0); // mask
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
