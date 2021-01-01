#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

void UN(){

map<char,int> M;
unordered_map<char,int> U;
string s = "Nikhil Kumar"; //add(key,value) - logN(map) , O(1) unordered_map

for(char c: s) M[c]++; //O(logN)

for(char c : s)U[c]++; //O(N)

}



int main(){

UN();

return 0;
}
