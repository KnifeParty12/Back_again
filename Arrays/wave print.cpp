#include<iostream>
#include<cmath>
#include<climits>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

void wavePrint(int arr[][4],int row,int col){
int check=0;
while(check<col){
if(check%2==0){
   for(int j=check;j<(check+1);j++){
      for(int i=0;i<row;i++){
        cout<<arr[i][j]<<" ";
      }
    }
  }
  else{
      for(int j=check;j<check+1;j++){
    for(int i=row-1;i>=0;i--){
      cout<<arr[i][j]<<" ";
    }
  }
  }
check++;
}
}


int main(){
int bucky[3][4]={ {1,2,3,4},{5,6,7,8},{9,10,11,12}};
wavePrint(bucky,3,4);
return 0;
}
