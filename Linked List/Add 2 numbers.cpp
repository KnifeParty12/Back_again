#include<bits/stdc++.h>

using namespace std;

class node{

public:

int data;
node *next;

node(int data){
this->data = data;
next = NULL;
}

};

node *makelist(int *arr,int n){

node *head = new node(arr[0]);
node *temp = head;
for(int i = 1; i<n; i++){
    node *newnode = new node(arr[i]);
    temp ->next = newnode;
    temp = temp->next;
}
temp->next = NULL;
return head;

}


node *addlists(node *head1, node *head2){

if(head1 == NULL) return head2;
if(head2 == NULL) return head1;

node *res = NULL;
node *temp, *prev = NULL;
int carry = 0;
int sum;

while(head1!=NULL || head2!= NULL){

    sum = carry + (head1 ? head1->data:0) + (head2 ? head2->data: 0);

    carry = sum / 10;
    sum %=10;

    temp = new node(sum);

    if(!res){
        res = temp;
    }

    else{
        prev ->next = temp;
    }
    prev = temp;
    if(head1) head1 = head1->next;
    if(head2) head2 = head2->next;

}

if(carry){
    temp->next = new node(carry);
}
return res;

}


void printlist(node *head){

while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
}

}



int main(){

int arr[] = {7,5,9,4,6};
int arr2[] = {2,1,3};

node *head1 = makelist(arr,5);
node *head2 = makelist(arr2,3);

node *res = addlists(head1,head2);
printlist(res);

return 0;
}
