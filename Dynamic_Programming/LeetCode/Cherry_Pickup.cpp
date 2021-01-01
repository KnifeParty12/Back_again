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

int n;
int dp[50][50][50];

int cherrypick(vector<vector<int>> &arr, int r1, int c1, int c2)
{

    int r2 = r1 + c1 - c2;
    if (r1 == n - 1 && c1 == n - 1)
        return arr[r1][c1]; // reached end point
    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || arr[r1][c1] == -1 || arr[r2][c2] == -1)
        return INT_MIN;

    if (dp[r1][c1][c2] != -1)
        return dp[r1][c1][c2];

    int res = arr[r1][c1];
    if (c1 != c2)
        res += arr[r2][c2]; // people are on different coordinates

    res += max({cherrypick(arr, r1, c1 + 1, c2), cherrypick(arr, r1, c1 + 1, c2 + 1),
                cherrypick(arr, r1 + 1, c1, c2), cherrypick(arr, r1 + 1, c1, c2 + 1)});

    dp[r1][c1][c2] = res;
    return dp[r1][c1][c2];
}

void solve()
{
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    // LOGIC
    // what we think of is finding 2 different paths from (0,0) to (n-1,n-1)
    // say person p1 has covered t steps then r1 + c1 = t = r2 + c2
    // hence dp[r1][c1][c2] is our dp states, we dont need r2 coz r2 = r1 + c1 - c2, hence can be calculated
    memset(dp, -1, sizeof dp);
    cout << cherrypick(arr, 0, 0, 0) << endl;
}

int main()
{
    fast_io int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}
