#include<iostream>
#include<stack>
using namespace std;

struct node {
    int data;
    struct node * lnode;
    struct node * rnode;
};

void PreOrder(node *root){// Node Left Right
    stack <node *> st;
    while (root != NULL){
        cout << root->data << " ";
        st.push(root->rnode);
        root = root->lnode;
    }
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        if (root != NULL){
            while (root != NULL){
                cout << root->data << " ";
                st.push(root->rnode);
                root = root->lnode;
            }
        }
    }
    
}

void R_PreOrder(node *root){// Node Left Right
    if (root==NULL) return;
    while (root != NULL){
        cout << root->data << " ";
        R_PreOrder(root->lnode);
        root = root->rnode;
    }
}

void InOrder(node *root){
    stack <node *> st;
    while(true){
        while (root != NULL){
            st.push(root);
            root = root->lnode;
        }
        if (st.empty()){
            break;
        }
        root = st.top();
        st.pop();
        cout << root->data << " ";
        root = root->rnode;
    }
}

void PostOrder(node *root){
    stack <node *> st;
    while(true){
        while (root != NULL){
            st.push(root);
            root = root->lnode;
        }
        if (st.empty()){
            break;
        }
        root = st.top();
        st.pop();
        if (root->rnode != NULL)
            cout << root->rnode->data << " ";
        cout << root->data << " ";
        root = root->rnode;
    }
}

int main(){
    /*create this static binary tree
                    10
            12              13
        14      15      45      65      
    */
   // we need 7 nodes
    node *root;
    node n1,n2,n3,n4,n5,n6,n7;
    root = &n1;
    n1.data = 10;
    n2.data = 12;
    n3.data = 13;
    n4.data = 14;
    n5.data = 15;
    n6.data = 45;
    n7.data = 65;
    n1.lnode = &n2;
    n1.rnode = &n3;
    n2.lnode = &n4;
    n2.rnode = &n5;
    n3.lnode = &n6;
    n3.rnode = &n7;
    n4.lnode = n4.rnode = n5.lnode = n5.rnode = n6.lnode = n6.rnode = n7.lnode = n7.rnode = NULL;
    // tranversal can be done in 3 ways -
    //pre-order     (NLR)
    //in-order      (LNR)
    //post-order    (LRN)
    PreOrder(root);
    cout << endl;
    R_PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout <<endl;
    return 0;
}