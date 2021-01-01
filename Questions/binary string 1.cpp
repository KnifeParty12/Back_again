#include<bits/stdc++.h>

using namespace std;


int helper(string s , int k,int n){

int l = 0;
int maxlen = 0;
int cnt0 = 0;
for(int i = 0; i<n; i++){
if(s[i] == '0') cnt0++;

if(cnt0 > k){
    if(s[l] == '0') cnt0--;
    l++;
}
maxlen = max(maxlen,i-l+1);
}
return maxlen;
}


int helperutil(string s, int k, int n){
int maxlen = helper(s,k,n);
string test = "";
for(int i = 0;i<maxlen; i++){
    test+="1";
}
cout<<test<<endl;

vector<int> v;
for(int i =0; i<n; i++){
    if(s[i] == '0') v.push_back(i);
}
int ways = 0;
string temp = s;
int counter = k;
for(int i = 0; i<v.size() - k; i++){
    int j = i;
    while(counter > 0){
        temp[v[j]] = '1';
        counter--;
        j++;
    }
    if(temp.find(test) < n){
            cout<<temp<<endl;
        ways++;
    }
    temp = s;
    counter = k;
}

return ways;
}





int main(){

string s = "1011010101010111010101";
cout<<helperutil(s,2,s.length());
return 0;

}
