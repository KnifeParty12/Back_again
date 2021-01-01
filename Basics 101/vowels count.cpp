#include<iostream>
#include<cmath>
#include<climits>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;

void vowels(char str[]){
    int count1=0;
for(int i=0;str[i]!='\0';i++){
    switch(str[i])
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        ++count1;
    }
}
cout<<count1<<endl;
}

int main(){
char input[]="ima albatross with example";
vowels(input);

}
