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

int MCM(vector<int> &p, int start, int end, vector<vector<int>> &memo)
{
    if (start == end || start == end - 1)
        return 0;

    if (memo[start][end] != -1)
    {
        cout << "Overlapping Subproblem :" << start << " " << end << endl;
        return memo[start][end];
    }
    int ans = INT_MAX;
    for (int k = start + 1; k < end; k++)
    {
        int temp = MCM(p, start, k, memo) + MCM(p, k, end, memo) + (p[start] * p[k] * p[end]);
        if (temp < ans)
            ans = temp;
    }
    memo[start][end] = ans;
    return memo[start][end];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> p[i];
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
    cout << MCM(p, 0, n, memo);
}

int main()
{
    fast_io int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
    return 0;
}
