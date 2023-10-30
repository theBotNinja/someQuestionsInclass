#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * lnode;
    struct node * rnode;
};

struct node1{
    struct node *info;
    struct node1 *next;
};

struct node1 *start = NULL;

void push(struct node *val){
    struct node1 *new = (struct node1 *)malloc(sizeof(struct node1));
    if (new){
        if (start){
            new->next = start;
            start = new;
        }else{
            start = new;
            new->next = NULL;
        }
        new->info = val;
    }else{
        printf("Stack Overflow !!\n");
    }
}

struct node * pop(){
    if (start){
        struct node1 *temp = start;
        start = start->next;
        struct node * t1 =  temp->info;
        free(temp);
        return t1;
    }else{
        printf("Stack Underflow!!\n");
    }
}


void R_PreOrder(struct node *root){// Node Left Right
    if (root==NULL) return;
    while (root != NULL){
        printf("%d ",root->data);
        R_PreOrder(root->lnode);
        root = root->rnode;
    }
}

struct node * CreateBT(){
    int val;
    char ch;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("enter the value at node : ") ;
    scanf("%d",&val);
    new->data = val;
    new->lnode = new->rnode = NULL;
    printf("this node has left ? <y> or  <n> : ");
    scanf(" %c",&ch);
    if (ch == 'y'){
        new->lnode = CreateBT();
    }

    printf("this node has right ? <y> or  <n> : ");
    scanf(" %c",&ch);
    if (ch == 'y'){
        new->rnode = CreateBT();
    }
    return new;
}
 struct node * CreateBT_using_stack(){
    int val;
    char ch;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value at ROOT node : ") ;
    scanf("%d",&val);
    new->data = val;
    new->lnode = new->rnode = NULL;
    push(new);
    while (start != NULL)
    {
        struct node * temp = pop();
        printf("this with val %d node has left ? <y> or  <n> : ",temp->data);
        scanf(" %c",&ch);
        if (ch == 'y'){
            struct node *new2 = (struct node *)malloc(sizeof(struct node));
            printf("enter the value at left of node  %d : ",temp->data) ;
            scanf("%d",&val);
            new2->data = val;
            new2->lnode = new2->rnode = NULL;
            push(new2);
            temp->lnode = new2;
        }
        printf("this with val %d node has right ? <y> or  <n> : ",temp->data);
        scanf(" %c",&ch);
        if (ch == 'y'){
            struct node *new2 = (struct node *)malloc(sizeof(struct node));
            printf("enter the value at right of node  %d: ",temp->data) ;
            scanf("%d",&val);
            new2->data = val;
            new2->lnode = new2->rnode = NULL;
            push(new2);
            temp->rnode = new2;
        }
        printf("\n");
    }
    
    return new;
 }

int main(){
    
    struct node *root = CreateBT_using_stack();
    R_PreOrder(root);
    printf("\n");
    return 0;
}