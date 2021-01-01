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
int dp[1 << 17];
int like[17][17];

int set_bits(int mask)
{

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            cnt++;
    }
    return cnt;
}

int helper(int mask)
{

    if (mask == (1 << n) - 1)
        return 1; // only 1 way possible

    if (dp[mask] != -1)
        return dp[mask];

    int cnt = set_bits(mask); // assigning to cnt person now

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (like[cnt][i] != 0 && !(mask & (1 << i)))
            res += helper(mask | (1 << i));
    }
    dp[mask] = res;
    return dp[mask];
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    { // candy
        for (int j = 0; j < n; j++)
            cin >> like[i][j];
    }
    memset(dp, -1, sizeof dp);
    // what does a mask represents
    // it represents candies

    cout << helper(0) << endl;
}

int main()
{
    fast_io int tc = 1;
    //   cin >> tc;
    while (tc--)
        solve();
    return 0;
}
