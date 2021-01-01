#include<bits/stdc++.h>

#define endl "\n"

using namespace std;

void Vector(){

vector<int> A = {11,2,3,14};

cout<<A[1]<<endl;

sort(A.begin(),A.end()); //O(nlogn)

//2,3,11,14

//O(logN)
bool present = binary_search(A.begin(),A.end(),2); //True

A.push_back(100); //Pushes 100 at the end of vector
present = binary_search(A.begin(),A.end(),100);

//2,3,11,14,100
A.push_back(100);
A.push_back(100);
A.push_back(100);
A.push_back(100);

//2,3,11,14,100,100,100,100,100
A.push_back(123);
//2,3,11,14,100,100,100,100,100,123

auto it = lower_bound(A.begin(),A.end(),100); // >=
auto it2 = upper_bound(A.begin(),A.end(),100); // >
cout<<it2 - it<<endl; //5

sort(A.begin(),A.end(),greater<int>()); //descending order sort


vector<int>:: iterator it3;

for(it3 = A.begin(); it3!=A.end();it3 ++){
    cout<< *it3<< " ";
}

cout<<endl;

//Another way to print vector

for(int x: A){
    cout<<x<<" ";
}
cout<<endl;


//To make changes to the vector elements while iterating a vector

for(int &x : A){
    x++;
    cout<< x <<" ";
}


}
int main(){

Vector();
return 0;
}
