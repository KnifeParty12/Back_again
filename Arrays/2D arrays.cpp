#include<iostream>
#include<cmath>
#include<climits>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

void findlargest(int arr[][6],int row,int col){
int summax=INT_MIN,index=-1;
bool isRow=true;
for(int i=0;i<row;i++){
       int rowsum=0;
for(int j=0;j<col;j++){
    rowsum+=arr[i][j];
}
    if(rowsum>summax){
        summax=rowsum;
        index=i;
    }
}
for(int j=0;j<col;j++){
    int colsum=0;
for(int i=0;i<row;i++){
    colsum+=arr[i][j];
}
if(colsum>summax){
    isRow=false;
    summax=colsum;
    index=j;
}
}
if(isRow==true){
    cout<<"row"<<" "<<index<<" "<<summax;
}
else
    cout<<"column"<<" "<<index<<" "<<summax;
}

void printa(int arr[][6],int row,int col){
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}
int main(){
int bucky[][6]={ {1,3,4,5,6,7},{2,4,5,2,5,6},{5,23,436,12,364,3}, {2,5,2,364,21,34} };
    printa(bucky,4,6);
    cout<<endl;
    findlargest(bucky,4,6);

return 0;
}

