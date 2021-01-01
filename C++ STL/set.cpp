#include<bits/stdc++.h>
#define endl "\n"

using namespace std;


void Set(){

set<int> S;

S.insert(14);
S.insert(19);
S.insert(17);
S.insert(11);
S.insert(56);
S.insert(22);
S.insert(12);


auto it = S.lower_bound(13);
cout<<*it<<endl;
for(int x : S){
    cout<<x<<" ";
}


}



int main(){

Set();

return 0;
}
