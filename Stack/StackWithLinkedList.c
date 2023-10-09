#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *start = NULL;

void push(int val){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new){
        if (start){
            new->next = start;
            start = new;
        }else{
            start = new;
            new->next = NULL;
        }
        new->info = val;
    }else{
        printf("Stack Overflow !!\n");
    }
}

int pop(){
    if (start){
        struct node *temp = start;
        start = start->next;
        int t1 =  temp->info;
        free(temp);
        return t1;
    }else{
        printf("Stack Underflow!!\n");
    }
}

void showStack(){
    struct node *s =start;
    while(s){
        printf("%d\n",s->info);
        s = s->next;
    }
}

int main(){
    while (1){
        printf("1. Push item into stack\n2.Pop item from stack\n3.show\n4.exit\nenter (1,2,3) >>> ");
        int choice,newsize,value;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the value to inserted : ");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            printf("%d value removed\n",pop());
            break;

        case 3:
            showStack();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("enter only 1 , 2 or 3\n");
            break;
        }
    }
    return 0;
}