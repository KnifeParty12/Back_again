#include<bits/stdc++.h>
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define loop(i,a,b) for(int i=a;i<b;i++)
#define sloop(str,i,a) for(int i = a; str[i]!='\0'; i++)
#define mod 1e9 + 7
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int,int>
#define MAX 1000005
#define inf 1000000000000000LL

typedef long long ll;
using namespace std;

struct subtitle{
int start;
int end;
string cap;
};

struct stringsubs{
string start;
string end;
string cap;
};

int main(){


//ifstream infile("Sample.srt.txt");
ifstream infile("test.txt");

string str = "";
vector<string> withspace;

while(!infile.eof()){
    getline(infile,str);
    withspace.pb(str);
}
infile.close();
vector<string> withoutspace;

for(int i = 0; i<withspace.size(); i++){
    if(i%2 == 0)withoutspace.pb(withspace[i]);
}

vector<subtitle> arr(withoutspace.size());
for(int i = 0; i<withoutspace.size(); i++){
    string word = "";
    int cnt = 0;
    for(auto x : withoutspace[i]){
        if(x == ' '){
            if(word.empty()) continue;

            else{
                cnt++;
                if(cnt == 1){ // starttime
                    int temp = stoi(word);
                    arr[i].start = temp;
                    word="";
                }
                else if(cnt == 2){ // endtime
                    int temp = stoi(word);
                    arr[i].end = temp;
                    word="";
                }
                else word+=x;
            }
        }
        else word+=x;
    }
        arr[i].cap = word;
}
//
//for(auto it : arr){
//    cout<<it.start<<" "<<it.end<<" "<<it.cap<<endl;
//}






return 0;
}
