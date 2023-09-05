#include<stdio.h>
struct node
{
    int n;
    struct node *next;
};

int main(){
    struct node p1,p2,p3;

    p1.n = 2;    
    p2.n = 3;
    p3.n = 4;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = NULL;

    struct node *start = &p1;
    struct node *s = start;

    while (s!=NULL){
        printf("%d\n",s->n);
        s = s->next;
    }
    return 0;
}