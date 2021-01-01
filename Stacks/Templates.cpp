#include<iostream>

using namespace std;

template<typename T,typename V>

class Pair {

T x;
V y;

public :
    void setX(T x){
    this ->x = x;
    }

    T getX(){
    return x;
    }

    void setY(V y){
    this ->y = y;
    }

    V getY(){
    return y;
    }

};

int main(){

Pair<int,int> p2;
Pair<Pair<int,int>,int> p1;
p2.setX(12);
p2.setY(22);
p1.setX(p2);
cout<<p1.getX().getX();

return 0;
}
