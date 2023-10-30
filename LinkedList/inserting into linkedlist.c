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

int insectIntoLinkedListByIndex(struct node ** Start, int index ,int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->n = value;
    if (index == 0){
        new->next = *Start;
        *Start = new;
    }else{
        struct node * s =  *Start;
        if (s == NULL){
            new->next = NULL;
            *Start = new;
        }
        while (index-1){
            s = s->next;
            if (s == NULL){
                free(new);
                return 1;
            }
            index--;
        }
        new->next = s->next;
        s->next = new;
    }
    return 0;
}

int insectIntoLinkedListByValue(struct node ** Start, int v ,int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->n = value;
    struct node *s = *Start;
    if (s == NULL){
        *Start = new;
        new->next = NULL;
        return 0;
    }while (s != NULL){
        if (s->n == v){
            new->next = s->next;
            s->next = new;
            return 0;
        }
        s = s->next;
    }
    return 1;
}

int insectIntoLinkedListByAddress(struct node ** Start, struct node * addr,int value){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->n = value;
    struct node *s = *Start;
    if (s == NULL){
        *Start = new;
        new->next = NULL;
        return 0;
    }while (s != NULL){
        if (s == addr){
            new->next = s->next;
            s->next = new;
            return 0;
        }
        s = s->next;
    }
    return 1;
}

int main(){
    struct node * linkedlistStart = createLinkedList(0);

    
    struct node * s = linkedlistStart;
    printf("start -> ");
    while (s){
        printf("[%d] ",s->n);
        s = s->next;
    }
    printf("-> end\n");
    int result = insectIntoLinkedListByIndex(&linkedlistStart,1,45);
    if (result){
        printf("can't perform operation with these parameters.\n");
    }
    s= linkedlistStart;
    printf("start -> ");
    while (s){
        printf("[%d] ",s->n);
        s = s->next;
    }
    printf("-> end\n");
    return 0;
}