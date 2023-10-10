#include<stdio.h>
#include<stdlib.h>


struct node
{
    int n;
    struct node *next;
};
struct node *START = NULL;

void showLinkedList(struct node * start){
    struct node * s = start;
    int count = 0;
    printf("start -> ");
    while (s && count < 10){
        printf("[%d] ",s->n);
        s = s->next;
    count ++;
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

struct node * reverseLinkedList(struct node *start,struct node *first){
    struct node *temp = start;
    if (temp->next == NULL){
        START  = temp;
        return temp;
    }
    struct node *s = reverseLinkedList(temp->next,first);
    s->next = temp;
    temp->next = NULL;
}

int main(){
    struct node *linkedlist = createLinkedList(5);
    START = linkedlist;
    showLinkedList(START);
    struct node *rll = reverseLinkedList(linkedlist,START);
    showLinkedList(START);
    return 0;
}