#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


vector<int> removeDups(int *arr , int n) {

vector<int> output;
unordered_map<int, bool> ourmap;

for(int i = 0 ; i < n ; i++){
    if(ourmap.count(arr[i]) > 0){
        continue;
    }else{
    ourmap[arr[i]] = true;
    output.push_back(arr[i]);
    }
}
return output;
}




int main () {

int arr[] = {1,1,2,2,4,5,6,5,4,7,8,6,9,8,9,0};
int size = sizeof(arr)/sizeof(arr[0]);
vector<int> output = removeDups(arr,size);

for(int i : output){
    cout<<i<<" ";
    i++;
}

return 0;
}
