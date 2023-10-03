#include<stdio.h>
#include<stdlib.h>

int TOP = -1;
int arr[5];

void push(int val){
    if (TOP+1 != sizeof(arr)/sizeof(arr[0])){
        TOP++;
        arr[TOP] = val;
    }else{
        printf("Stack Overflow !!\n");
    }
}

int pop(){
    if (TOP != -1){
        TOP--;
        return (arr[TOP+1]);
    }else{
        printf("Stack Underflow!!\n");
    }
}

void showStack(){
    for(int i = TOP ; i >=0 ; i--){
        printf("%d\n",arr[i]);
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