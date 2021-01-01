#include<climits>
#include<iostream>
using namespace std;
char highestOccurringChar(char str[]) {
 int freq[256]={0};
  int index=0;
  char ans;
  int occmax=INT_MIN;
  for(int i=0;str[i]!='\0';i++){
    index=str[i];
    freq[index]++;
  }
	for(int i=0;i<256;i++){
      if(freq[i]>occmax){
        occmax=freq[i];
        index=i;
      }
    }
  ans=index;
  return ans;
}


int main(){
char str[]="qwfqgwhetrgweqwfqefwdfwqa#$#@%#$%@$$##!$#@%$#";
char ans=highestOccurringChar(str);
cout<<ans<<endl;
return 0;
}
