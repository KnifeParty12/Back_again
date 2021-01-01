#include<iostream>
#include<cmath>
#include<climits>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

int length(char str[]){
int count=0;
for(int i=0;str[i]!='\0';i++){
    count++;
}
return count;
}
void reverse1(char str[],int startw,int enda){
int i=startw;
int j=enda;
while(i<j){
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    i++;
    j--;
}
}
void reversestring(char str[]){
int i=0;
int j=length(str)-1;
while(i<j){
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
    i++;
    j--;
}
}

void ReverseStringWordWise(char str[]){
reversestring(str);
int startw=0,enda=0,i;
for(i=0;str[i]!='\0';i++){
    if(str[i]==' '){
        enda=i-1;
        reverse1(str,startw,enda);
        startw=i+1;
    }
}
enda=i-1;
reverse1(str,startw,enda);
}


int main(){
char bucky[]="nigga bold af na suck my tiddie ass";
ReverseStringWordWise(bucky);
cout<<bucky;

return 0;
}
