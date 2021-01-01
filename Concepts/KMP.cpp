#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define loop(i, a, b) for (int i = a; i < b; i++)
#define sloop(str, i, a) for (int i = a; str[i] != '\0'; i++)
#define mod 1e9 + 7
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int, int>
#define MAX (int)1e6 + 1
#define inf 1000000000000000LL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
using namespace std;

int reset[MAX];

void KMPpreprocess(string &pat)
{
    int i = 0, j = 1;
    reset[0] = -1;
    while (i < pat.size())
    {
        while (j >= 0 && pat[i] != pat[j])
            j = reset[j];
        i++;
        j++;
        reset[i] = j;
    }
}

void KMPSearch(string &str, string &pat)
{
    KMPpreprocess(pat);
    int cnt = 0;
    int i = 0, j = 0;
    while (i < str.size())
    {
        while (j >= 0 && str[i] != pat[j])
            j = reset[j];
        i++;
        j++;
        if (j == pat.size())
        {
            cout << "Pattern is found at "
                 << " " << i - j << endl;
            cnt++;
            j = reset[j];
        }
    }
    cout << cnt;
}

void solve()
{
    string pat, str;
    cin >> str >> pat;
    for (int i = 0; i < MAX; i++)
        reset[i] = -1;
    KMPSearch(str, pat);
}

int main()
{
    fast_io int tc = 1;
    //cin>>tc;
    while (tc--)
        solve();
    return 0;
}
