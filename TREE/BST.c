#include<stdio.h>
#include<stdlib.h>

//node struct for Tree
struct node {
    int data;
    struct node * lnode;
    struct node * rnode;
};

void pushIntoBST(struct node* root,int val){
    struct node* temp = root;
    while(temp!=NULL){
        // check if node is smaller or greater then val
        if (temp->data < val){
            // check if right of the node is null or not
            if (temp->rnode == NULL){
                // create new node and insert the val
                struct node* t = (struct node*)malloc(sizeof(struct node));
                t->data =val;
                t->lnode = t->rnode = NULL;
                temp->rnode = t;
                break;
            }else{
                temp = temp->rnode;
            }
        }else if (temp->data > val){
            // check if left of the node is null or not
            if (temp->lnode == NULL){
                // create new node and insert the val
                struct node* t = (struct node*)malloc(sizeof(struct node));
                t->data =val;
                t->lnode = t->rnode = NULL;
                temp->lnode = t;
                break;
            }else{
                temp = temp->lnode;
            }
        }
    }
}

struct node *createBST(){
    int tempInt;char user_input;
    // create the root node with values 
    printf("enter the value at root node : "); 
    scanf("%d",&tempInt);
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->data = tempInt;
    root->lnode = root->rnode = NULL;
    while (1){
        //add other node in binary search tree 
        printf("enter the value at node : ");
        scanf("%d",&tempInt);
        pushIntoBST(root,tempInt); // push function pushs element at right place in BST
        printf("enter more element (enter) => for yes / (n) => for no) : ");
        scanf(" %c",&user_input);
        if (user_input == 'n'){
            break;
        }
    }
    return root;
}

int searchInBST(struct node *root,int val){// we will be returning 1 if element found and 0 if not
    while(root != NULL){
        if (root->data == val){// checking condition at each node
            return 1;
        }
        else if (root->data < val){ // go down toward right 
            if (root->rnode == NULL){
                break;
            }else{
                root = root->rnode;
            }
        }else if (root->data > val){// go down toward left
            if (root->lnode == NULL){
                break;
            }else{
                root = root->lnode;
            }
        }
    }
    return 0;
}

void doubleR_InOrder(struct node *root){
    if (root==NULL) 
        return;
    doubleR_InOrder(root->lnode);
    printf("%d ",root->data);
    doubleR_InOrder(root->rnode);
}

int main(){
    //creation of BST
    struct node *ROOT = createBST();
    doubleR_InOrder(ROOT);
    //Searching in BST
    int searchForInterger;
    printf("the int you want to search : ");
    scanf("%d",&searchForInterger);
    searchForInterger = searchInBST(ROOT,searchForInterger);
    if (searchForInterger)  printf("Element found !");
    else   printf("Element not found !!");
    return 0;
}