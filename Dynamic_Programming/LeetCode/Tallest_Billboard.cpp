#include<bits/stdc++.h>
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
string to__string(T x){
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

int dp[21][10001];

int helper(vector<int> &rods, int ls, int n){
    if(n == 0){
        if(ls == 0) return 0;
        else return -10000;
    }

    if(dp[n][5000 + ls] != -1) return dp[n][5000 + ls];

    dp[n][5000 + ls] = max({helper(rods,ls,n-1), // right set contains rod
    rods[n-1] + helper(rods,ls+rods[n-1],n-1), // both set ignore the rod
    helper(rods,ls-rods[n-1],n-1)}); // left set contains rod

    return dp[n][5000+ls];
}

void solve()
{
    int n;
    cin>>n;
    vector<int> rods(n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin>>rods[i];
        sum+=rods[i];
    }

    memset(dp,-1,sizeof dp);
    helper(rods,0,n);
}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
