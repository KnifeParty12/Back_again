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
#define MAX 1000005
#define inf 1000000000000000LL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

typedef long long ll;
using namespace std;

int n;
vector<int> seg_tree(MAX);

void build(int *arr,int start,int end,int t_index){
if(start == end){
    seg_tree[t_index] = arr[start];
    return;
}

int mid = (start + end) >> 1;
build(arr,start,mid,2*t_index);
build(arr,mid+1,end,2*t_index+1);
seg_tree[t_index] = seg_tree[2*t_index] + seg_tree[2*t_index + 1];
}

void update(int *arr,int start,int end,int t_index,int update_index,int val){

if(start == end){
    arr[update_index] = val;
    seg_tree[t_index] = val;
    return;
}

int mid = (start + end) >> 1;
if(update_index <= mid)update(arr,start,mid,2*t_index,update_index,val);

else update(arr,mid+1,end,2*t_index+1,update_index,val);

seg_tree[t_index] = seg_tree[2*t_index]  + seg_tree[2*t_index+1];

}

ll query(int start, int end,int t_index,int q_start,int q_end){
//completely outside
if(start > q_end || end < q_start) return 0;

// completely inside
if(start>=q_start && end<=q_end) return seg_tree[t_index];

// partially inside partially outside
ll mid = (start+end)>>1;
ll a1 = query(start,mid,2*t_index,q_start,q_end);
ll a2 = query(mid+1,end,2*t_index+1,q_start,q_end);
return a1 + a2;
}


int main(){

fast_io
int arr[] = {1,2,3,4,5,6,7,8,9};
n = sizeof arr/sizeof arr[0];
build(arr,0,8,1);
for(int i = 1; i<2*n; i++)cout<<seg_tree[i]<<" ";
cout<<"\n";
update(arr,0,8,1,2,10);
for(int i = 1; i<2*n; i++)cout<<seg_tree[i]<<" ";
cout<<endl;
cout<< query(0,8,1,4,6)<<endl;

return 0;
}
