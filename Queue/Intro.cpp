#include<iostream>

using namespace std;

class Queue {
int *data;
int frontindex;
int nextindex;
int capacity;
int maxsize;

public :

    Queue() {
    capacity = 4;
    data = new int[capacity];
    frontindex = 0;
    maxsize = 0;
    nextindex = 0;
    }

    void enqueue(int element) {
        if(nextindex >= maxsize){
            int *newdata = new int[capacity*2];
            for(int i = frontindex; i<capacity; i++){
                newdata[i] = data[i];
            }
            delete [] data;
            data = newdata;
            capacity *= 2;
        }

        data[nextindex] = element;
        nextindex++;
        maxsize++;
    }

    bool isempty() {
        return (maxsize) ? false : true;
    }

    int size () {
    return maxsize;
    }

    int front() {
    return data[frontindex];
    }

    void dequeue() {
        if(isempty()){
            cout<<"Queue is empty homie\n";
        }
        frontindex++;
        maxsize--;
    }

};





int main(){

Queue q;
q.enqueue(12);
q.enqueue(42);
q.enqueue(22);
q.enqueue(232);
q.enqueue(213);
q.enqueue(13);
q.enqueue(121);
q.enqueue(2213);
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
return 0;
}
