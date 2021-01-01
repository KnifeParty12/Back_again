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
            ans *= a, ans %= mod;
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

int n, k;
int dp[31][31];
int prefix[31];
int merge_stones(vector<int> &stones, int start, int end)
{

    // BASE CASE
    int len = end + 1 - start;
    if (len < k) // not worth partitioning
        return 0;

    if (dp[start][end] != -1) // already calculated
        return dp[start][end];

    // now we partition right ?
    int res = 1e6;
    for (int i = start; i < end; i += (k - 1)) // need to make k-1 size gaps so that we make useful calls only
    {
        res = min(res, merge_stones(stones, start, i) + merge_stones(stones, i + 1, end));
    }
    if ((len - k) % (k - 1) == 0)
    { // can be combined or not
        res += prefix[end];
        if (start)
            res -= prefix[start - 1];
    }

    return dp[start][end] = res;
}

void solve()
{
    cin >> n >> k;
    vector<int> stones(n);
    for (int i = 0; i < n; i++)
        cin >> stones[i];
    prefix[0] = stones[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + stones[i];
    // BASE CASE
    if ((n - k) % (k - 1) != 0)
    {
        cout << -1;
        return;
    }
    memset(dp, -1, sizeof dp);
    cout << merge_stones(stones, 0, n - 1);
}

/*
4 2
3 2 4 1
*/

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
