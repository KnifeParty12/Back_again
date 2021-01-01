#include<iostream>
#include<climits>
#include<utility>
using namespace std;

void bubblesort(int a[],int size){
for(int i=0;i<(size-1);i++){
    for(int j=0;j<size-1;j++){
        if(a[j]>a[j+1]){
         swap(a[j],a[j+1]);
        }
    }
}
}

int main(){
int bucky[12]={1,4,3,2,6,45,32,76,5,88,76,44};
bubblesort(bucky,12);
for(int i=0;i<12;i++){
    cout<<bucky[i]<<" ";
}

return 0;
}
