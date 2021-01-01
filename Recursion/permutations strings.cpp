#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int length(char str[]){
  int count=0;
  for(int i=0;str[i]!='\0';i++){
    count++;
  }
  return count;
}


bool isPermutation(char str1[], char str2[]) {
  int a=length(str1);
int b=length(str2);
  sort(str1,str1+a);
  sort(str2,str2+b);
 if(a!=b){
   return false;
 }
  else
  for(int i=0;str1[i]!='\0';i++){
    for(int j=0;st2[j]!='\0';j++){
      if(str[i]==str[j]){
        break;
      }
    }
  }
}



int main(){

}
