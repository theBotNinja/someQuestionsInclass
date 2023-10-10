#include<stdio.h>
#include<stdlib.h>

int Qlist[10];
int QLength = 10;
int Front1 = -1;
int Rear1 = -1;
int Front2 = -1;
int Rear2 = -1;

void showQueue(){
    int len = sizeof(Qlist)/sizeof(Qlist[0]);
    for (int i = 0 ; i < len ; i++){
        printf(" %d ,",Qlist[i]);
    }
    printf("\n");
}

void Enqueue1(int val){
    if (Front1 == -1 && Rear1 == -1){
        Front1++;
        Rear1++;
        Qlist[Front1] = val;
    }else if(Rear1+1 == Rear2){
        printf("Queue Overflow!!\n");
    }else{
        Rear1++;
        Qlist[Rear1] = val;
    }
}

int Dequeue1(){
     if (Front1 == -1 && Rear1 == -1){
        printf("Underflow !!\n");
    }else if(Front1 == Rear1){
        Front1 = Rear1 = -1;
    }else{
        for (int  i = 0; i < Rear1; i++)
        {
            Qlist[i] = Qlist[i+1];
        }
        Rear1--;
    }
}

void Enqueue2(int val){
    if (Front2 == -1 && Rear2 == -1){
        Front2 = QLength-1;
        Rear2 = QLength-1;
        Qlist[Front2] = val;
    }else if(Rear2 -1 == Rear1){
        printf("Queue Overflow!!\n");
    }else{
        Rear2--;
        Qlist[Rear2] = val;
    }
}

int Dequeue2(){
     if (Front2 == -1 && Rear2 == -1){
        printf("Underflow !!\n");
    }else if(Front2 == Rear2){
        Front2 = Rear2 = -1;
    }else{
        for (int  i = Front2; i > Rear1; i--)
        {
            Qlist[i] = Qlist[i-1];
        }
        Rear2++;
    }
}

int main(){
    while (1){
        int choice,temp;
        printf("Enter the name : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf(">>>");
            scanf("%d",&temp);
            Enqueue1(temp);
            showQueue();
            break;
        
        case 2:
            printf(">>>");
            scanf("%d",&temp);
            Enqueue2(temp);
            showQueue();
            break;
        
        case 3:
            Dequeue1();
            showQueue();
            break;
        
        case 4:
            Dequeue2();
            showQueue();
            break;
        
        default:
            printf("1,2,3,4\nthat it \n");
            break;
        }
    }
    return 0;
}