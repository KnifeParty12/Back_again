#include<iostream>
#include<cmath>

using namespace std;

int main(){

int n;
cin>>n;
bool k=false;
int div=2;
while(div<=sqrt(n)){
    if(n%div==0){
        return k=true;

    }
    div++;
}
if(k==true){
    cout<<"Not Prime";
}
else{
    cout<<"Prime";
}
return 0;
}
