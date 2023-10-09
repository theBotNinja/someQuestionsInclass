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

struct node * createLinkedList(int n,struct node ** addr){
    struct node *start = NULL;

    for (int i = 1 ; i<=n ; i++){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->n = i;
        if (i==1){
            start = new;
            *addr = new;
            new->next = NULL;
        }else{
            new-> next = start;
            start = new ;
        }
    }
    return start;
}

int deleteByAddr(struct node ** ptr_start , struct node * addr){
    struct node * s = *ptr_start;
    while (s != NULL)
    {   
        if (s==*ptr_start){
            if (s == addr){
                *ptr_start = s->next;
                free(s);
                return 1;
            }else if (s->next == addr){
                s->next = s->next->next;
                free(addr);
                return 1;
            }
        }else if (s->next == addr)
        {
            s->next = s->next->next;
            free(addr);
            return 1;
        }
        s = s->next;
    }
    return 0;
}

int deleteByValue(struct node ** ptr_start , int value){
    struct node * s = *ptr_start;
    struct node * prev = NULL;
    while (s != NULL)
    {   
        if (s->n == value){
            if (prev){
                prev->next = s->next;
                free(s);
                return 1;
            }else{
                *ptr_start = s->next;
                free(s);
                return 1;
            }
        }else{
            prev = s;
        }
        s = s->next;
    }
    return 0;
}


int deleteByIndex(struct node ** ptr_start , int index){
    struct node * s = *ptr_start;
    struct node * addr;
    while (s != NULL)
    {   
        if (index == 0){
            *ptr_start = s->next;
            free(s);
            return 1;
        }else if (index == 1 && s->next != NULL )
        {
            addr = s->next; 
            s->next = s->next->next;
            free(addr);
            return 1;
        }
        index--;
        printf("%d\n",index);
        s = s->next;
    }
    return 0;
}

int main(){
    struct node * addr,*temp;
    struct node * LinkedListStart = createLinkedList(10,&addr);

    //int result = deleteByAddr(&LinkedListStart,temp);
    int result = deleteByValue(&LinkedListStart,11);
    //int x;
    //scanf("%d",&x);
    //int result = deleteByIndex(&LinkedListStart,x);
    printf("%s",result?"deleted successfully!\n":"Can't find the addr in linked list !!\n");
    showLinkedList(LinkedListStart);

    return 0 ;
}