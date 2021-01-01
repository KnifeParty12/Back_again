#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;


void printTree(BinaryTreeNode<int> * root){
if(root == NULL){
    return;
}
cout<<root->data<< ": ";
if(root->left){
    cout<<"L"<<root->left->data;
}
if(root->right){
    cout<<"R"<<root->right->data;
}
cout<<endl;
}


int countnode(BinaryTreeNode<int> *root){

if(!root) return 0;

return 1 + countnode(root->left) + countnode(root->right);

}



int main() {

BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

root->left = node1;
root->right = node2;

BinaryTreeNode<int> *node3 = new BinaryTreeNode<int>(4);
BinaryTreeNode<int> *node4 = new BinaryTreeNode<int>(5);
node1->left = node3;
node1->right = node4;

cout<<countnode(root);
return 0;

}

