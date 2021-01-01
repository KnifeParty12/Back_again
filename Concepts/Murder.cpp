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

ll mergeo(int *arr, int si, int mid, int ei){
ll ans = 0;
int temp[ei - si + 1];

int i = si;
int j = mid;
int k = 0;

while(i < mid && j <=ei){
    if(arr[i] >= arr[j]) temp[k++] = arr[j++];
    else{
        ans += (ei - j + 1)*arr[i];
        temp[k++] = arr[i++];
    }
}

while(i<mid) temp[k++] = arr[i++];
while(j <= ei) temp[k++] = arr[j++];

//Copy them back
k = 0;
for(int x = si; x<=ei; x++){
    arr[x] = temp[k++];
}
return ans;
}



ll mergesort(int *arr, int si, int ei){
if(si>=ei) return 0;
int mid = si + (ei-si)/2;
ll ans = mergesort(arr,si,mid);
ans+= mergesort(arr,mid+1,ei);
ans+=mergeo(arr,si,mid+1,ei);
return ans;
}


void solve(){
int n;
cin>>n;
int arr[n];
for(int i = 0; i<n; i++) cin>> arr[i];

ll ans = mergesort(arr,0,n-1);
cout<<ans<<endl;
}



int main(){
fast_io

int tc = 1;
cin>>tc;
while(tc--){
    solve();
}

return 0;
}



