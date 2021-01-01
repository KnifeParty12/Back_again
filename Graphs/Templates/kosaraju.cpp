#include <bits/stdc++.h>
#define endl "\n"
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define loop(i, a, b) for (int i = a; i < b; i++)
#define sloop(str, i, a) for (int i = a; str[i] != '\0'; i++)
#define mod (ll)1e9 + 7
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int, int>
#define MAX 100001
#define inf 1000000000000000LL

typedef long long ll;
using namespace std;

vector<int> adj[MAX];
vector<int> neg_adj[MAX];
vector<int> visited;
stack<int> s;
int v, e;

void dfs(int sv)
{
    visited[sv] = true;
    for (auto it : adj[sv])
    {
        if (!visited[it])
            dfs(it);
    }
    s.push(sv);
}

void dfs_better(int sv)
{
    visited[sv] = true;
    cout << sv << " ";
    for (auto it : neg_adj[sv])
    {
        if (!visited[it])
            dfs_better(it);
    }
}

void solve()
{
    cin >> v >> e;
    adj->resize(v + 1);
    visited.resize(v + 1);

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        adj[f].pb(s);
        neg_adj[s].pb(f);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(1);
    }
    for (int i = 1; i <= v; i++)
        visited[i] = false;

    while (!s.empty())
    {
        int curr = s.top();
        if (!visited[curr])
        {
            dfs_better(curr);
            cout << "\n";
        }
        s.pop();
    }
}
/*
1
10 12
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
7 8
8 9
9 8
9 10
*/

int main()
{
    fast_io int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
