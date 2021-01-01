#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

int main() {

unordered_map<string,int> ourmap;
// insertion
ourmap["abc"] = 1;
pair<string , int> p("def" , 2);
ourmap.insert(p);

//find ,search
cout<<ourmap["ghi"]<<endl;
cout<<ourmap.at("abc")<<endl;
cout<<"Size : "<<ourmap.size()<<endl;
// Check presence

if(ourmap.count("ghi") > 0){
    cout<<"key is present" <<endl;
}else{
    cout<<"key is absent"<<endl;
}

// Erase
ourmap.erase("ghi");
cout<<"Size : "<<ourmap.size()<<endl;
if(ourmap.count("ghi") > 0){
    cout<<"key is present" <<endl;
}else{
    cout<<"key is absent"<<endl;
}
return 0;
}
