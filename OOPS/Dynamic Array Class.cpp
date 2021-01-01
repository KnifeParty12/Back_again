#include<iostream>
#include<algorithm>

using namespace std;

class DynamicArray {

int *data;
int nextindex;
int capacity;

public :

DynamicArray(){
nextindex = 0;
data = new int[5];
capacity = 5;
}

DynamicArray(const DynamicArray &d1){

    // Deep Copy
    this-> data = new int[d1.capacity];
    for(int i = 0; i <d1.nextindex; i++){
            this->data[i] = d1.data[i];
    }
    this-> nextindex = d1.nextindex;
    this->capacity = d1.capacity;

}

void operator=(const DynamicArray &d1){

    this-> data = new int[d1.capacity];
    for(int i = 0; i <d1.nextindex; i++){
            this->data[i] = d1.data[i];
    }
    this-> nextindex = d1.nextindex;
    this->capacity = d1.capacity;

}


void addElement(int element){

if(nextindex == capacity){
    int * data2 = new int[capacity*2];
    for(int i = 0;i <capacity;i++){
        data2[i] = data[i];
        }
        delete [] data;
        data = data2;
        capacity *=2;
}
  data[nextindex] = element;
nextindex++;

}

int getElement(int i){

        if(i < nextindex){
            return data[i];
        }else{
            return -1;
        }
    }


    void add(int i, int element){

    if(i<nextindex){
        data[i] = element;
    }
    else if(i == nextindex){
        addElement(element);
    }
    else{
        return;
    }
}

void print(){
for(int i =0; i<nextindex; i ++){

    cout<<data[i]<<" ";
}
cout<<"\n";
}

};

