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

int n, m;
string s, t;
int dp[5005][5005];

void solve()
{
    cin >> m >> n;
    cin >> s >> t;
    // make LCS table
    memset(dp, 0, sizeof dp);
    // create LCS
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max(dp[i - 1][j - 1] + 2, dp[i][j]);

            if(dp[i][j] < 0) dp[i][j] = 0;    
        }
    }

    // formula is 4*LCS - m - n
    ll ans = INT_MIN;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
}

int main()
{
    fast_io int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}
