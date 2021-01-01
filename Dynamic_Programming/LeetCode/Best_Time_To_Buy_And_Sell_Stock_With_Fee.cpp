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

int dp[50005][2];
int sz;

int helper(vector<int> &arr, int n, int fee, int flag)
{

    if (n == 0)
        return 0;
    if (dp[n][flag] = -1)
        return dp[n][flag];

    if (flag)
        dp[n][flag] = max(helper(arr, n - 1, fee, flag), helper(arr, n - 1, fee, flag ^ 1) + arr[sz - n] - fee);

    else
        dp[n][flag] = max(helper(arr, n - 1, fee, flag), helper(arr, n - 1, fee, flag ^ 1) - arr[sz - n]);

    return dp[n][flag];
}

void solve()
{
    int n, fee;
    cin >> n >> fee;
    vector<int> arr;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.pb(temp);
    }

    if (n < 2)
    {
        cout << 0 << endl;
        return;
    }
    sz = n;

    cout << helper(arr, n, fee, 0) << endl;
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
