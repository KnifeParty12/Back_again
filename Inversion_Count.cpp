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

int mergo(vector<int> &arr, int si, int mid, int ei)
{

    vector<int> temp((ei - si) + 1);

    int ans = 0;
    int j = mid;
    for (int i = si; i < mid; i++)
    {
        while (j <= ei && arr[i] > arr[j])
            j++;
        ans += j - mid;
    }

    int i = si, k = 0;
    j = mid;

    while (i < mid && j <= ei)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i < mid)
        temp[k++] = arr[i++];
    while (j <= ei)
        temp[k++] = arr[j++];

    k = 0;
    for (i = si; i <= ei; i++)
    {
        arr[i] = temp[k++];
    }
    return ans;
}

int inv_count(vector<int> &arr, int si, int ei)
{

    if (si >= ei)
        return 0;

    int ans = 0;
    int mid = (si + ei) >> 1;
    ans += inv_count(arr, si, mid);
    ans += inv_count(arr, mid + 1, ei);

    ans += mergo(arr, si, mid + 1, ei);

    return ans;
}

void solve()
{
    vector<int> arr = {1, 7, 6, 5, 4, 7, 8, 9, 3, 6, 5, 7, 8, 9, 6, 5, 3, 2, 5, 6, 7, 8, 9, 3, 5, 67};
    int n = arr.size();
    cout << inv_count(arr, 0, n - 1);
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
