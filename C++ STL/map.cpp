#include<bits/stdc++.h>
#define endl "\n"

using namespace std;


void Map(){

map<int,int> A;
A[1] = 100;
A[2] = -1;
A[3] = 200;
A[12131231] = 1;

map<char,int> cnt;
string x = "rachit jain";

for(char c: x){
    cnt[c]++;
}       //O(N)
cout<<cnt['n']<<" "<<cnt['z']<<endl; //logN

}





int main(){

Map();
return 0;
}
