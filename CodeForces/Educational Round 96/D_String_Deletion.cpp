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
#define pii pair<int, int>
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

int n;
string str;

void solve()
{
    cin >> n >> str;
    vector<int> prefix;

    int prev = str[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (str[i] == prev)
            len++;
        else
        {
            prefix.pb(len);
            len = 1;
            prev = str[i];
        }
    }
    prefix.pb(len);

    int ans = 0;
    bool flag = true; // deletion of char going on

    for (int i = 0; i < prefix.size(); i++)
    {
        if (flag)
        {
            if (prefix[i] > 1)
                ans++;
            else
            {
                flag = false;
                continue;
            }
        }
        else
        {
            flag = true;
            ans++;
        }
    }
    if (!flag)
        ans++;
    cout << ans << endl;
}

/* 
Need to find maximum operations we can perform

TIPS : (a) choose i to delete from the prefix itself(len > 1)

1100010011
ans = 4
STEPS : (a) maintain array for prefix lengths

prefix -> 2 3 1 2 2


 */

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
