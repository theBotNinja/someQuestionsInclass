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

void deletionByValue(struct DoublelylinkedList * ptrToHead,int val){
    struct node *s = ptrToHead->start;
    struct node *e = ptrToHead->end;
    ptrToHead->length--;
    if(s==NULL && e == NULL){
        printf("can't perform this opration!");
        ptrToHead->length++;
        return;
    }
    while (s->info != val && e->info != val){
        s = s->next;
        e = e->prev;
        if ((s == e && s->info!=val)){
            printf("can't find given value!!\n");
            ptrToHead->length++;
            return;
        }
    }
    if (s->info==val){
        if (s->next!=NULL && s->prev==NULL){
            s=s->next;
            ptrToHead->start = s;
            free(s->prev);
            s->prev = NULL;
        }else if (s->next==NULL && s->prev==NULL){
            ptrToHead->start = NULL;
            ptrToHead->end = NULL;
            free(s);
        }else{
            s->prev->next = s->next;
            s->next->prev = s->prev;
            free(s);
        }
    }else{
        if (e->next == NULL && e->prev!=NULL){
            e = e->prev;
            ptrToHead->end = e;
            free(e->next);
            e->next=NULL;
        }else{
            e->prev->next = e->next;
            e->next->prev = e->prev;
            free(e);
        }
    }
}


void deletionByAdr(struct DoublelylinkedList * ptrToHead,struct node *ptr){
    struct node *s = ptrToHead->start;
    struct node *e = ptrToHead->end;
    ptrToHead->length--;
    if(s==NULL && e == NULL){
        printf("can't perform this opration!");
        ptrToHead->length++;
        return;
    }
    while (s != ptr && e != ptr){
        s = s->next;
        e = e->prev;
        if ((s == e && s!=ptr)){
            printf("can't find given value!!\n");
            ptrToHead->length++;
            return;
        }
    }
    if (s==ptr){
        if (s->next!=NULL && s->prev==NULL){
            s=s->next;
            ptrToHead->start = s;
            free(s->prev);
            s->prev = NULL;
        }else if (s->next==NULL && s->prev==NULL){
            ptrToHead->start = NULL;
            ptrToHead->end = NULL;
            free(s);
        }else{
            s->prev->next = s->next;
            s->next->prev = s->prev;
            free(s);
        }
    }else{
        if (e->next == NULL && e->prev!=NULL){
            e = e->prev;
            ptrToHead->end = e;
            free(e->next);
            e->next=NULL;
        }else{
            e->prev->next = e->next;
            e->next->prev = e->prev;
            free(e);
        }
    }
}

void deletionByIndex(struct DoublelylinkedList * ptrToHead,int index,int fromEnd){
    struct node *s = ptrToHead->start;
    struct node *e = ptrToHead->end;
    ptrToHead->length--;
    if (s==NULL && e==NULL)
    {
        printf("list has no elements!!");
        ptrToHead->length++;
        return;
    }
    if (index==0){
        if (fromEnd){
        if (e->next == NULL && e->prev!=NULL){
            e = e->prev;
            ptrToHead->end = e;
            free(e->next);
            e->next=NULL;
        }else if (e->next==NULL && e->prev==NULL){
            ptrToHead->start = NULL;
            ptrToHead->end = NULL;
            free(e);
        }
    }else{
        if (s->next!=NULL && s->prev==NULL){
            s=s->next;
            ptrToHead->start = s;
            free(s->prev);
            s->prev = NULL;
        }else if (s->next==NULL && s->prev==NULL){
            ptrToHead->start = NULL;
            ptrToHead->end = NULL;
            free(s);
        }
    }
        return;
    }
    while(index){
        if(fromEnd){
            e =e->prev;
        }else{
            s =s->next;
        }
        if (s == NULL || e == NULL){
            printf("can't work with that index!!");
            ptrToHead->length++;
            return;
        }
        index--;
    }
    if (fromEnd){
        if (e->next != NULL && e->prev==NULL){
            e = e->next;
            ptrToHead->start = e;
            free(e->prev);
            e->prev=NULL;
        }else{
            e->prev->next = e->next;
            e->next->prev = e->prev;
            free(e);
        }
    }else{
        if (s->next==NULL && s->prev!=NULL){
            s= s->prev;
            ptrToHead->end = s;
            free(s->next);
            s->next = NULL;
        }else{
            s->prev->next = s->next;
            s->next->prev = s->prev;
            free(s);
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
    while(1){
        /*int x;
        printf("enter the value : ");
        scanf("%d",&x);
        deletionByValue(list,x);*/
        //deletionByAdr(list,list->start);
        int x,y;
        printf("enter the value : ");
        scanf("%d",&x);
        printf("enter the fromend : ");
        scanf("%d",&y);
        deletionByIndex(list,x,y);
        showLinkedList(list->start,0);
        showLinkedList(list->end,1);
    }
    return 0;
}