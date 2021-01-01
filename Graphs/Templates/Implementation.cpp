#include<bits/stdc++.h>
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define sloop(str,i,a) for(int i = a; str[i]!='\0'; i++)
#define mod 1e9 + 7
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int,int>
#define MAX 1000005
#define inf 1000000000000000LL

typedef long long ll;
using namespace std;

vector<bool> visited(10005);

class graph {
public:
    int v,e;
    vector<int> adj[1005];

    graph(int v,int e){ // v vertex is indexed
        this->v = v;
        this->e = e;
        adj->resize(v);
        visited.resize(v);
        adj->clear();
        visited.clear();
        for(int i = 0; i<e; i++){
            int f,s;
            cin>>f>>s;
            adj[f].pb(s);
            adj[s].pb(f);
        }
    }

    void dfs(int sv){
        visited[sv] = true;
        for(auto it : adj[sv]){
            if(!visited[it])dfs(it);
        }
    }

    void bfs(int sv){
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it : adj[curr]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }

    vector<int> *getpathdfs(int sv,int ev){
        if(sv == ev){
            vector<int> *path = new vector<int>();
            path->pb(ev);
            return path;
        }
        visited[sv] = true;
        for(auto it : adj[sv]){
            if(!visited[it]){
                vector<int> *path = getpathdfs(it,ev);
                if(path!=NULL){
                    path->pb(sv);
                    return path;
                }
            }
        }
        return NULL;
    }

    void getpathbfs(int sv,int ev){

        queue<int> q;
        q.push(sv);
        map<int,int> parent;
        visited[sv] = true;
        bool flag = false;
        while(!q.empty() && !flag){
            int temp = q.front();
            q.pop();
            for(auto it : adj[temp]){
                if(!visited[it]){
                    visited[it] = true;
                    parent[it] = temp;
                    q.push(it);
                    if(it == ev){
                        flag = true;
                        break;
                }
            }
        }
        }
        if(!flag)return;
        vector<int> path;
        path.pb(ev);
        auto it = parent[ev];
        while(it!=sv){
            path.pb(it);
            it = parent[it];
        }
        path.pb(sv);
        for(int i = 0; i<path.size(); i++)cout<<path[i]<<" ";
    }

    bool haspath(int sv, int ev){
            if(sv == ev) return true;

            visited[sv] = true;
            for(auto it : adj[sv]){
                if(!visited[it]){
                    if(haspath(it,ev)) return true;
                }
            }
            return false;
    }

    bool is_connected(){
        visited.clear();
        int cnt = 0;
        for(int i = 0; i<v; i++){
            if(!visited[i]){
              dfs(i);
              cnt++;
            }
        }
        if(cnt == 1)return true;
        else return false;
    }
};


int main(){
fast_io

return 0;
}
