#include<iostream>
#include<cmath>
#include<climits>
#include<utility>
#include<algorithm>
using namespace std;



void leftrotatebyone(int a[],int size) {
  int temp=a[0];
  int i;
  for(i=0;i<size-1;i++){
    a[i]=a[i+1];
  }
  a[i]=temp;
}

void leftrotate(int a[],int d,int size){
for(int i=0;i<d;i++){
    leftrotatebyone(a,size);
}
}


  int main(){
  int bucky[9]={1,2,3,5,6,7,5,4,9};
  leftrotate(bucky,2,9);
  for(int i=0;i<9;i++){
    cout<<bucky[i]<<" ";
  }
  return 0;
  }
