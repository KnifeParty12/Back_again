#include<bits/stdc++.h>
#inclde "Node.cpp"

using namespace std;



node *reverser(node *head){

if(head == NULL || head->next == NULL) return head;

node *smallhead = reverser(head->next);

head->next ->next = head;
head->next = NULL;
return smallhead;

}

node *addoneUtil(node *head){

node *res = head;
node *temp;
int carry = 1 , sum;

while(head){
    sum = carry + (head ? head->data : 0);
    carry = (sum >= 10) ? 1 : 0;
    sum = sum % 10;
    head ->data = sum;
    temp = head;
    head = head->next;
}
    if(carry > 0){
        temp->next = new node(carry);
    }

    return res;
}


node *addOne(node *head){

head = reverser(head);
head = addoneUtil(head);
head = reverser(head);
return head;
}
