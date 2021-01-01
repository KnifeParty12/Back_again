#include<iostream>

using namespace std;

template<typename T>

class Stack{

T *data;
int nextindex;
int capacity;

public :

Stack() {
    capacity = 4;
data = new T[capacity];
nextindex = 0;

}

public:
    int size() {

    return nextindex;
    }

    bool isempty() {
    bool k = (nextindex == 0) ? true : false;
    return k;
    }

    T push(T element) {
    if(capacity < nextindex){
        T *newdata = new T[2*capacity];
        for(int i = 0; i<capacity; i++){
            newdata[i] = data[i];

        }
        delete [] data;
        data = newdata;
        capacity *=2;
    }
    data[nextindex] = element;
    nextindex++;
    }

    void pop() {
        if(isempty()){
            cout<<"Stack empty ma nigga !\n";
        }
    nextindex--;
    }

    T top() {

    return data[nextindex-1];
    }

};


int main() {

Stack<char> s;
s.push(100);
s.push(101);
s.push(102);
cout<<s.top();
return 0;
}
