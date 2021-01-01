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

void solve()
{
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    int lo = 1;
    int hi = n - 1;
    int ans;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if ((mid * (mid + 1)) / 2 <= n)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    // now we got "ans" number of people who we can give candy too except the left overs
    // which we can give to last guy so that we won't get anything same
    int sum = (ans * (ans + 1)) / 2;
    int leftover = n - sum;
    cout << ans << endl;

    for (int i = 1; i <= ans; i++)
    {
        if (i == ans)
            cout << (i + leftover);
        else
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
