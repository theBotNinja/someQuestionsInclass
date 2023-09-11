#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node *next;
};

int main(){
    int n = 5;
    struct node *start = NULL;

    for (int i = 1 ; i<n ; i++){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->next = NULL;
        new->num = i;
        if (i==1){
            start = new;
        }else{
            new-> next = start;
            start = new ;
        }
    }
    struct node *s = start;
    while (s!=NULL){
        printf("%d,",s->num);
        s=s->next;
    }
    
    

    return 0;
}