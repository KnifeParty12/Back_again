#include<iostream>

using namespace std;

class teacher{

string name;
int roomno;

print(){

cout<<"Teacher\n ";
}

};

class student {

int rollno;
string name;

print(){

cout<<"Student\n";
}
};

class TA : public teacher , public student{

int ret;

};


int main(){

TA a;

a.print();
return 0;
}
