#include<bits/stdc++.h>
#include<string>
using namespace std;

void sub(string input,string output){
if(input.empty()){
    cout<<output<<endl;
    return;
}
sub(input.substr(1),output);
sub(input.substr(1),output+input[0]);
}

int main(){
string input;
cin>>input;
string output="";
sub(input,output);
return 0;
}
