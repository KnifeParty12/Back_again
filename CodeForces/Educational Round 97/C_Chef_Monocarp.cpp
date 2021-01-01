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
#define inf 1e9
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

int fast_expo(ll a, ll b)
{

    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a, ans -= mod;
        a *= a, a %= mod;
        b /= 2;
    }
    return ans;
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

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    
    sort(arr.begin(), arr.end());
    vector<vector<int>> dp(n+1,vector<int>(2*n+1,inf)); 
    //dp[i][j] represents "i" size and jth time
    for(int i = 0; i<=2*n; i++) dp[0][i] = 0;
    for(int i = 1; i<=n; i++){ // size
        for(int j = 1; j<=2*n; j++){
            dp[i][j] = min(dp[i][j-1],dp[i-1][j-1] + abs(arr[i-1] - j));
        }
    }

    cout<<dp[n][2*n]<<endl;

}

int main()
{
    fast_io int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
