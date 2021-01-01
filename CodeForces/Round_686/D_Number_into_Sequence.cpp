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

ll n;

void solve()
{
    cin >> n;
    // something to do with divisors

    vector<ll> fact;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fact.pb(i);
            fact.pb(n / i);
        }
    }

    if (fact.size() == 0)
    { // i.e prime
        cout << 1 << endl
             << n << endl;
        return;
    }

    // we got pairs of divisors to check

    vector<ll> res;
    ll t1 = fact[0];
    ll t2 = fact[1];

    // LOGIC need to check for every pair of factors
    int mx = 0;
    for (int i = 0; i < fact.size(); i += 2)
    {
        ll t1 = fact[i];
        ll t2 = fact[i + 1];
        vector<ll> temp;

        if (t2 % t1 != 0)
            continue;

        if (t1 == t2)
        {
            temp.pb(t1);
            temp.pb(t1);
        }

        // are divisible
        else
        {
            temp.pb(t1);
            while (t2 % t1 == 0 && (t2 / t1) % t1 == 0)
            {
                temp.pb(t1);
                t2 /= t1;
            }

            temp.pb(t2);
        }

        if (temp.size() > res.size())
        {
            res.clear();
            for (int j = 0; j < temp.size(); j++)
                res.pb(temp[j]);
        }
    }

    if (res.size() == 0)
    {
        cout << 1 << endl
             << n << endl;
        return;
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
