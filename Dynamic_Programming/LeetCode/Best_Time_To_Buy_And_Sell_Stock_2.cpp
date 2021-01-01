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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n < 2)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        // find peaks
        set<int> peaks;
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                if (arr[i] > arr[i - 1])
                    peaks.insert(i);
            }
            else
            {
                if (arr[i] > arr[i - 1])
                    peaks.insert(i);
            }
        }

        int i = 0;
        int profit = 0;
        while (i < n && !peaks.empty())
        {
            int f_peak = *peaks.begin();
            int temp = INT_MAX;
            while (i < f_peak)
            {
                if (arr[i] < temp)
                    temp = arr[i];
                i++;
            }
            peaks.erase(peaks.begin());
            profit += arr[f_peak] - temp;
        }
        cout << profit << endl;
    }
}

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
