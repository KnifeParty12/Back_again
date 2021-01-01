#include<iostream>

using namespace std;

class vehicle{

private:
    int maxspeed;

protected:
    int numTyres = 0;

public:
    string color;

    vehicle(){

    cout<<"vehicle constructor called\n";

    }

    vehicle(int r){

    cout<<"Parameterized Constructor vehicle\n";
    }

    ~vehicle(){

    cout<<"Destructor vehicle\n";

    }

};

class car : public vehicle {

public:
    int numGears;

    void print(){

        cout<<numTyres<<"\ n";
    }

    car() : vehicle(5){

    cout<<"Car constructor called\n";

    }

    ~car(){

    cout<<"Destructor car\n";
    }

};

class honda : public car{

public :
    int rel;

    honda(){

    cout<<"Honda boi called\n";
    }

    ~honda(){

    cout<<"Destructor Honda\n";
    }

};

int main(){

honda h1;

}
