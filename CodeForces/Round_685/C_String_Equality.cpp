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

int n, k; // length n and (n-k+1) last index to 'aaaaaaa' boi
string a, b;
string yo = "Yes\n";
string no = "No\n";
int lastindex;
int dp[MAX];

void solve()
{
    cin >> n >> k;
    cin >> a >> b;

    vector<int> fa(27, 0);
    vector<int> fb(27, 0);

    for (int i = 0; i < n; i++)
    {
        fa[a[i] - 'a']++;
        fb[b[i] - 'a']++;
    }
    bool bad = false;
    for (int i = 0; i <= 26; i++)
    {
        if (fa[i] < fb[i])
        {
            bad = true;
            break;
        }
        else
        {
            int left = fa[i] - fb[i];
            fa[i] -= fb[i];
            if (left % k) // coz we can only increment in blocks of k
            {
                bad = true;
                break;
            }
            fa[i + 1] += fa[i];
        }
    }

    if (bad)
        cout << no;
    else
        cout << yo;
}

// aaaabb
// ddddcc

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
