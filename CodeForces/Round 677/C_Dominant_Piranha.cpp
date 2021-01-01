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
    vector<ll> arr(n);
    int mx = -1;
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > mx)
            mx = arr[i];
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == mx)
        {
            if (i == 0)
            {
                if (arr[i + 1] != mx)
                {
                    cout << 1 << endl;
                    return;
                }
            }
            else if (i == n - 1)
            {
                if (arr[i - 1] != mx)
                {
                    cout << n << endl;
                    return;
                }
            }
            else
            {
                if (arr[i] > arr[i - 1] || arr[i] > arr[i + 1])
                {
                    cout << i + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
