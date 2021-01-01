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

string str;
int dp[101][101];

int mcm(string str, int start, int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;

    if (dp[start][end] != -1)
        return dp[start][end];

    int res = INT_MAX;
    if (str[start] == str[start + 1])
        res = mcm(str, start + 1, end);
    else if (str[start] == str[end] || str[end] == str[end - 1])
        res = mcm(str, start, end - 1);

    else
    {
        res = mcm(str, start, end - 1) + 1; // treat last char as different
        for (int k = start + 1; k < end; k++)
        {
            if (str[k] == str[end])
            {
                res = min(res, mcm(str, start, k - 1) + mcm(str, k, end - 1));
            }
        }
    }
    return dp[start][end] = res;
}

void solve()
{
    cin >> str;
    memset(dp, -1, sizeof dp);
    int n = str.length();
    int res = mcm(str, 0, n - 1);
    //LOGIC
    // possible options ->
    //if : str[start] == str[start+1] -> dp[start+1][end] // answer would depend on res of 2nd char
    // if : str[end] == str[end-1] || str[start] == str[end] -> dp[start][end-1] // no need to print last char
    // else : 1 option would be to TREAT last character as unique hence dp[start][end-1] + 1
    // next would to partition the array such that str[k] == str[end]
    cout << res << endl;
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
