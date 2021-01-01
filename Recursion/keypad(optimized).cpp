#include<bits/stdc++.h>

using namespace std;
string dialer(int d){
string options[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
return options[d];

}

void keypad(int n,string output){
if(n==0){
    cout<<output<<endl;
    return;
}
int d=n%10;
int smallnum=n/10;
string options=dialer(d);
int i=0;
while(i<options.length()){
    keypad(smallnum,options[i]+output);
    i++;
}
}

int main(){
int n;
cin>>n;
string output="";
keypad(n,output);

return 0;
}
