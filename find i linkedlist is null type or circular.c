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

struct node * createLinkToLinkedlist(int n ,struct node * start1 ,int atWhatIndex){
    struct node *start = NULL;
    struct node *last = NULL;

    for (int i = 1 ; i<=n ; i++){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->n = i+10;
        if (i==1){
            start = new;
            last = new;
            new->next = NULL;
        }else{
            new-> next = start;
            start = new ;
        }
    }

    struct node * s = start1;

    while(s != NULL){
        if (atWhatIndex == 1){
            last->next=s->next;
            break;
        }
        atWhatIndex--;
        s= s->next;
    }

    
    return start;
}

struct node * findMeetingPoint(struct node * start1 ,struct node * start2){
    int count1 = 0 , count2 = 0;
    struct node *s1 = start1;
    while (s1 != NULL){
        count1++;
        s1 = s1->next;
    }
    struct node *s2 = start2;
     while (s2 != NULL){
        count2++;
        s2 = s2->next;
    }
    s1 = start1;
    s2 = start2;
    if (count1 > count2){
        count1 = count1-count2;
        while (count1)
        {
            s1 = s1->next;
            count1--;
        }
    }else if (count1 < count2){
        count1 = count2 - count1;
        while (count1)
        {
            s2 = s2->next;
            count1--;
        }
    }
    while ((s1 != NULL)||(s2!=NULL))
    {
        if (s1->next==s2->next){
            return s1->next;
        }
        s1 = s1->next;
        s2 = s2->next;
    }
    
}


int main(){
    struct node *start1 = createLinkedList(5);
    struct node *start2 = createLinkToLinkedlist(3,start1,2);
    struct node *found  = findMeetingPoint(start1,start2);

    printf("%d\n",found->n);
    return 0;
}