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
string y = "YES\n";
string ne = "NO\n";

void solve()
{
    cin >> n;
    vector<int> arr(n);
    ll sum_n = 0;
    ll sum_p = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
            sum_p += arr[i];
        else
            sum_n += arr[i];
    }

    if (sum_p == abs(sum_n))
        cout << ne;
    else
    {
        cout << y;
        if (sum_p > abs(sum_n))
        {
            sort(arr.begin(), arr.end(), greater<int>());
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else
        {
            sort(arr.begin(), arr.end());
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
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
