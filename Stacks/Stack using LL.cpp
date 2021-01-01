#include<iostream>

using namespace std;

template<typename T>
class Node {

public :
    T data;
    Node<T> *next;  // Coz Node class T ki bani hai

    Node(T data){
    this ->data = data;
    next = NULL;
    }
};

template<typename T>
class Stack{

    Node<T>*head;
    int size; //No of elements present in stack

public:

    Stack() {
        head = NULL;
        size = 0;
    }

    int getSize() {

    return size;
    }

    bool isempty() {
    return (head == NULL) ? true : false;
    }

    void push(T element) {
      Node <T> *newnode = new Node<T>(element);
      newnode->next = head;
      head = newnode;
        size++;
    }

    T pop() {
        if(isempty){
            return 0;
        }
    T value = head->data;
    head = head->next;
    return value;
    }

    T top() {
        if(head == NULL) return 0;

        return head->data;
    }

};

int main() {

Stack<int> s;
s.push(12);
s.push(23);
s.push(22);
cout<<s.top();
return 0;
}
