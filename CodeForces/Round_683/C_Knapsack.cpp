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
#define MAX 200005
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

ll n, wt;

void solve()
{
    cin >> n >> wt;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll lo = (wt + 1) / 2;
    ll hi = wt;

    // check for any element <=lo
    int found = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= lo && arr[i] <= hi)
        {
            found = i + 1;
            break;
        }
    }
    if (found != -1)
    { // if found
        cout << 1 << endl
             << found << endl;
        return;
    }

    ll currsum = 0;
    vector<ll> ind;

    for (int i = 0; i < n; i++)
    {
        if (currsum >= lo)
            break;
        if (arr[i] < hi)
        {
            currsum += arr[i];
            ind.pb(i + 1);
        }
    }

    if (currsum < lo || currsum > hi)
        cout << -1 << endl;
    else
    {
        cout << ind.size() << endl;
        for (int i = 0; i < ind.size(); i++)
            cout << ind[i] << " ";
        cout << endl;
    }
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
