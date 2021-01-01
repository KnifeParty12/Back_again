#include<queue>
#include<iostream>
using namespace std;

template <typename T>
class TreeNode {
public :

    T data;
    vector<TreeNode*> children;

    TreeNode(T data) {
    this->data = data;
    }

};


int countrecur(TreeNode<int> *root){

if(root == NULL){
    return 0;
}

int subans = 1;

for(int i = 0; i<root->children.size() ; i++){
    subans += countrecur(root->children[i]);
}

return subans;
}

int countnode(TreeNode<int> *root){

queue<TreeNode<int>*> pendingnode;
pendingnode.push(root);
int count = 0;
while(!pendingnode.empty()){
    TreeNode<int> *front = pendingnode.front();
    pendingnode.pop();
    count++;
    for(int i = 0; i<front->children.size(); i++){
        pendingnode.push(front->children[i]);
    }
}
return count;
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



int main() {

TreeNode<int> *root = takeInputLevelWise();
print(root);
cout<<endl;
cout<<countrecur(root);
return 0;
}
