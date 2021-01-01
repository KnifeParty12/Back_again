#include<iostream>
#include<algorithm>

using namespace std;

class Fraction {

 private :
     int num;
     int den;

 public :

    Fraction(int num,int den){
        this -> num = num;
        this -> den = den;
    }

    void display(){

    cout<<num<<"/"<<den<<"\n";
    }


    void simplify (){
        int k = __gcd(num,this->den);
        this->num /= k;
        this->den /= k;
    }

    Fraction operator+(Fraction const &f2) const {
        int lcm = this->den * f2.den;
        int x = lcm/den;
        int y = lcm/f2.den;
        int anum = x*this->num + (y*f2.num);

        Fraction fnew(anum,lcm);
        fnew.simplify();
        return fnew;
    }

    Fraction operator*(Fraction const &f2)const {

       int num1 = num * f2.num;
       int den1 = den * f2.den;

       Fraction fnew(num1,den1);
        fnew.simplify();
        return fnew;
    }

    bool operator==(Fraction f2) const{

    return (num == f2.num && den == f2.den);
    }

    Fraction& operator++(){
    num = num + den;
    simplify();
    return *this;
    }
};
