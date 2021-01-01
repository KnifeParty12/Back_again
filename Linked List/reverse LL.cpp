#include<bits/stdc++.h>

using namespace std;

class node {

public :

int data;
node *next;

node(int data){
this->data = data;
next = NULL;

}
};


node *takeInput() {

int data;
cin >> data;
node *head = NULL;
node *tail = NULL;

while(data !=-1){

    node *newnode = new node(data);
    if(head == NULL){
        head = newnode;
        tail = newnode;

    } else{
        tail->next = newnode;
        tail = newnode;
}
    cin >> data;
}

return head;
}




void printer(node *head){

node *temp = head;
while(temp !=NULL){
    cout<<temp->data<<" ";
    temp = temp ->next;
}
}


void reverie(node *head){

node *prev = NULL;
node *curr = head;
node *next;

while(curr !=NULL){

    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}

head = prev;

printer(head);

}




int main(){

node *head = takeInput();
reverie(head);

return 0;
}
