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

struct node * makeCircularLinkedList(int n,int repeatFromIndex){
    struct node *start = NULL;
    struct node *last = NULL;
    struct node *repeatFromHere = NULL;
    for (int i = 1 ; i<=n ; i++){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->n = i+10;
        if (i==1){
            start = new;
            last = start;
            new->next = NULL;
        }else{
            new-> next = start;
            start = new ;
        }
        if (repeatFromIndex==0){
            repeatFromHere = start;
        }
        repeatFromIndex--;
    }
    last->next = repeatFromHere;
    return start;
}
struct node * findstart(struct node * start,struct node * slow,struct node * fast){
    struct node * i = start;
    while (i != slow){
        while (slow != fast){
            if (i==slow){
                return i;
            }
            slow = slow->next;
        }
        i =  i->next;
        slow=slow->next;
    }
    return NULL;
}


int main(){
    struct node * start = makeCircularLinkedList(10 ,5);
    

    struct node * s = start;
    int count =  20;
    while(count){
        printf("<%d>",s->n);
        s= s->next;
        count--;
    }
    printf("...\n");

    struct node * slow = start;
    struct node * fast = start;
    struct node * repeatingNode = NULL;
    
    while ((slow != NULL) || (fast != NULL)){
        slow = slow->next;
        fast = fast->next->next;
        if (slow->next == fast->next){
            printf(" The list is circular\n");
            repeatingNode = findstart(start,slow,fast);
            printf("repeating node has value - %d\n",repeatingNode->n);   
            break;
        }
    }
    if (repeatingNode==NULL){
        printf("linked list is linear.\n");
    }
    return 0;
}