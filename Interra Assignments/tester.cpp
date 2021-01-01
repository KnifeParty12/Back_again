#include<iostream>
using namespace std;

class mapVal {
    public:
    int key;
    int value;


    mapVal(int key,int value) {
        this->value = value;
        this->key = key;
    }
};

//Our own map class
class Map
{
    //hash element array
    mapVal**arr;
    int capacity;
    //current size
    int size;
    //dummy node
    mapVal *dummy;

    public:
    Map()
    {
        //Initial capacity of hash array
        capacity = 30;
        size=0;
        arr = new mapVal*[capacity];

        //Initialise all elements of array as NULL
        for(int i=0 ; i < capacity ; i++)
            arr[i] = NULL;

        //dummy node with value and key -1
        dummy = new mapVal(-1, -1);
    }

    int hashCode(int key)
    {
        return key % capacity;
    }

    //Function to add key value pair
    void insert(int key,int value){
        mapVal*temp = new mapVal(key, value);

        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //find next free space
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }

        //if new node to be inserted increase the current size
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }

    //Function to delete a key value pair
    int deleteNode(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        //finding the node with given key
        while(arr[hashIndex] != NULL)
        {
            //if node found
            if(arr[hashIndex]->key == key)
            {
                mapVal*temp = arr[hashIndex];

                //Insert dummy node here for further use
                arr[hashIndex] = dummy;

                // Reduce size
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;

        }

        //If not found return null
        return NULL;
    }

    //Function to search the value for a given key
    int get(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);
        int counter=0;
        //finding the node with given key
        while(arr[hashIndex] != NULL)
        {    int counter =0;
             if(counter++>capacity)  //to avoid infinite loop
                return NULL;
            //if node found return its value
            if(arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        //If not found return null
        return NULL;
    }

    //Return current size
    int sizeofMap()
    {
        return size;
    }

    //Return true if size is 0
    bool isEmpty()
    {
        return size == 0;
    }

    //Function to display the stored key value pairs
    void display()
    {
        for(int i=0 ; i<capacity ; i++)
        {
            if(arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key
                     <<"  value = "<< arr[i]->value << endl;
        }
    }
};

//Driver method to test map class
int main()
{
    Map*h = new Map();
    h->insert(1,1);
    h->insert(2,2);
    h->insert(2,3);
    h->display();
    cout << h->sizeofMap() <<endl;
    cout << h->deleteNode(2) << endl;
    cout << h->sizeofMap() <<endl;
    cout << h->isEmpty() << endl;
    cout << h->get(2);

    return 0;
}
