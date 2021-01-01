#include<iostream>

using namespace std;

class vehicle {

public :
    string color ;

    virtual void print() = 0;
};

class car  : public vehicle {

public :
    int tyres;

   void print(){

    cout<<"Car\n";
    }

    };


    int main(){

    car c;

    return 0;
    }


