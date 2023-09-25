#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct linkedList{
    int length;
    struct node *start;
};

struct node * createLinkedList(int n){
    struct node *start = NULL;

    for (int i = 1 ; i<=n ; i++){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->info = i;
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

void showLinkedList(struct linkedList list){
    struct node *s = list.start;
    printf("start[%d] -> ",list.length);
    while (s)
    {
        printf("%d -> ",s->info);
        s = s->next;
    }
    printf("end\n");
}

int main(){
    int n;
    printf("enter the no. of node you want : ");
    scanf("%d",&n);
    struct linkedList list;
    list.length=n;
    list.start=createLinkedList(list.length);
    showLinkedList(list);
    return 0;
}