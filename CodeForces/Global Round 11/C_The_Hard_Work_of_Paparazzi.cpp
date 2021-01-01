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

int r, n;
vector<int> x(MAX);
vector<int> y(MAX);
vector<int> t(MAX);
vector<int> dp(MAX);
vector<int> max_dp(MAX);

void flush()
{
    dp.clear();
    max_dp.clear();
}

void solve()
{
    cin >> r >> n;
    x[0] = 1, y[0] = 1;

    flush();

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1e9;
        for (int j = max(0, i - (2 * r)); j < i; j++)
        {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        if (i > 2 * r)
            dp[i] = max(dp[i], 1 + max_dp[i - 2 * r]);
        max_dp[i] = max(dp[i], max_dp[i - 1]);
    }

    cout << max_dp[n] << endl;
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
