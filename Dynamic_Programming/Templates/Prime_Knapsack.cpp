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
#define MAX 2005
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

int prime[11] = {1,2,3,5,7,11,13,17,19,23,29};
//29,23,19,17,13,11,7,5,3,2,1
int n, w;
vector<int> profit(MAX);
vector<int> wt(MAX);

int dp[2][MAX][MAX]; // here states are if prime taken or not , i size array , deciding on (i-1)th element whether picked without prime/not picked/with prime

int knappy(){

    // Base Case
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=w; j++){
            dp[0][i][j] = dp[0][i-1][j];
            if(j >= wt[i-1]) dp[0][i][j] = max(dp[0][i][j],dp[0][i-1][j-wt[i-1]] + profit[i-1]);
        }
    }

    for(int p = 1; p<=10; p++){
        int f = p&1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=w; j++){
                dp[f][i][j] = dp[f][i-1][j]; // exclude
                if(j >= wt[i-1])
                dp[f][i][j] = max({dp[f][i][j],(dp[f][i-1][j-wt[i-1]] + profit[i-1]), (dp[f^1][i-1][j-wt[i-1]] + (profit[i-1]*prime[p]))});
            }
        }
    }
        return dp[0][n][w];
}


void solve()
{
    cin >> n >> w;
    int x, y;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        arr.pb({x, y});
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    });

    for (int i = 0; i < n; i++)
    {
        profit[i] = arr[i].first;
        wt[i] = arr[i].second;
    }

    cout<<knappy()<<endl;

}

/*
3 4
1 1
2 1
3 1
*/


int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
