#include<iostream>
using namespace std;


class Stack{

int *data;
int nextindex;
int capacity;

public :
    Stack(){
    capacity = 4;
    nextindex = 0;
    data = new int[capacity];
    }

    int size(){
    return nextindex;
    }

  void push(int element){
  if(capacity == nextindex){
    int *newdata = new int[2*capacity];
    for(int i = 0; i<capacity; i++){
        newdata[i] = data[i];
    }
    delete [] data;
    data = newdata;
    capacity = 2*capacity;
  }
    data[nextindex] = element;
    nextindex++;
  }

  bool isempty(){
    bool k = (nextindex == 0) ?  true :  false;
    return k;
  }


    int pop() {
    if(isempty()){
        cout<<"Empty Stack ma Nigga !"<<endl;
    }
    nextindex--;
    return data[nextindex];
    }


};




int main(){

Stack s ;

s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
s.push(60);
s.push(70);

s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
s.pop();
cout<<s.isempty();

return 0;
}
