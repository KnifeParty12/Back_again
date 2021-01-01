#include<iostream>
#include<deque>

using namespace std;

void showdq(deque<int> g){

deque<int> :: iterator it;
for(it = g.begin(); it!=g.end(); ++it){
    cout<<*it<<" ";
}
cout<<endl;
}



int main(){

deque<int> gquiz;
gquiz.push_back(10);
gquiz.push_front(20);
gquiz.push_back(30);
showdq(gquiz);
cout<<gquiz.max_size();
return 0;
}
