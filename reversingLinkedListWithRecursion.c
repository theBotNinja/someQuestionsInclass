#include<stdio.h>
#include<stdlib.h>


struct node
{
    int n;
    struct node *next;
};

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

struct node * reverseLinkedList(struct node *start){
    
    if (start->next == NULL){
        return start;
    }else{
        struct node *str = reverseLinkedList(start->next);

    }
}

int main(){
    struct node *linkedlist = createLinkedList(11);
    showLinkedList(linkedlist);
    struct node *rll = reverseLinkedList(linkedlist);
    showLinkedList(rll);
    return 0;
}