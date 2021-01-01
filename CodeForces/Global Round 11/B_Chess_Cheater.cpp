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
int n, k;
string str;

void solve()
{
    cin >> n >> k;
    cin >> str;
    // finding streaks from the start
    int winstreak = 0;
    vector<int> gap;
    int wins = 0, loss = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'W')
        {
            wins++;
            if (i == 0 || str[i - 1] == 'L')
                winstreak++;
        }
        else
        {
            loss++;
            if (i == 0 || str[i - 1] == 'W')
                gap.pb(0);
            gap.back()++;
        }
    }

    if (k >= loss)
    {
        cout << 2 * n - 1 << endl;
        return;
    }
    if (wins == 0)
    {
        if (k == 0)
            cout << "0\n";
        else
            cout << 2 * k - 1 << endl;
        return;
    }

    if (str[0] == 'L')
        gap[0] = 1e8;
    if (str[n - 1] == 'L')
        gap.back() = 1e8;
    sort(gap.begin(), gap.end());
    wins += k;
    for (int i : gap)
    {
        if (i > k)
            break;
        k -= i;
        winstreak--;
    }
    cout << (2 * wins) - winstreak << "\n";
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
