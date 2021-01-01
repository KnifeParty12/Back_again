#include<iostream>
#include<algorithm>

using namespace std;

int bs(int a[],int size,int k){
int low=0;
int high=size;
int mid;
while(low<=high){
    mid=(low+high)/2;
    if(a[mid]==k){
    return 1;
    }
    else if(a[mid]>k){
        high=mid-1;
    }
    else
        low=mid+1;
}
return -1;
}


int main(){
int bucky[]={1,2,3,4,5,6,7,8,9,14,12};
sort(bucky,bucky+11);
bs(bucky,11,14);
cout<<bs(bucky,11,14)<<endl;

return 0;
}
