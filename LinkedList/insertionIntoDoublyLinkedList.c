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

void insertIntoDoublyLinkedListByIndex(struct DoublelylinkedList *ptrToHead,int index,int info,int insertAtEnd){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = info;
    ptrToHead->length++;
    struct node *s = (insertAtEnd)?ptrToHead->end:ptrToHead->start;
    if (index){
        while(index-1 && (s != NULL)){
            if (insertAtEnd){
                s=s->prev;
            }else{
                s=s->next;
            }
            index--;
        }
        if (s==NULL){
            printf("Can't insert at that index try something else.\n");
            free(new);
            ptrToHead->length--;
            return;
        }
        if (s->next==NULL || s->prev==NULL) {
            if (insertAtEnd){
                new->prev = NULL;
                new->next = s;
                s->prev = new;
                ptrToHead->start = new;
            }else{
                new->next = NULL;
                new->prev = s;
                s->next = new;
                ptrToHead->end = new;
            }
        }else{
            if (insertAtEnd){
                new->prev = s->prev;
                s->prev->next = new;
                new->next = s;
                s->prev = new;
            }else{
                new->next = s->next;
                new->prev = s;
                s->next = new;
                new->next->prev = new;
            }
        }
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

void InsertIntoDoublyLinkedlistByAdr(struct DoublelylinkedList *ptrToHead,struct node *ptr,int info,int after){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = info;
    struct node *s = ptrToHead->start;
    struct node *e = ptrToHead->end;
    while (s!=ptr && e!=ptr){
        s = s->next;
        e = e->prev;
        if ((s == e && s!=ptr)){
            printf("can't find given address!!\n");
            free(new);
            return;
        }
    }  
    if (s==ptr){
        if (after){
            if (s->next){
                new->next = s->next;
                s->next=new;
                new->prev = s;
                new->next->prev = new;
            }else{
                new->next = NULL;
                s->next=new;
                new->prev = s;
            }
        }else{
            if(s->prev){
                new->prev = s->prev;
                new->next = s;
                s->prev->next = new;
                s->prev = new;
            }
            else{
                new->prev = NULL;
                new->next = s;
                s->prev = new;
            }
        }
    }else{
        if (after){
            if(s->prev){
                new->prev = s->prev;
                new->next = s;
                s->prev->next = new;
                s->prev = new;
            }
            else{
                new->prev = NULL;
                new->next = s;
                s->prev = new;
            }
        }else{
            if (s->next){
                new->next = s->next;
                s->next=new;
                new->prev = s;
                new->next->prev = new;
            }else{
                new->next = NULL;
                s->next=new;
                new->prev = s;
            }
        }
    }
}

void InsertIntoDoublyLinkedListByvalue(struct DoublelylinkedList *ptrToHead,int val,int info,int after){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = info;
    struct node *s = ptrToHead->start;
    struct node *e = ptrToHead->end;
    while (s->info!=val && e->info!=val){
        s = s->next;
        e = e->prev;
        if ((s == e && s->info!=val)){
            printf("can't find given address!!\n");
            free(new);
            return;
        }
    }  
    if (s->info==val){
        if (after){
            if (s->next){
                new->next = s->next;
                s->next=new;
                new->prev = s;
                new->next->prev = new;
            }else{
                new->next = NULL;
                s->next=new;
                new->prev = s;
                ptrToHead->end =new;
            }
        }else{
            if(s->prev){
                new->prev = s->prev;
                new->next = s;
                s->prev->next = new;
                s->prev = new;
            }
            else{
                new->prev = NULL;
                new->next = s;
                s->prev = new;
                ptrToHead->start = new;
            }
        }
    }else{
        if (after){
            if(s->prev){
                new->prev = s->prev;
                new->next = s;
                s->prev->next = new;
                s->prev = new;
            }
            else{
                new->prev = NULL;
                new->next = s;
                s->prev = new;
                ptrToHead->start =new;
            }
        }else{
            if (s->next){
                new->next = s->next;
                s->next=new;
                new->prev = s;
                new->next->prev = new;
            }else{
                new->next = NULL;
                s->next=new;
                new->prev = s;
                ptrToHead->end =new;
            }
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
        break;
        printf("\n");
        int i,j,k;
        printf("enter value to be inserted : ");
        scanf("%d",&i);
        printf("At which index (0-n) : ");
        scanf("%d",&j);
        printf("if insertion should be done from back out 1 : ");
        scanf("%d",&k);
        insertIntoDoublyLinkedListByIndex(list,j,i,k);
        showLinkedList(list->start,0);
        showLinkedList(list->end,1);
    }while(1){
        int i,j,k;
        printf("enter value to be inserted : ");
        scanf("%d",&i);
        printf("At which value : ");
        scanf("%d",&j);
        printf("if insertion should be done from back out 1 : ");
        scanf("%d",&k);
        InsertIntoDoublyLinkedListByvalue(list,j,i,k);
        showLinkedList(list->start,0);
        showLinkedList(list->end,1);
    }
    return 0;
}