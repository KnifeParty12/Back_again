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
vector<int> lazy(MAX);

void build(int *arr, int start, int end, int t_index){
    if(start == end){
        seg_tree[t_index] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(arr,start,mid,2*t_index);
    build(arr,mid+1,end,2*t_index+1);
    seg_tree[t_index] = seg_tree[2*t_index] + seg_tree[2*t_index + 1];
}

int query(int start, int end, int t_index, int q_start, int q_end){

if(start  > end) return 0;
if(lazy[t_index]!= 0){
seg_tree[t_index] += (end - start + 1)*lazy[t_index];
if(start!= end){
    lazy[2*t_index] += lazy[t_index];
    lazy[2*t_index + 1] += lazy[t_index];
}
    lazy[t_index] = 0;
}

if(start > q_end || end < q_start) return 0; // outside

else  if(start >= q_start && end <=q_end) return seg_tree[t_index]; // complete overlap

else{
    int mid = (start + end) >> 1;
    int a1 = query(start,mid,2*t_index,q_start,q_end);
    int a2 = query(mid+1,end,2*t_index + 1,q_start,q_end);
    return a1 + a2;
}
}

void update(int *arr, int start, int end,int t_index,int u_start, int u_end,int val){

if(start > end) return; // still don't realize when am i gonna hit this condition ever???

if(lazy[t_index]!= 0){
    seg_tree[t_index] += (end - start + 1)*lazy[t_index];

    if(start != end){ // not the leaf
        lazy[2*t_index] += lazy[t_index];
        lazy[2*t_index + 1] += lazy[t_index];
    }
    lazy[t_index] = 0;
}

if(start > u_end || end < u_start) return; // outside

else  if(start >= u_start && end <=u_end){ // complete overlap
    seg_tree[t_index]+= (end - start + 1)*val;

    if(start!=end){ // not the leaf
        lazy[2*t_index] += val;
        lazy[2*t_index + 1] +=val;
    }
    return;
}

int mid = (start + end) >> 1;
update(arr,start,mid,2*t_index,u_start,u_end,val);
update(arr,mid+1,end,2*t_index+1,u_start,u_end,val);
seg_tree[t_index] = seg_tree[2*t_index] + seg_tree[2*t_index+1];
}



/*
TESTCASE

*/



int main(){

int arr[] = {1,2,3,4,5,6,7,8,9,10};
n = 10;
build(arr,0,n-1,1);
for(int i = 1; i<2*n; i++)lazy[i] = 0;

update(arr,0,n-1,1,0,3,3);
for(int i = 1; i<2*n; i++)cout<<seg_tree[i]<<" ";
cout<<endl;
for(int i = 1; i<2*n; i++)cout<<lazy[i]<<" ";
cout<<endl;

update(arr,0,n-1,1,0,1,5);
for(int i = 1; i<2*n; i++)cout<<seg_tree[i]<<" ";
cout<<endl;
for(int i = 1; i<2*n; i++)cout<<lazy[i]<<" ";
cout<<endl;

update(arr,0,n-1,1,2,3,1);
for(int i = 1; i<2*n; i++)cout<<seg_tree[i]<<" ";
cout<<endl;
for(int i = 1; i<2*n; i++)cout<<lazy[i]<<" ";
cout<<endl;

cout<<query(0,n-1,1,0,3)<<endl;
cout<<query(0,n-1,1,1,2)<<endl;
cout<<query(0,n-1,1,2,2)<<endl;



return 0;
}
