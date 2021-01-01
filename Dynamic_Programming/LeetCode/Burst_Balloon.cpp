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
int n;
int dp[500][500];

int max_profit(vector<int> &coins, int start, int end)
{

    if (start > end)
        return 0;

    if (dp[start][end])
        return dp[start][end];
    int left = 1, right = 1;
    if (start - 1 >= 0)
        left = coins[start - 1];
    if (right + 1 < n)
        right = coins[right + 1];

    int res = 0;
    for (int i = start; i <= end; i++)
    { // choosing the last balloon to burst
        res = max(
            res, max_profit(coins, start, i - 1) + max_profit(coins, i + 1, end) + coins[i] * left * right;)
    }
    return dp[start][end] = res;
}

void solve()
{

    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // now we know that coins earned by bursting ith balloon == coins[i] * coins[i-1] *coins[i+1]
    // we need to choose our last balloon such that we get max profit
    // need to partition the array in sucha way
    cout << max_profit(coins, 0, n - 1);
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
