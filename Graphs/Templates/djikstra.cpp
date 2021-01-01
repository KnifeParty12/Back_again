#include<bits/stdc++.h>
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define sloop(str,i,a) for(int i = a; str[i]!='\0'; i++)
#define mod (ll)1e9 + 7
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int,int>
#define MAX 100001
#define inf 1000000000000000LL

typedef long long ll;
using namespace std;


ll D[MAX];//distance array
int n; // vertex
vector<PII> adj[MAX];

void dijkstra(){
    for(int i = 1; i <= n; i++) D[i] = inf;
    D[1] = 0;
    set<pair<ll,int>> pq; // distance - vertex
    pq.insert({0,1}); // distance - vertex
    map<int,int> check;
    while(!pq.empty()){
        int u = pq.begin()->s;
        ll dist = pq.begin()->f;
        pq.erase(pq.begin());

        if(dist > D[u]) continue;

        for(PII pr : adj[u]){
            int v = pr.f;
            ll next_dist = dist + pr.s;

            if(next_dist < D[v]){
                pq.erase({D[v],v});
                D[v] = next_dist;
                check[v] = u;
                pq.insert({next_dist,v});
            }
        }
    }
    if(D[n] == inf){
    cout<<-1<<endl;
    return;
    }

    vector<int> ans;
    auto it = check[n];
    ans.pb(n);
    while(it!= 1){
        ans.pb(it);
        it = check[it];
    }
    ans.pb(1);
    reverse(ans.begin(),ans.end()); // printing path
    for(int i = 0; i<ans.size(); i++) cout<<ans[i]<<" ";
}

int main(){

int e;
cin>>n>>e;
for(int i = 0; i<e; i++){
    int p,q,r;
    cin>>p>>q>>r;
    adj[p].pb({q,r});
    adj[q].pb({p,r});
}

dijkstra();
return 0;
}

