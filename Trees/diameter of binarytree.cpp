#include<bits/stdc++.h>
#include "BinaryTreeNode.h"

using namespace std;

pair<int,int> heightDiameter(BinaryTreeNode<int> *root){

if(!root){
    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    return p;
}

pair<int,int> leftans = heightDiameter(root->left);
pair<int,int> rightans = heightDiameter(root->right);
int lh = leftans.first;
int ld = leftans.second;
int rh = rightans.first;
int rd = rightans.second;

int height =  1 + max(lh,rh);
int diameter = max((lh + rh) , max(ld,rd));
pair<int,int> ans;
ans.first = height;
ans.second = diameter;
return ans;
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

pair<int,int>diameter = heightDiameter(root);
cout<<diameter.second;
return 0;
}
