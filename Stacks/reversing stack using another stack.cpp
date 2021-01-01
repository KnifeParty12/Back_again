#include<iostream>
#include<stack>

using namespace std;

int main() {

stack<int> s1;
s1.push(1);
s1.push(2);
s1.push(3);
s1.push(4);

stack<int>s2;
s2.push(s1.top());
cout<<s2.top();

return 0;
}
