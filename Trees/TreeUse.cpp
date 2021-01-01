#include<iostream>
#include "TreeNode.h"
#include<queue>
using namespace std;


TreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data " <<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!= 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter num of children of " << front->data <<endl;
        int numchild;
        cin>>numchild;
        for(int i = 0; i<numchild ; i++){
            int ChildData;
            cout<<"Enter "<<i << " ith child of " <<front->data<<endl;
            cin >> ChildData;
            TreeNode<int> *child = new TreeNode<int>(ChildData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}



TreeNode<int>* takeInput() {
    int rootData;
    cout<<"Enter Data " <<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter num of children of " << rootData<<endl;
    cin>>n;

    for(int i = 0; i < n; i++){
       TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}


void print(TreeNode<int> *root){

if(root == NULL){
    return;  // Edge Case
}
cout<<root->data<< ":";
for(int i = 0; i<root->children.size(); i++){
    cout<<root->children[i]->data<<",";
}
cout<<endl;
for(int i = 0; i<root->children.size() ; i++){
    print(root->children[i]);
}
}



int main() {

/*TreeNode<int>* root = new TreeNode<int>(1);
TreeNode<int>* node1 = new TreeNode<int>(2);
TreeNode<int>* node2 = new TreeNode<int>(3);
root->children.push_back(node1);
root->children.push_back(node2);
*/

TreeNode<int> *root = takeInputLevelWise();
print(root);
return 0;
}
