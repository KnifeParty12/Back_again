#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,k;
cin>>n>>k;
int count = 0;
while(n--){
    int t;
    cin>>t;
    if(t % k == 0) count++;
}

cout<<count<<endl;

return 0;
}
