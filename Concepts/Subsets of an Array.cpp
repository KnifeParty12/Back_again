#include<bits/stdc++.h>
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define sloop(str,i,a) for(int i = a; str[i]!='\0'; i++)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int,int>
#define MAX 100005
#define inf 1000000000000000LL

typedef long long ll;
using namespace std;

void subsets(int *arr,int n){

unsigned int setsize = pow(2,n);

for(int i = 0; i<setsize; i++){
    for(int j = 0; j<n; j++){
        if(i & (1<<j)) cout<<arr[j]<<" ";
    }
    cout<<endl;
}
return;
}



int main(){
fast_io
int arr[] = {56,9,2};
int n = sizeof(arr)/sizeof(arr[0]);
subsets(arr,n);
return 0;
}


