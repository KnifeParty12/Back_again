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
    multiset<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    multiset<int>::iterator it;
    multiset<int>::iterator rit;
    vector<pii> ans;
    while (s.size() != 1)
    {
        it = prev(s.end());
        rit = prev(s.end(), 2);
        int a = *it, b = *rit;
        ans.pb({a, b});
        s.erase(it);
        s.erase(rit);
        s.insert((a + b + 1) / 2);
    }

    cout << *s.begin() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].f << " " << ans[i].s << endl;
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
