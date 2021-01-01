#include<bits/stdc++.h>

using namespace std;

void rotate(int *arr, int n, int d){

int gcd = __gcd(n,d);

for(int i=0; i<gcd; i++){
    int temp = arr[i];
    int j = i;

    while(1){
        int k = j + d;
        if(k==i) break;
        if(k>=n) k -=n;
        arr[j] = arr[k];
        j = k;
    }
    arr[j] = temp;
}
}
