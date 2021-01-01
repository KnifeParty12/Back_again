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
#define MAX 100005
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

ll n, k;

vector<ll> arr(MAX);

void preprocess()
{
    for (int i = 0; i < MAX; i++)
        arr[i] = i + 1;
    for (int i = 1; i < MAX; i++)
        arr[i] += arr[i - 1];
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    char res[n];
    for (int i = 0; i < n; i++)
        res[i] = 'a';

    int gap = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

    ll cnt = k - arr[gap - 1]; // check if 0
    // positions of 'b'
    //this gap is the one we need to fit into if cnt != 0
    // positon of 1st b from left -> (n-1) - gap - 1 = n - gap - 2
    // last b -> n-1-cnt
    // 5 2  abaab
    // 10 4  aaaabaaaab
    if (cnt == 0)
    {
        gap--;
        res[n - gap - 2] = 'b';
        res[n - gap - 1] = 'b';
    }

    else
    {
        cnt--;
        res[n - gap - 2] = 'b';
        res[n - cnt - 1] = 'b';
    }

    for (int i = 0; i < n; i++)
        cout << res[i];
    cout << endl;
}

// 5 2
// aaabb , aabab

int main()
{
    preprocess();
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
