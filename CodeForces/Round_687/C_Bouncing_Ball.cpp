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
#define pii pair<int, int>
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

int fast_expo(ll a, ll b, ll p)
{

    if (a == 0)
        return 0;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a, ans %= p;
        a *= a, a %= p;
        b /= 2;
    }
    return ans;
}

ll inv(ll a, ll p)
{
    return fast_expo(a, p - 2, p);
}

/* ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k],p)%p) * inv(fact[n-k],p)) % p;
} */

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

int n, p, k;
string str; // n platforms
int x, y;

void solve()
{
    cin >> n >> p >> k >> str;
    cin >> x >> y;

    str = " " + str;

    // LOGIC
    // get all possible values of p
    // need to optimize inner loop

    vector<ll> cnt(n + 1);
    if (str[n] == '0')
        cnt[n] = 1; // need to add 1 platform
    else
        cnt[n] = 0;

    for (int i = n - 1; i >= p; i--)
    {

        if (i + k > n)
            cnt[i] = (str[i] == '1') ? 0 : 1;
        else
        {
            if (str[i] == '1')
                cnt[i] = cnt[i + k];
            else
                cnt[i] = cnt[i + k] + 1;
        }
    }

    ll ans = inf;
    for (ll i = p; i <= n; i++)
    { // 1st index is (p-1)
        // also cost for this move is (i-p)*y
        ll temp = (i - p) * y + (cnt[i] * x);

        if (temp < ans)
            ans = temp;
    }

    cout << ans << endl;
    //0 1 0 1 0 1 0 1 0 1
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
