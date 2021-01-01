#include<iostream>

using namespace std;


 class vehicle{

 public :

 print(){

 cout<<"vehicle\n";

 }

 /* vehicle(){

 cout<<"default constructor vehicle\n";
 } */

 vehicle(int r){
 cout<< r<<"\n";

 }
 };

 class car : virtual  public vehicle{

 public :

 printi(){

 cout<<"Car\n";

 }

 car() : vehicle(3){

 cout<<"car constructor\n";
 }

 };


 class truck : virtual public vehicle{

 public :

 printo(){

 cout<<"Truck\n";

 }

 truck(): vehicle(5) {

 cout<<"Truck constructor\n";
 }

 };

 class bus : public car , public truck {

 public :

 bus() : vehicle(12){

 cout<<"bus constructor\n";
 }

 };


 int main(){

 bus b;

  return 0;
 }
