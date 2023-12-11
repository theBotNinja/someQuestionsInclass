#include<iostream>
#include<queue>
using namespace std;

struct node {
    int data;
    struct node * lnode;
    struct node * rnode;
};

void printValuesAtLeafNodes(node *root){
    if (root==NULL) return;
    if (root->lnode == NULL && root->rnode == NULL)// this is the condition for leaf node printing while transversal
        cout << root->data<<" ";
    printValuesAtLeafNodes(root->lnode);
    printValuesAtLeafNodes(root->rnode);
}

void printValuesAtIntermalNodes(node *root){
    if (root==NULL) return;
    while (root != NULL){
        if (root->lnode != NULL || root->rnode != NULL)// this is the condition for internal node printing while transversal
            cout << root->data << " ";
        printValuesAtIntermalNodes(root->lnode);
        root = root->rnode;
    }

}

node * getMaxNode(node * root){
    queue<node *>Queue;
    node * maxval = root;
    Queue.push(root);
    while(!Queue.empty()){
        node * temp = Queue.front();
        Queue.pop();
        if (temp->data > maxval->data){
            maxval = temp;
        }
        if (temp->lnode != NULL)
            Queue.push(temp->lnode);
        if (temp->rnode != NULL)
            Queue.push(temp->rnode);
    }
    return maxval;
}

node * R_getMaxNode(node * root){
    node *leftMaxNode,*rightMaxNode;
    if (root->lnode==NULL && root->rnode!=NULL){
        rightMaxNode = R_getMaxNode(root->rnode);
        if (rightMaxNode->data < root->data){
            return root;
        }else{
            return rightMaxNode;
        }
    }else if (root->rnode == NULL && root->lnode != NULL){
        leftMaxNode = R_getMaxNode(root->lnode);
        if (leftMaxNode->data < root->data){
            return root;
        }else{
            return leftMaxNode;
        }
    }else if (root->rnode == NULL && root->lnode == NULL){
        return root;
    }else{
        leftMaxNode = R_getMaxNode(root->lnode);
        rightMaxNode = R_getMaxNode(root->rnode);
        if (leftMaxNode->data > rightMaxNode->data){
            if (leftMaxNode->data > root->data)
                return leftMaxNode;
            else
                return root;
        }else{
            if (rightMaxNode->data > root->data)
                return rightMaxNode;
            else
                return root;
        }
    }
}

int getNumberOfNode(node *root){
    queue<node *>Queue;
    int count = 0;
    if (root != NULL){
        Queue.push(root);
    }
    while(!Queue.empty()){
        node * temp = Queue.front();
        Queue.pop();
        count++;
        if (temp->lnode != NULL)
            Queue.push(temp->lnode);
        if (temp->rnode != NULL)
            Queue.push(temp->rnode);
    }
    return count;
}

int R_getNumberOfNode(node *root){
    int counter = 1;
    if (root->lnode != NULL)
        counter += R_getNumberOfNode(root->lnode);
    if (root->rnode != NULL)
        counter += R_getNumberOfNode(root->rnode);
    return counter;
}

int childWithSingleNode(node *root){
    queue<node *>Queue;
    int count = 0;
    if (root != NULL){
        Queue.push(root);
    }
    while(!Queue.empty()){
        node * temp = Queue.front();
        Queue.pop();
        if ((temp->lnode == NULL && temp->rnode != NULL)||(temp->lnode != NULL && temp->rnode == NULL))
            count++;
        if (temp->lnode != NULL)
            Queue.push(temp->lnode);
        if (temp->rnode != NULL)
            Queue.push(temp->rnode);
    }
    return count;
}

int R_childWithSingleNode(node *root){
    int counter = 0;
    if (root->lnode==NULL && root->rnode!=NULL){
        counter++;
        counter += R_childWithSingleNode(root->rnode);
    }else if (root->rnode == NULL && root->lnode != NULL){
        counter++;
        counter += R_childWithSingleNode(root->lnode);
    }else if (root->rnode != NULL && root->lnode != NULL){
        counter += R_childWithSingleNode(root->rnode);
        counter += R_childWithSingleNode(root->lnode);
    }
    return counter;
}

int main(){
    /*create this static binary tree
                    10
            12              13
        14      15      45      65 
                    100     
    */
   // we need 8 nodes
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
    cout << "leaf node" << endl;
    printValuesAtLeafNodes(root);
    cout << endl;
    cout << "internal node" << endl;
    printValuesAtIntermalNodes(root);
    cout <<"get max node"<< endl;
    node * maxNode = R_getMaxNode(root);
    cout << maxNode->data << endl;
    cout << "count nodes" << endl;
    int nodeCount = R_getNumberOfNode(root);
    cout << nodeCount << endl;
    cout << "number of single child nodes" << endl;
    int singlechildnode = R_childWithSingleNode(root);
    cout << singlechildnode << endl;
    return 0;
}