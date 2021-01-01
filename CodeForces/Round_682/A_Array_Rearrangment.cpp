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

int n, x;
string y = "Yes\n";
string no = "No\n";

void solve()
{
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> hash;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        hash[b[i]]++;
    }

    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= x)
        {
            cout << no;
            return;
        }
        int target = x - a[i];
        bool flag = false;
        for (int j = target; j >= 1; j--)
        {
            if (hash.count(j) && hash[j] > 0)
            {
                hash[j]--;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << no;
            return;
        }
    }
    cout << y;
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
