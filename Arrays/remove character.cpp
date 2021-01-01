#include<iostream>
#include<cmath>
using namespace std;

void removeAllOccurrencesOfChar(char str[], char c) {
int j=0;
  for(int i=0;str[i]!='\0';i++){
    if(str[i]!=c){
      str[j]=str[i];
      j++;
    }
  }
  str[j]='\0';
}
