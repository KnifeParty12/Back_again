#include<iostream>
#include<climits>
using namespace std;

class mapval{
public:
    int key;
    int val;

    mapval(){
    key = INT_MIN;
    val = -1;
    }

    mapval(int key, int val){
    this->key = key;
    this->val = val;
    }
};

class Map{


public:
    mapval *arr;
    int capacity;
    int sz;

    Map(){
    capacity = 30;
    sz = 0;
    arr = new mapval[capacity];

    //Initialise all elements of array as INT_MIN
    for(int i=0 ; i < capacity ; i++) arr[i] = {INT_MIN,-1};
    }

    int hashCode(int key){
        return key % capacity;
    }

    void insert(int key,int value){
        // Apply hash function to find index for given key

    int cnt = 0; // count variable to check if map is full or not
    int hashIndex = hashCode(key);
    while(arr[hashIndex].key!=INT_MIN){
        cnt++;
        hashIndex++;
        hashIndex%=capacity;
    }
    if(cnt == capacity){
        cout<<"Map is Full\n";
        return;
    }
    else{
        arr[hashIndex] = {key,value};
        sz++;
    }
    }

    void deletenode(int element){
        int hashIndex = hashCode(element);
        while(arr[hashIndex].key!=INT_MIN){
            if(arr[hashIndex].key == element){
                    arr[hashIndex] = {INT_MIN,-1}; // dummy value
                    sz--;
                    return;
            }
            hashIndex++;
            hashIndex%=capacity;
        }

        return; // If key not found
    }

    int findkey(int key){
        int hashIndex = hashCode(key);
        int cnt = 0;
        while(arr[hashIndex].key!= NULL){
            cnt = 0;
            if(cnt++ > capacity)return NULL; // avoid infinite loop

            if(arr[hashIndex].key == key) return arr[hashIndex].val;
            hashIndex++;
            hashIndex%=capacity;
        }
        cout<<"Key not found\n";
        return NULL;
    }

    //Return current size
    int sizeofMap(){
        return sz;
    }

    //Return true if size is 0
    bool isEmpty(){
        return sz == 0;
    }

    //Function to display the stored key value pairs
    void display(){
        for(int i=0 ; i<capacity ; i++){
            if(arr[i].key!= INT_MIN)
                cout << "key = " << arr[i].key<<"  value = "<< arr[i].val << endl;
        }
    }

};

int main(){

Map *m = new Map();
m->insert(12,3);
cout<<m->findkey(12)<<endl;
m->deletenode(12);
cout<<m->sizeofMap()<<endl;
return 0;
}

