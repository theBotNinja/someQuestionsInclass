#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char info;
    struct node *next;
};

struct node *start = NULL;

void push(char val){
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
        char t1 =  temp->info;
        free(temp);
        return t1;
    }else{
        printf("Stack Underflow!!\n");
    }
}

int isnum(char ch){
    if ((int)ch >=48 && (int)ch <=57){
        return 1;
    }
    return 0;
}

int isOp(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

int importants(char ch){
    if (ch == '+' || ch == '-'){
        return 1;
    }else if (ch == '*' || ch == '/' || ch == '%'){
        return 2;
    }else if (ch == '^'){
        return 3;
    }else {
        return -1;
    }
}

int main(){
    char inputExp[100],result[100];
    int j=0;
    push('(');
    printf("enter your expression : ");
    scanf("%s",inputExp);
    for(int i = 0 ; inputExp[i]!='\0' ; i++){
        if (isOp(inputExp[i])){
            while (importants(inputExp[i]) <= importants(start->info)){
                char temp = pop();
                result[j++] = temp;
            }
            push(inputExp[i]);
        }else if(inputExp[i] == '('){
            push('(');
        }else if (inputExp[i] == ')'){
            while(start->info!= '('){
                char temp = pop();
                result[j++] = temp;
            }
            pop();
        }else{
            result[j++] = inputExp[i];
        }
    }
    while (start->next != NULL)
    {
        char temp = pop();
        result[j++] = temp;
    }
    printf("Input expression : %s\n",inputExp);
    printf("Output expression : %s\n",result);

    return 0;
}