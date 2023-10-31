#include<iostream>
#include<stack>
#include<queue>
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
    cout<<endl;
}

void R_PreOrder(node *root){// Node Left Right
    if (root==NULL) return;
    while (root != NULL){
        cout << root->data << " ";
        R_PreOrder(root->lnode);
        root = root->rnode;
    }
}

void doubleR_PreOrder(node *root){
    if (root==NULL) return;
    cout << root->data<<" ";
    doubleR_PreOrder(root->lnode);
    doubleR_PreOrder(root->rnode);
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
    cout<<endl;
}

void doubleR_InOrder(node *root){
    if (root==NULL) return;
    doubleR_InOrder(root->lnode);
    cout << root->data<<" ";
    doubleR_InOrder(root->rnode);
}


void doubleR_PostOrder(node *root){
    if (root==NULL) return;
    doubleR_PostOrder(root->lnode);
    doubleR_PostOrder(root->rnode);
    cout << root->data<<" ";
}

void PostOrder(node *root){
    stack <node *> st;
    struct node * prev;int count =0;
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
        if (root->lnode == NULL && root->rnode == NULL){
            cout << root->data << " ";
            prev = root;
        }
        if (root->rnode == prev && root->rnode != NULL){
            cout << root->data << " ";
            prev = root;
        }
        if (root->lnode == prev && root->rnode != NULL){
            st.push(root);
            root = root->rnode;
            continue;
        }
        cout << "<>" << prev->data<<"<>" << endl;
        if (count++ > 10) break; 
        root =  NULL;
    }
    cout << endl;
}

void levelOrder(node * root){
    queue<node *>Queue;
    Queue.push(root);
    while(!Queue.empty()){
        node * temp = Queue.front();
        Queue.pop();
        cout << temp->data << " ";
        if (temp->lnode != NULL)
            Queue.push(temp->lnode);
        if (temp->rnode != NULL)
            Queue.push(temp->rnode);
    }
    cout << endl;
}

int main(){
    /*create this static binary tree
                    10
            12              13
        14      15      45      65 
                    100     
    */
   // we need 7 nodes
    node *root;
    node n1,n2,n3,n4,n5,n6,n7,n8;
    root = &n1;
    n1.data = 10;
    n2.data = 12;
    n3.data = 13;
    n4.data = 14;
    n5.data = 15;
    n6.data = 45;
    n7.data = 65;
    n8.data = 100;
    n1.lnode = &n2;
    n1.rnode = &n3;
    n2.lnode = &n4;
    n2.rnode = &n5;
    n3.lnode = &n6;
    n3.rnode = &n7;
    n5.rnode = &n8;
    n8.lnode = n8.rnode = n4.lnode = n4.rnode = n5.lnode = n6.lnode = n6.rnode = n7.lnode = n7.rnode = NULL;
    // tranversal can be done in 3 ways -
    // Level order
    //pre-order     (NLR)
    //in-order      (LNR)
    //post-order    (LRN)
    cout << "LevelOrder" << endl;
    levelOrder(root);
    cout << endl;
    cout << "preorder" << endl;
    PreOrder(root);
    R_PreOrder(root);
    cout << endl;
    doubleR_PreOrder(root);
    cout << endl;
    cout << "\nInOrder" << endl;
    InOrder(root);
    doubleR_InOrder(root);
    cout << endl;
    cout << "\nPostOrder" << endl;
    doubleR_PostOrder(root);
    cout << endl;
    PostOrder(root);
    return 0;
}