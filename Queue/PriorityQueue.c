#include<stdio.h>

int N = 10;
int queueList[10][10];
int FRONT = -1;
int REAR = -1;


void Enqueue(int val,float p){
    //pass
}

int Dequeue(){
    int temp = queueList[FRONT];
    if (FRONT == -1 && REAR == -1){
        printf("UnderFlow !!\n");
    }else if((FRONT+1)%N == REAR){
        FRONT = -1;
        REAR = -1;
        return temp;
    }else{
        FRONT = (FRONT+1)%N;
        return temp;
    }
}

void showQueue(){
    printf("Front : %d Rear : %d\n",FRONT,REAR);
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
