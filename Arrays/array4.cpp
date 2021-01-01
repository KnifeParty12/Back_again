#include<iostream>
#include<algorithm>

using namespace std;

void SortZ(int a[], int n){
sort(a,a+n);
for(int i=0;i<n;i++){
  cout<<a[i]<<" ";

}
}

int main(){
int bucky[9]={1,0,0,1,1,0,1,0,1};
SortZ(bucky,9);
return 0;
}
