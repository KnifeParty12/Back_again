#include<iostream>
#include<stack>

using namespace std;

void showstack(stack <int> s){

while(!s.empty()){
    cout<<s.top()<< " ";
    s.pop();
}
cout<<"\n";

}




int main(){


stack<int> s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
s.push(60);

showstack(s);
cout<<s.size()<<endl;
cout<<s.top()<<endl;
s.pop();
showstack(s);
return 0;
}
