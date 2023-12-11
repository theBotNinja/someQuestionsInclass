#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
void doubleR_InOrder(node *root){
    if (root==NULL) return;
    doubleR_InOrder(root->left);
    cout << root->data<<" ";
    doubleR_InOrder(root->right);
}


struct node * CreateBT(){
    int val;
    char ch;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    cout <<"enter the value at node : ";
    cin >> val;
    t->data = val;
    t->left = t->right = NULL;
    cout << "this node has left ("<< t->data  <<")? <y> or  <n> : ";
    cin >> ch;
    if (ch != 'n'){
        t->left = CreateBT();
    }
    cout << "this node has right ("<< t->data  <<")? <y> or  <n> : ";
    cin >> ch;
    if (ch != 'n'){
        t->right = CreateBT();
    }
    return t;
}

int main(){
    node * binaryTree = CreateBT();
    doubleR_InOrder(binaryTree);
    cout << "\n search for 10's parent : " << endl;
    node *temp = searchParent(binaryTree,10);
    cout << temp->data << endl;
    return 0;
}