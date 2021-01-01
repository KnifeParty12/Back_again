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
#define MAX 1005
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

void solve()
{
    int n, x, pos;
    cin >> n >> x >> pos;
    ll ans = 1;
    int left = x - 1;
    int right = n - x;
    int lo = 0;
    int hi = n;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;
        if (pos >= mid)
        {
            if (pos != mid)
                ans *= left, left--;
            lo = mid + 1;
        }
        else
            hi = mid, ans *= right, right--;
        ans %= mod;
    }

    for (int i = 1; i <= left + right; i++)
        ans *= i, ans %= mod;

    cout << ans;
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
