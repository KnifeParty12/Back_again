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

class disjointset
{
public:
    vector<int> parent, rank, cnt, minimum, maximum;
    int cnt_cmp;

    disjointset(int v)
    {
        parent.resize(v + 1);
        rank.resize(v + 1);
        cnt.resize(v + 1);
        minimum.resize(v + 1);
        maximum.resize(v + 1);
        cnt_cmp = v;
        for (int i = 1; i <= v; i++)
        {
            parent[i] = i;
            rank[i] = 1;
            cnt[i] = 1;
            minimum[i] = i;
            maximum[i] = i;
        }
    }

    int find(int a)
    {
        if (a == parent[a])
            return a;
        else
            return find(parent[a]);
    }

    void join(int a, int b)
    {
        a = parent[a];
        b = parent[b];
        if (a == b)
            return;
        if(a!=b) cnt_cmp--;    
        if (rank[a] == rank[b])
            rank[a]++;
        if (rank[a] > rank[b])
        {
            parent[b] = a;
            minimum[a] = min(minimum[a], minimum[b]);
            maximum[a] = max(maximum[a], maximum[b]);
            cnt[a] += cnt[b];
        }
        else
        {
            parent[a] = b;
            minimum[b] = min(minimum[a], minimum[b]);
            maximum[b] = max(maximum[a], maximum[b]);
            cnt[b] += cnt[a];
        }
    }

    bool check(int a, int b)
    {
        return find(a) == find(b);
    }

    int get_cnt(int a)
    {
        return cnt[find(a)];
    }
};

void solve()
{
    int v, e;
    cin >> v >> e;
    disjointset dsu(v);
    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        dsu.join(f, s);
    }

    cout << dsu.check(1, 7) << endl;
    cout << dsu.cnt_cmp << endl;
    cout << dsu.find(3);
}

/* 
8 4
1 2
2 3
3 4
5 6

 */

int main()
{
    fast_io int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();
    return 0;
}
