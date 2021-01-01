#include<iostream>
#include<cmath>

using namespace std;

int  factorial(int n ){

int ans=1;
for(int  i=1;i<=n;i++){
    ans=ans*i;
}
return ans;
}

int main(){
int  n;
int r;
cin>>n>>r;

int num=factorial(n);
int den1=factorial(r);
int den2=factorial(n-r);
int k=num/(den1*den2);
cout<<k<<endl;

return 0;
}
