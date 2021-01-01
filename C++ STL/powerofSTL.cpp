#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

void POS(){

set<pair<int,int> > S;
S.insert({401,450});
S.insert({10,20});
S.insert({2,3});
S.insert({30,400});

int point = 400;
auto it = S.upper_bound({point,INT_MAX});

if(S.begin()== it){
    cout<<"the given point is not present anywhere..\n";
    return;
}

it--;
pair<int,int> current = *it;
if(current.first<=point && current.second >= point){
    cout<<"yes : " <<current.first<< " " <<current.second<<endl;
} else{

    cout<<"Not Present anywhere\n";
}


}


int main(){
POS();

return 0;
}
