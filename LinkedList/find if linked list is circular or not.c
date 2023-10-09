#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *next;
};

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

int main(){
    struct node * start = makeCircularLinkedList(10 ,5);
    
    /*struct node * s = start;
    int count =  20;
    while(count){
        printf("%d\n",s->n);
        s= s->next;
        count--;
    }*/

    struct node * slow = start;
    struct node * fast = start;
    
    while ((slow != NULL) || (fast != NULL)){
        if (slow->next == fast->next){
            printf("Circular\n");
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return 0;
}