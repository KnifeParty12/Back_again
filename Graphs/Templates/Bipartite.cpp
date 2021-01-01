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
vector<bool> visited(MAX);
unordered_set<int> s[2];
int v, e;

bool bipartite(int sv)
{
    visited[sv] = true;
    s[0].insert(sv);
    vector<int> pending;
    pending.pb(sv);

    while (!pending.empty())
    {
        int curr = pending.back();
        pending.pop_back();
        int currset = s[0].count(curr) > 0 ? 0 : 1;

        for (auto it : adj[curr])
        {
            if (s[0].count(it) == 0 && s[1].count(it) == 0)
            {
                visited[it] = true;
                s[1 - currset].insert(it);
                pending.push_back(it);
            }
            else if (s[currset].count(it) > 0)
            {
                return false;
            }
        }
    }
    return true;
}

void flush()
{
    s[0].clear();
    s[1].clear();
    for (int i = 0; i <= v; i++)
    {
        visited[i] = false;
        adj[i].clear();
    }
}

void solve()
{

    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    for (int i = 1; i <= v; i++)
        visited[i] = false;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i] && !bipartite(i))
        {
            cout << "NOT BICOLORABLE\n";
            return;
        }
    }

    cout << "BICOLORABLE\n";
}

/*
1
7 8
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
*/

int main()
{
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}