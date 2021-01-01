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

int n, k; // n floors and k eggs
int dp[105][10005];

void solve()
{
    cin >> k >> n;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    }

    for (int i = 0; i <= k; i++)
    {
        dp[i][0] = 0; // 0 floor
        dp[i][1] = 1; // 1 floor
    }

    for (int i = 0; i <= n; i++)
        dp[0][i] = 0, dp[1][i] = i; // only 1 egg available

    for (int i = 2; i <= k; i++)
    { // eggs
        for (int j = 2; j <= n; j++)
        { // floors
            int lo = 1, hi = j, temp = 0, res = 1e5;
            while (lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                int left = dp[i - 1][mid - 1];
                int right = dp[i][j - mid];

                temp = 1 + max(left, right);
                if (left < right)
                    lo = mid + 1;
                else
                    hi = mid - 1;
                res = min(res, temp);
            }
            dp[i][j] = res;
        }
    }
    cout << dp[k][n] << endl;
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
