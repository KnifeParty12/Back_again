#include<iostream>
#include<algorithm>

using namespace std;

class Polynomial {

int * degCoeff;
int capacity;

Polynomial(){

degCoeff = new int[10]{0};
capacity = 10;

}

Polynomial(Polynomial const &p1){

degCoeff = new int [p1.capacity]{0};
for(int i = 0; i < p1.capacity ; i++){
    degCoeff[i] = p1.degCoeff[i];
}
capacity = p1.capacity;
}

void operator=(Polynomial const &p1){

degCoeff = new int[p1.capacity];
for(int i = 0 ; i < p1.capacity ; i++){
    degCoeff[i] = p1.degCoeff[i];
}
capacity = p1.capacity;
}

void setCoefficient(int degree,int coefficient){

if(degree >= capacity){
    int sizer = 2*capacity;

    while(sizer <= degree){
        sizer *=2;
    }

    int *newDegCoeff = new int[sizer]{0};

    for(int i = 0 ; i<capacity; i ++){

        newDegCoeff[i] = degCoeff[i];
    }
    delete [] degCoeff;
    degCoeff = newDegCoeff;
    capacity = sizer;
}

    degCoeff[degree] = coefficient;

}

Polynomial operator+(Polynomial const &p1){

    Polynomial pnew;
    int i = 0 , j = 0;
    while(i < this->capacity && j < p1.capacity){
        int deg = i;
        int coeff = this->degCoeff[i] + p1.degCoeff[i];
        pnew.setCoefficient(deg,coeff);
        i++;
        j++;
    }
    while( i < capacity){
        pnew.setCoefficient(i,degCoeff[i]);
        i++;
    }
    while( j < p1.capacity){
        pnew.setCoefficient(j,p1.degCoeff[j]);
        j++;
    }

    return pnew;
}


Polynomial operator-(Polynomial const &p1){

    Polynomial pnew;
    int i = 0 , j = 0;
    while(i < this->capacity && j < p1.capacity){
        int deg = i;
        int coeff = this->degCoeff[i] - p1.degCoeff[i];
        pnew.setCoefficient(deg,coeff);
        i++;
        j++;
    }
    while( i < capacity){
        pnew.setCoefficient(i,degCoeff[i]);
        i++;
    }
    while( j < p1.capacity){
        pnew.setCoefficient(j,( -1 * p1.degCoeff[j]));
        j++;
    }

    return pnew;
}

int getCoefficient(int degree){

   int k =  (degree >= capacity) ?  0 :  degCoeff[degree];

   return k;
}




Polynomial operator*(Polynomial const &p1){

    Polynomial pnew;

    for(int j = 0 ; j<p1.capacity ; j++){
    for(int i = 0 ; i < capacity ; i++){
            int deg = i + j;
            int coeff = getCoefficient(deg) + (degCoeff[i] * p1.degCoeff[j]);
            pnew.setCoefficient(deg,coeff);
    }
    }
    return pnew;
}

};

