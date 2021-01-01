#include<iostream>
#include<string>
#include<fstream>
#define MAX 10001
using namespace std;

int counter=0;

class automata{
	int top;
	int st[MAX]; // stack taken for pda

public :
	automata(){
	    top=-1; // initialize top for 0's
	}
	void push(int);
	void pop();
	int valid(string);
	int  parsefile(string);
	void clear();

};
void automata :: clear()
{
	for(int i=0; i< 100; i++) st[i]=0;
        top=-1 ;
}
int automata :: parsefile(string filename){
int cnt=0;
string str;
ifstream file(filename, ios::in);
 while(getline(file, str))
	  cnt++;
 file.close();
 cout<< "Lines count in  input.txt  : "<< cnt <<" "<<endl;
return cnt;
}
void automata :: push(int x){
 top++;
 st[top]=x;
}
void automata :: pop(){
 top--;
 if(top==-1)counter++;
}
int automata :: valid(string str)
{
int n=str.length();
 top=-1;
 for(int i=0; i<n; i++)
    {
		if(top<-1) return 0;

        if(str[i]=='0' || str[i]=='1')
        {
            if(str[i]=='0') push((int)(str[i]-'0'));
            else pop();
        }
        else break;
    }
    if(top==-1)return 1;
    else return 0;
}

int main()
{
string str1;
int i=0, sz; // number of lines/queries
automata pd; // declaring object for pda
string filename ="input.txt";             //fill with your absolute path
                                          //taking input file name location using \\ from subtitle
cout<< "File : "<< filename <<" "<<endl;           // calling the function size file
sz= pd.parsefile(filename);
ifstream ip (filename, ios::in);           //reading the file
string* arr = new string[sz];
while(!ip.eof())                 //upto end of the file
   {
  getline(ip, str1);
         arr[i]=str1;
		 cout<< "input.txt line "<< i<<" : "<< arr[i]<<" "<<endl; // taking string subtittle
          i++;
   }
string *write = new string[sz];

for(int j=0;j<sz;j++)
{
	i=pd.valid(arr[j]);
	pd.clear();
	if(counter==1 && i==1)
	{
		write[j] = "True";
	}
	else
	{
		write[j] = "False";
	}
	counter=0;
}
ofstream myop;
myop.open ("output.txt");
for(int j=0;j<sz;j++)
{
	myop << write[j]<<endl;
}
myop.close();
cout<< "Output is written in output.txt : "<< endl;
    ip.close();
    delete arr; // deallocating memory
    delete write; // deallocating memory
    system("pause");
}
