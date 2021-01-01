#include<bits/stdc++.h>
#include<string>
using namespace std;

int subsequences(string input,string output[]){
if(input.empty()){
    output[0]="";
    return 1;
}
string smallstring=input.substr(1);
int smallans=subsequences(smallstring,output);
int i;
for(i=0;i<smallans;i++){
    output[i+smallans]=input[0]+output[i];
}
return 2*smallans;
}
int main(){
string input;
cin>>input;
int k=input.size();
k=pow(2,k);
string*output=new string[k];
int count=subsequences(input,output);
for(int i=0;i<count;i++){
    cout<<output[i]<<endl;
}

return 0;
}
