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

int helper(vector<int> &en, int lo, int hi)
{
    if (lo == hi - 1)
        return 1;
    int mid = en[lo];
    if (mid == hi)
        return 2 * helper(en, lo + 1, hi - 1); // (smaller-problem)
    else
        return helper(en, lo, mid) + helper(en, mid + 1, hi); // (s1) + (s2)
}

void solve()
{
    // LOGIC
    // () => 1
    // (A) => 2*score
    // AB => score of(A)  + score of (B)

    string str;
    cin >> str;
    stack<int> st;
    int n = str.size();
    vector<int> en(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ')')
        {
            int t = st.top();
            st.pop();
            en[t] = i;
        }
        else
            st.push(i);
    }

    // now recursion will do the work
    cout << helper(en, 0, n - 1) << endl;
}

int main()
{
    fast_io int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}
