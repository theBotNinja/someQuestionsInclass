#include<stdio.h>
#include<stdlib.h>

struct DoublelylinkedList{
    struct node *start;
    struct node *end;
    int length;
};
struct node{
    struct node *prev;
    int info;
    struct node *next;
};

void showLinkedList(struct node * start,int fromEnd){
    struct node * s = start;
    printf("%s -> ",fromEnd?"END":"START");
    while (s){
        printf("[%d] ",s->info);
        if (fromEnd){
            s = s->prev;
        }else{
            s = s->next;
        }
    }
    printf("-> %s\n",fromEnd?"START":"END");
}

int pushIntoLinkedList(struct DoublelylinkedList *ptrToHead,int info,int insertAtEnd){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = info;
    if (ptrToHead->start == NULL){
        ptrToHead->start = new;
        ptrToHead->end = new;
        new->next = NULL;
        new->prev = NULL;
    }else{
        if (insertAtEnd){
            ptrToHead->end->next = new;
            new->prev = ptrToHead->end;
            new->next = NULL;
            ptrToHead->end = new;
        }else{
            ptrToHead->start->prev = new;
            new->next = ptrToHead->start;
            new->prev = NULL;
            ptrToHead->start = new;
        }
    }
    
}

int main(){
    struct DoublelylinkedList *list = (struct DoublelylinkedList *)malloc(sizeof(struct DoublelylinkedList));
    int n;
    printf("Enter the node of nodes you want : ");
    scanf("%d",&n);
    list->length = n;
    for (int i = 0; i<n ; i++){
        int info; 
        printf("Enter the value at this node : ");
        scanf("%d",&info);
        pushIntoLinkedList(list,info,0);
    }
    showLinkedList(list->start,0);
    showLinkedList(list->end,1);
    return 0;
}