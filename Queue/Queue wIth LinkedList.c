#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *Front = NULL;
struct node *Rear = NULL;

void Enqueue(int val){
    struct node *new = (struct node *)malloc(sizeof(struct node)); 
    if (new == NULL){
        printf("Overflow !!\n");
        return;
    }
    if (Front == NULL && Rear == NULL){
        Front = new;
        Rear = new;
        new->info = val;
        new->next = NULL;
    }else{
        new->info = val;
        new->next = NULL;
        Rear ->next = new;
        Rear = new;
    }
}

int Dequeue(){
    if (Front == NULL && Rear == NULL){
        printf("Underflow !!\n");
    }else if(Front == Rear){
        int temp = Front->info;
        free(Front);
        Front = NULL;
        Rear = NULL;
        return temp;
    }else{
        struct node  * temp = Front;
        Front = Front->next;
        int t = temp->info;
        free(temp);
        return (t);
    }
}


void showQueue(){
    struct node *s = Front;
    while(s != NULL){
        printf("[ %d ]-> ",s->info);
        s = s->next;
    }
    printf("\n");
}


int main(){
    while (1)
    {
        printf("1.Enqueue\n2.Dequeue\n");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            int ch2;
            printf("enter value to be inserted : ");
            scanf("%d",&ch2);
            Enqueue(ch2);
            showQueue();
            break;

        case 2:
            printf("%d Element removed From queue\n",Dequeue());
            showQueue();
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}
