#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int si,int ei){
int k=0;
int output[ei-si+1]={0};
int i=0;
int j=0;
int m=si;
int mid=si+(ei-1)/2;
while(i<=mid || j<=ei){
    if(arr[i]<arr[j]){
        output[k]=arr[i];
        i++;
        k++;
    }
    else{
        output[k]=arr[j];
        k++;
        j++;
    }
}
while(i<=mid){
    output[k]=arr[i];
        i++;
        k++;
}
while(j<=ei){
    output[k]=arr[j];
        j++;
        k++;
}
for(int i=0;i<k;i++){
    arr[m]=output[i];
    m++;
}

}

void mergesort(int arr[],int si,int ei){
if(si>=ei)
return;
int mid=si+(ei-1)/2;
mergesort(arr,si,mid);
mergesort(arr,mid+1,ei);
merge(arr,si,ei);
}
void printa(int arr[],int size){
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}

}

int main(){
int arr[]={1,4,6,2,2,5,6,31,1,0,0,4,2,1};
mergesort(arr,0,13);
printa(arr,14);
    return 0;
}

