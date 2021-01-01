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

vector<int> price(MAX);

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> price[i];
    // logic keep track of right max as you can only buy and sell once that's all
    if (n < 2)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> right_max(n);
    right_max[n - 1] = -1;
    int mx = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i] < mx)
            right_max[i] = mx;
        else
        {
            mx = price[i];
            right_max[i] = -1;
        }
    }

    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (right_max[i] != -1)
        {
            profit = max(profit, right_max[i] - price[i]);
        }
    }
    cout << profit;
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
