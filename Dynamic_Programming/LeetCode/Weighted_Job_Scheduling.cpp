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

struct triplet
{
    int start, end, profit;
};

int searchForNonConfilctingJob(vector<triplet> &job, int index)
{
    int lo = 0;
    int hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (job[mid].end <= job[index].start)
        {
            if (job[mid + 1].end <= job[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
    return -1;
}

void solve()
{
    int n; // number of jobs
    cin >> n;
    vector<int> startTime(n);
    vector<int> endTime(n);
    vector<int> profit(n);

    for (int i = 0; i < n; i++)
        cin >> startTime[i];
    for (int i = 0; i < n; i++)
        cin >> endTime[i];
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    vector<triplet> job(n);

    for (int i = 0; i < n; i++)
    {
        job[i].start = startTime[i];
        job[i].end = endTime[i];
        job[i].profit = profit[i];
    }

    vector<int> dp(n, 0);
    dp[0] = job[0].profit;
    for (int i = 1; i < n; i++)
    {
        int p1 = job[i].profit;
        int l = searchForNonConfilctingJob(job, i);
        if (l != -1)
            p1 += dp[l];
        dp[i] = max(dp[i - 1], p1);
    }
    cout << dp[n - 1] << endl;
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
