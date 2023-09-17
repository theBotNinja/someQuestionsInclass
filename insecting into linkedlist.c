#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *next;
};

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

int insectIntoLinkedList(struct node ** Start, int index ,int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (index == 1){
        new->n = value;
        new->next = *Start;
        *Start = new;
    }else{
        struct node * s =  *Start;
        while (index-1){
            s = s->next;
            if (s == NULL){
                free(new);
                return 1;
            }
            index--;
        }
        new->n = value;
        new->next = s->next;
        s->next = new;
    }
    return 0;
}

int main(){
    struct node * linkedlistStart = createLinkedList(10);

    int result = insectIntoLinkedList(&linkedlistStart, 10 ,100);
    if (result){
        printf("can't perform operation with these parameters.\n");
    }

    struct node * s = linkedlistStart;
    printf("start -> ");
    while (s){
        printf("[%d] ",s->n);
        s = s->next;
    }
    printf("-> end\n");
    return 0;
}