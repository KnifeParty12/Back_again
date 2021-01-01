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
    int a[n];
    int b[n];
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> p(n);
    p[0] = a[0];
    int prev = p[0];
    int start = p[0];
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            if (a[i] != prev && a[i] != start)
            {
                p[i] = a[i];
                continue;
            }
            if (b[i] != prev && b[i] != start)
            {
                p[i] = b[i];
                continue;
            }
            if (c[i] != prev && c[i] != start)
            {
                p[i] = c[i];
                continue;
            }
        }
        if (a[i] != prev)
        {
            p[i] = a[i];
            prev = a[i];
            continue;
        }
        else if (b[i] != prev)
        {
            p[i] = b[i];
            prev = b[i];
            continue;
        }
        else if (c[i] != prev)
        {
            p[i] = c[i];
            prev = c[i];
            continue;
        }
    }

    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
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
