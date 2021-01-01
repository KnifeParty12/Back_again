#include<bits/stdc++.h>
using namespace std;

void merge(int *part1,int size1,int *part2,int size2,int arr[]){
int i=0,j=0,k=0;
while(i<size1 && j<size2){
    if(part1[i]<=part2[j]){
        arr[k]=part1[i];
        i++;
        k++;
    }
    else{
        arr[k]=part2[j];
        k++;
        j++;
    }
}
while(i<size1){
    arr[k]=part1[i];
    k++;
    i++;
}
while(j<size2){
    arr[k]=part2[j];
    k++;
    j++;
}

}



void mergesort(int arr[],int size){
if(size<=1){
    return;
}
int mid=size/2;
int part1[100],part2[100];
int size1=mid,size2=size-mid;
for(int i=0;i<mid;i++){
    part1[i]=arr[i];
}
int k=0;
for(int j=mid;j<size;j++){
    part2[k]=arr[j];
    k++;
}
mergesort(part1,size1);
mergesort(part2,size2);
merge(part1,size1,part2,size2,arr);

}
int main() {
int arr[]={2,6,5,4,3,1,84,6,3,2,6,2};
int size=sizeof(arr)/sizeof(arr[0]);
mergesort(arr,size);
cout<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
