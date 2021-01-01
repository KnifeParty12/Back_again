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

vector<int> hist(MAX);
int n; // size of array

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> hist[i];

    stack<int> s;
    int tp;
    int temp_area;
    int ans = 0;

    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        else
        {
            tp = s.top();
            s.pop();

            temp_area = hist[tp] * (s.empty() ? i : i - s.top() - 1); // in i - s.top() - 1 ( i is leftmost index where hist[i] <= top())
            if (ans < temp_area)
                ans = temp_area;
        }
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        temp_area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        if (ans < temp_area)
            ans = temp_area;
    }
    cout << ans << "\n";
}

/* TESTCASE

    5
    3 1 3 2 2

 */

int main()
{
    fast_io int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
