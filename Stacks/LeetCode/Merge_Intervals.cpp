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

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        arr.pb({x, y});
    }

    stack<pair<int, int>> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {

        pair<int, int> curr = s.top();
        // if interval outside
        if (curr.second < arr[i].first)
            s.push(arr[i]);
        // if interval
        if (curr.second < arr[i].second)
        {
            curr.second = arr[i].second;
            s.pop();
            s.push(curr);
        }
    }
    vector<pair<int, int>> res;
    while (!s.empty())
    {
        res.pb(s.top());
        s.pop();
    }
}

int main()
{
    fast_io int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}
