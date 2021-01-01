#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void linearsearch(int arr[],int size,int n){
    bool b=false;
for(int i=0;i<size;i++){
    if(arr[i]==n){
    b++;
    }
}
cout<<b<<endl;
}

int main(){
    int size;
    cin>>size;
    int bucky[size];
for(int i=0;i<size;i++){
    cin>>bucky[i];
}
cout<<endl;
linearsearch(bucky,size,2);

return 0;
}
