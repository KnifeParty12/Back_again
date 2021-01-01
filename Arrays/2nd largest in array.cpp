#include<iostream>
#include<cmath>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;

int secondlargest(int a[],int size){
int L=a[0];
int S=INT_MIN;
for(int i=1;i<size;i++){
if(a[i]>L){
    S=L;
    L=a[i];
}
else if(a[i]>S && a[i]!=L){
    S=a[i];
}
}
return S;
if(size<=0)
    return INT_MIN;
}

int main(){
int bucky[10]={12,45,236,456,76,356,688,688,888,87};
int k=secondlargest(bucky,10);
cout<<k<<endl;
return 0;
}









