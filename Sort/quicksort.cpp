#include<bits/stdc++.h>
using namespace std;
int parti(int*arr,int si,int ei){
int pivot=arr[si];
int count=0;
for(int i=si+1;i<=ei;i++){
    if(arr[i]<=pivot){
        count++;
    }
}
int pivotindex=si+count;
swap(arr[si],arr[pivotindex]);
int i=si;
int j=ei;
while(i<pivotindex && j>pivotindex){
    while(arr[i]<=pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
    if(i<pivotindex && j>pivotindex){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
return pivotindex;
}

void quickie(int*arr,int si,int ei){
if(si>=ei){
    return;
}
int c=parti(arr,si,ei);
quickie(arr,si,c-1);
quickie(arr,c+1,ei);
}


int main() {
int arr[]={2,6,5,4,3,1,4,0,6,3,2,6,2};
int size=sizeof(arr)/sizeof(arr[0]);
quickie(arr,0,size-1);
cout<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}

return 0;
}

