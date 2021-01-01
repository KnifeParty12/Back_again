#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

void selectionsort(int a[],int size){
for(int i=0;i<(size-1);i++){
    int min=a[i];
    int minindex=i;
    for(int j=i+1;j<size;j++){
        if(a[j]<min){
            min=a[j];
            minindex=j;
        }
    }
    if(minindex!=i){
    a[minindex]=a[i];
    a[i]=min;
    }
}

}



int main() {
int bucky[10]={1,3,5,2,6,6,2,59,23,42};
selectionsort(bucky,10);
for(int i=0;i<10;i++){
    cout<<bucky[i]<<" ";
}
return 0;
}
