#include<iostream>
#include <algorithm>
#include<math.h>
#include "Dynamic Array Class.cpp"

using namespace std;


class Student {

public :
    int rollnumber;
    int age;

    static int totalstudents;

    Student() {
    totalstudents++;
    cout<<"Total Students are "<<totalstudents<<"\n";
    }

    static int gettotalstudents(){
    return totalstudents;
    }

};

int Student :: totalstudents = 20;



int main(){


int *p = new int[10]{0};
cout<<p[2];

return 0;
}
