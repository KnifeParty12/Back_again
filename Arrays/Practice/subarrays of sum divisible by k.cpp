#include<bits/stdc++.h>

using namespace std;

int helper(int *arr, int n, int k){

int mod[k];

memset(mod,0,sizeof(mod));

int sum = 0;
for(int i =0; i<n; i++){
    sum +=arr[i];

    mod[((sum %k) + k)%k]++; //for negative numbers
}

int res =0;
for(int i=0; i<k; i++){
    if(mod[i] > 1){
        res += (mod[i]* (mod[i] -1))/2;
    }

}
res +=mod[0];
return res;
}

