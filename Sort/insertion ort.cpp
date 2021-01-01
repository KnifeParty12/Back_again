#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

void insertionsort(int a[],int size){
for(int i=1;i<size;i++){
    int j=i-1;
    int temp=a[i];
    while(a[j]>temp && j>=0){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
}
}
void printboi(int a[],int size){
for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
}
}
int main(){
int bucky[9]={4,6,2,7,1,3,8,5,0};
insertionsort(bucky,9);
printboi(bucky,9);
return 0;
}
