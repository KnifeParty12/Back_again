#include<iostream>

using namespace std;

class Student{

public:
    int rollNumber;

private:
    int age;

public:

    ~Student(){
        cout<<"Destructor called\n";

    }

    //Default Constructor
    Student(){
    cout<<"Constructor 1 is called !\n";
    }


    Student(int a,int r){
        cout<<"Constructor Called\n";
        rollNumber = r;
        age = a;
    }

    void display(){

    cout<<age<<" "<<rollNumber<<endl;
    }

};
