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
int m, n, sx, sy, N;

ll dp[51][51][51];
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int helper(int m, int n, int x, int y, int k)
{

    if (x < 0 || x == m || y < 0 || y == n)
        return 1;
    if (k == 0)
        return 0;

    if (dp[x][y][k] != -1)
        return dp[x][y][k];

    ll temp = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        temp += helper(m, n, nx, ny, k - 1);
        if (temp >= mod)
            temp -= mod;
    }
    dp[x][y][k] = temp;
    return dp[x][y][k];
}

void solve()
{
    cin >> m >> n >> sx >> sy >> N;
    memset(dp, -1, sizeof dp);
    cout << helper(m, n, sx, sy, N) << endl;
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
