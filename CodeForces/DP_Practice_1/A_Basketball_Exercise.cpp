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
#define MAX 100005
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

int n;
ll dp[MAX][3];
ll r1[MAX];
ll r2[MAX];

ll go(int start, int flag)
{

    if (start == n)
        return 0; // empty arrays

    if (dp[start][flag] != -1)
        return dp[start][flag];

    if (flag == 0)
    { // initial point
        ll sm1 = r1[start] + go(start + 1, 2);
        ll sm2 = r2[start] + go(start + 1, 1);
        ll sm3 = go(start + 1, 0);
        dp[flag][start] = max(sm1, max(sm2, sm3));
    }

    else if (flag == 1)
        dp[start][flag] = max(r1[start] + go(start + 1, 2), go(start + 1, 1));

    else
        dp[start][flag] = max(r2[start] + go(start + 1, 1), go(start + 1, 2));

    return dp[start][flag];
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r1[i];
    for (int i = 0; i < n; i++)
        cin >> r2[i];

    memset(dp, -1, sizeof dp);

    cout << go(0, 0);
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
