#include<stdio.h>
#include<stdlib.h>

struct  node
{
    int power;
    int coeff;
    struct node *next;
};

int pushIntoLinkedList(struct node **ptrToLinkedListStart , int coeff , int power){
    struct node *s = *ptrToLinkedListStart;
    struct node *prev = NULL;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->coeff=coeff;
    new->power=power;
    while (s){
        if (prev){
            if (s->power > power){
                new->next = s;
                prev->next = new;
                return 0;
            }
            prev = s;
        }else{
            if (s->power > power){
                new->next = *ptrToLinkedListStart;
                *ptrToLinkedListStart = new;
                return 0;
            }
            prev = s;
        }
        s = s->next;
    }
    if (prev){
        prev->next = new;
        new->next = NULL;
    }else{
        new->next = *ptrToLinkedListStart;
        *ptrToLinkedListStart = new;
    }
    return 0;
}

void normalPush(struct node **ptrstart,int c,int p){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->coeff=c;
    new->power=p;
    new->next = *ptrstart;
    *ptrstart =  new;
}

struct node *ployAdder(struct node *ploy1,struct node *ploy2){
    struct node * newlist = NULL;
    while (ploy1 != NULL && ploy2 != NULL){
        if (ploy1->power == ploy2->power){
            normalPush(&newlist,ploy1->coeff+ploy2->coeff,ploy1->power);
            ploy1 = ploy1->next;
            ploy2 = ploy2->next;
        }else if(ploy1->power > ploy2->power){
            normalPush(&newlist,ploy2->coeff,ploy2->power);
            ploy2 = ploy2->next;
        }else{
            normalPush(&newlist,ploy1->coeff,ploy1->power);
            ploy1 = ploy1->next;
        }
    }
    if (ploy1 == NULL){
        while(ploy2){
            normalPush(&newlist,ploy2->coeff,ploy2->power);
            ploy2 = ploy2->next;
        }
    }else{
        while(ploy1){
            normalPush(&newlist,ploy1->coeff,ploy1->power);
            ploy1 = ploy1->next;
        }
    }
    return newlist;
}

void showPoly(struct node * start){
    struct node * s = start;
    while (s){
        printf(" %dx^(%d)",s->coeff,s->power);
        if (s->next != NULL){
            printf(" + ");
        }
        s=s->next;
    }
    printf(" = 0\n");
}

int main(){
    int n;
    printf("how many terms your first ploynomial has : ");
    scanf("%d",&n);
    struct node *PolyStart1 = NULL;
    for (int i = 0 ; i < n ; i++){
        int power,coeff;
        printf("enter the coeff and power in respective order : ");
        scanf("%d %d",&coeff,&power);
        pushIntoLinkedList(&PolyStart1,coeff,power);
    }
    printf("how many terms your Second ploynomial has : ");
    scanf("%d",&n);
    struct node *PolyStart2 = NULL;
    for (int i = 0 ; i < n ; i++){
        int power,coeff;
        printf("enter the coeff and power in respective order : ");
        scanf("%d %d",&coeff,&power);
        pushIntoLinkedList(&PolyStart2,coeff,power);
    }
    showPoly(PolyStart1);
    showPoly(PolyStart2);
    showPoly(ployAdder(PolyStart1,PolyStart2));   
    return 0;
}