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

int n; // number of entries

bool is_palindrome(string &str)
{

    int sz = str.size();
    int i = 0, j = sz - 1;
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

void solve()
{
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    unordered_map<string, int> cnt; // to store reverse words indices

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        string temp = input[i];
        reverse(temp.begin(), temp.end());
        cnt[temp] = i;
    }

    if (cnt.find("") != cnt.end())
    {
        for (int i = 0; i < n; i++)
        {
            if (is_palindrome(input[i]))
                res.pb({cnt[""], i});
        }
    }

    for (int i = 0; i < n; i++)
    {
        string temp = input[i];
        for (int j = 0; j < temp.size(); j++)
        {
            string left = temp.substr(0, j);
            string right = temp.substr(j, temp.size() - j);
            if (cnt.find(left) != cnt.end() && is_palindrome(right) && cnt[left] != i)
                res.pb({i, cnt[left]});

            if (cnt.find(right) != cnt.end() && is_palindrome(left) && cnt[right] != i)
                res.pb({cnt[right], i});
        }
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
