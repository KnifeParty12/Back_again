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

bool perfectstring(string s){
int len=s.length();
int sum=0;
for(int i=0;i<len;i++){
    sum+=(int)s[i];
}
long double leftover=sqrt(sum)-floor(sqrt(sum));
if(leftover==0){
    return true;
}
else
    return false;
}


int main() {
string s;
cin>>s;
cout<<perfectstring(s);
return 0;
}
