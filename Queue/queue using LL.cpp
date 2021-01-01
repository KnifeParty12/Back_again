#include<iostream>

using namespace std;

template<typename T>
class Node {

 public :

T data;
Node<T> *next;


Node(T data) {
    this->data = data;
    next = NULL;
}

};





template<typename T>
class Queue {
int maxsize;
Node<T> *head;
Node<T> *tail;

public :

Queue() {
maxsize = 0;
head = NULL;
tail = NULL;
}

void enqueue(T element){
    Node<T> *newnode = new Node<T>(element);
    if(head == NULL){
        head = newnode;
        tail = newnode;
    } else{
        tail->next = newnode;
        tail = newnode;
    }
    maxsize++;
}

bool isempty(){

return (maxsize == 0) ? true : false;
}

int size(){
return maxsize;
}

T front() {
return head->data;
}

void dequeue(){
if(maxsize == 0){
    return;
}
else{
     head = head->next;
}
}

};



int main() {

Queue<int> q;
q.enqueue(12141);
q.enqueue(1264);
q.enqueue(112);
q.enqueue(123);
q.enqueue(122);
q.dequeue();
cout<<q.size()<<endl;;
cout<<q.front();
return 0;
}
