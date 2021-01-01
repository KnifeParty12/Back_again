#include<iostream>

using namespace std;

void deletion(int arr[],int size,int k){
for(int i=k;i<size;i++){
    arr[i]=arr[i+1];

}

}

int main(){
int bucky[6]={0,0,0,0,0,0};
for(int i=0;i<6;i++){
    cin>>bucky[i];
}
deletion(bucky,6,4);
for(int i=0;i<5;i++){
    cout<<bucky[i]<<" ";
}
return 0;
}
