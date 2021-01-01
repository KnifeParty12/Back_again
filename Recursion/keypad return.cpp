#include<bits/stdc++.h>

using namespace std;

string getstring(int d){
if(d==2){
    return "abc";
}
if(d==3){
    return "def";
}
if(d==4){
    return "ghi";
}
if(d==5){
    return "jkl";
}
if(d==6){
    return "mno";
}
if(d==7){
    return "pqrs";
}
if(d==8){
    return "tuv";
}
if(d==9){
    return"wxyz";
}
return " ";
}
int keypad(int n,string output[]){
if(n==0){
   output[0]="";
   return 1;
}
int d=n%10;
int smallnumber=n/10;
int smallans=keypad(smallnumber,output);
string options=getstring(d);
for(int i=0;i<options.size()-1;i++){
    for(int j=0;j<smallans;j++){
        output[j+((i+1)*smallans)]=output[j];
    }
}
int k=0;
for(int i=0;i<options.size();i++){
    for(int j=0;j<smallans;j++){
        output[k]=output[k]+options[i];
        k++;
    }
}
return smallans*(options.size());
}

int main(){
int n;
cin>>n;
string*output=new string[500];
int k=keypad(n,output);
for(int i=0;i<k;i++){
    cout<<output[i]<<endl;
}
delete[] output;
return 0;
}
