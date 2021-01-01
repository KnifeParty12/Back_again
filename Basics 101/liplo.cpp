#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;


int main(){
int n;
cin>> n;
int i=1;
while(i<=n){
        int space=1;
while(space<=n-i){
    cout<<" ";
    space++;
}
int col=1;
while(col<=i){
    cout<<col;
    col++;
}
    i++;
    cout<<endl;
}
return 0;
}

