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

bool subsetsum(vector<int> &arr, int n, int k)
{

    unsigned int sz = pow(2, n);
    int bit_set;

    for (bit_set = 0; bit_set < sz; bit_set++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit_set & (1 << i))
                sum += arr[i];
        }
        if (sum == k)
            return true;
    }
    return false;
}

void solve()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << subsetsum(arr, n, k) << endl;
}

/*
6
5 6 3 4 5 1
12
*/

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
