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

vector<int> adj[MAX]; // Graph needs to be DAG remember son
int indegree[MAX];
int v,e;
vector<int> res; // containing sorted graph

void topo_sort(){


set<int> pq;
for(int i = 1; i<=v; i++){
    if(indegree[i] == 0) pq.insert(i);
}

while(!pq.empty()){
    int curr = *pq.begin();
    res.pb(curr);
    pq.erase(pq.begin());
    for(auto it : adj[curr]){
        indegree[it]--;
        if(indegree[it] == 0) pq.insert(it);
    }
}

for(int i = 0; i<res.size(); i++) cout<<res[i]<<" ";
cout<<endl;

}

/*
    6 6
    6 1
    5 1
    5 2
    3 4
    4 2
    6 3
*/

void solve(){

cin>>v>>e;
int f,s;
for(int i = 0; i<e; i++){
    cin>>f>>s;
    adj[f].pb(s);
    indegree[s]++;
}

topo_sort();

}


int main(){
int tc = 1;
//cin>>tc;
while(tc--) solve();
return 0;
}
