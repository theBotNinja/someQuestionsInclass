#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int info;
    struct node *next;
};

struct node *START = NULL;

void push(int val){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new){
        if (START){
            new->next = START;
            START = new;
        }else{
            START = new;
            new->next = NULL;
        }
        new->info = val;
    }else{
        printf("Stack Overflow !!\n");
        exit(1);
    }
}

int pop(){
    if (START){
        struct node *temp = START;
        START = START->next;
        int t1 =  temp->info;
        free(temp);
        return t1;
    }else{
        printf("Stack Underflow!!\n");
        exit(1);
    }
}

void emptyStack(){
    struct node *s;
    while(START){
        s =START;
        START = START->next;
        free(s);
    }
}

void showStack(){
    printf("<Stack Below>\n");
    struct node *s =START;
    while(s){
        printf("%d\n",s->info);
        s = s->next;
    }
}

int isnum(char ch){
    if ((int)ch >=48 && (int)ch <=57){
        return 1;
    }
    return 0;
}

int charToNum(char ch){
    switch ((int)ch)
    {
    case 48:
        return 0;
        break;
    
    case 49:
        return 1;
        break;
    
    case 50:
        return 2;
        break;
    
    case 51:
        return 3;
        break;
    
    case 52:
        return 4;
        break;
    
    case 53:
        return 5;
        break;
    
    case 54:
        return 6;
        break;
    
    case 55:
        return 7;
        break;
    
    case 56:
        return 8;
        break;
    
    case 57:
        return 9;
        break;
    default:
        return -1;
        break;
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

char *InfixToPostfix(char *inputExp,char * result){
    int j=0;
    push('(');
    for(int i = 0 ; inputExp[i]!='\0' ; i++){
        if (isOp(inputExp[i])){
            while (importants(inputExp[i]) <= importants(START->info)){
                char temp = pop();
                result[j++] = temp;
            }
            push(inputExp[i]);
        }else if(inputExp[i] == '('){
            push('(');
        }else if (inputExp[i] == ')'){
            while(START->info!= '('){
                char temp = pop();
                result[j++] = temp;
            }
            pop();
        }else{
            result[j++] = inputExp[i];
        }
    }
    while (START->next != NULL)
    {
        char temp = pop();
        result[j++] = temp;
    }
    return result;
}

int calculateUsingStack(char *postfixExp){
    emptyStack();
    for (int i = 0 ; postfixExp[i] != '\0' ; i++){
        if (isnum(postfixExp[i])){
            push(charToNum(postfixExp[i]));
        }else if (isOp(postfixExp[i])){
            int b = pop();
            int a = pop();
            switch (postfixExp[i])
            {
            case '+':
                push(a+b);
                break;

            case '-':
                push(a-b);
                break;
            
            case '*':
                push(a*b);
                break;
            
            case '/':
                push(a/b);
                break;

            case '%':
                push(a%b);
                break;
            
            default:
                break;
            }
        }
        showStack();
    }
    return pop();
    
}

int main(){
    char inputFromUser[100],result[100];
    printf("enter your expression : ");
    scanf("%s",inputFromUser);
    InfixToPostfix(inputFromUser,result);
    printf("Output Expression : %s\n",result);
    printf("Answer to expression is : %d\n",calculateUsingStack(result));
    return 0;
}