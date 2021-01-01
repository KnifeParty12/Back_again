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

int n; // n persons and n tasks
int dp[21][1 << 21];
int DPbitmasking(vector<vector<int>> &cost, int i, int mask)
{ // i represents the job we are assigning job to

    if (i == n)
        return 0; // assgined jobs to all person

    if (dp[i][mask] != -1)
        return dp[i][mask];

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {                        // j represents the person job is being assigned to
        if (mask & (1 << j)) // jth bit is set
            ans = min(ans, cost[j][i] + DPbitmasking(cost, i + 1, mask ^ (1 << j)));
    }
    return dp[i][mask] = ans;
}

void solve()
{
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }
    memset(dp, -1, sizeof dp);
    cout << DPbitmasking(cost, 0, (1 << n) - 1); // answer lies in 1111111111111...uptil N
}

/*
set ith bit mask|(1<<j)
unset ith bit mask & !(1<<j)
check if ith bit set or not mask & (1<<j)

*/

int main()
{
    fast_io int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}
