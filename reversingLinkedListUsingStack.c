#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

struct node{
    int n;
    struct node *next;
};

struct node *Stack = NULL;

void push(int val){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new){
        if (Stack){
            new->next = Stack;
            Stack = new;
        }else{
            Stack = new;
            new->next = NULL;
        }
        new->n = val;
    }else{
        printf("Stack Overflow !!\n");
    }
}

int pop(){
    if (Stack){
        struct node *temp = Stack;
        Stack = Stack->next;
        int t1 =  temp->n;
        free(temp);
        return t1;
    }else{
        return NULL;
    }
}

void showLinkedList(struct node * start){
    struct node * s = start;
    printf("start -> ");
    while (s){
        printf("[%d] ",s->n);
        s = s->next;
    }
    printf("-> end\n");
}

struct node * createLinkedList(int n){
    struct node *start = NULL;
    for (int i = 1 ; i<=n ; i++){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->n = i;
        if (i==1){
            start = new;
            new->next = NULL;
        }else{
            new-> next = start;
            start = new ;
        }
    }
    return start;
}

int main(){
    struct node *LinkedList = createLinkedList(10);
    showLinkedList(LinkedList);
    struct node *s = LinkedList;
    while (s != NULL){
        push(s->n);
        s = s->next;
    }
    printf ("start ->");
    while (1)
    {
        int i = pop();
        if (i==NULL){
            break;
        }
        printf(" [%d]",i);
    }
    printf (" end \n");
    
    return 0;
}