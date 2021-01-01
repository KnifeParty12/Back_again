#include<bits/stdc++.h>
using namespace std;
void merger(int a[],int b[],int size1,int size2){
int i=0,j=0;
int k=0;
int test[size1+size2];
while(i<size1 && j<size2){
    if(a[i]<b[j]){
    test[k]=a[i];
    i++;
    k++;
    }
    else{
        test[k]=b[j];
        j++;
        k++;
    }
}
while(i<size1){
    test[k]=a[i];
    i++;
    k++;
}

while(j<size2){
    test[k]=b[j];
    j++;
    k++;
}
for(int m=0;m<size1+size2;m++){
    cout<<test[m]<<" ";
}
}

int main(){
int bucky[7]={1,3,5,6,7,8,9};
int lucky[5]={0,1,5,6,7};
merger(bucky,lucky,7,5);



return 0;
}

