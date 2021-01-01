#include<iostream>
#include<queue>

using namespace std;

int main() {

queue<int> q;
q.push(12);
q.push(23);
q.push(768);
q.pop();
cout<<q.front();
return 0;
}
