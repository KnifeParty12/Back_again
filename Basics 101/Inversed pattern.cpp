#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;


int main(){
int n;
cin>> n;
int i=1;
while(i<=n){
int j=n;
while(j>=1){
    if(j==i){
        cout<<"*";
}
    else
        cout<<j;
        j--;
}
cout<<endl;
i++;
}
return 0;
}

