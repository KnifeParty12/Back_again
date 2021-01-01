#include<iostream>

using namespace std;

class bus {

public :
void print();

};



class truck {

private :
    int x;

public :
    int y;

    friend void bus :: print();

};

 void bus :: print(){
 truck t;
 t.x = 12;
 t.y = 34;

 cout<< t.x << " "<<t.y<<endl;

 }


int main() {

bus b;
b.print();

return 0;
}
