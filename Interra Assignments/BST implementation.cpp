#include<iostream>

using namespace std;

struct key_val{
int key;
int val;
};


struct node {
        key_val data;
        node* left;
        node* right;
};

class BST {
    node* root;
    int cnt;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x,int y node* t){

        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        cnt++;
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        cnt--;
        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
        void preorder(node* t) {
        if(t == NULL)
            return;
        cout << t->data << " ";
        inorder(t->left);
        inorder(t->right);
    }
        void postorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        inorder(t->right);
        cout << t->data << " ";
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
        cnt = 0;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x,int y) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display(string order) {
        if(order == "inorder")inorder(root);
        else if(order == "preorder")preorder(root);
        else postorder(root);
        cout << endl;
    }
    void search(int x) {
        root = find(root, x);
    }

    void totalnodes(){
        cout<<cnt<<endl;
    }

    void ifempty(){
        if(root == NULL) cout<<"BST is empty\n";
        else cout<<"BST is not empty\n";
    }
};

int main() {
    BST t;
    t.ifempty();
    t.insert(20);
    t.insert(10);
    t.insert(5);
    t.display("inorder");
    t.remove(20);
    t.display("inorder");
    return 0;
}
