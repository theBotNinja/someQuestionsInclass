#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int TOP = -1;
char arr[100];

void push(char val){
    if (TOP+1 != sizeof(arr)/sizeof(arr[0])){
        TOP++;
        arr[TOP] = val;
    }else{
        printf("Stack Overflow !!\n");
    }
}

char pop(){
    if (TOP != -1){
        TOP--;
        return (arr[TOP+1]);
    }else{
        printf("Stack Underflow!!\n");
    }
}

void showStack(){
    printf("showing stach : \n");
    for(int i = TOP ; i >=0 ; i--){
        printf("%c\n",arr[i]);
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
            printf("%d %c\n",importants(inputExp[i]),inputExp[i]);
            while (importants(inputExp[i]) <= importants(arr[TOP])){
                char temp = pop();
                result[j++] = temp;
            }
            push(inputExp[i]);
        }else if(inputExp[i] == '('){
            push('(');
        }else if (inputExp[i] == ')'){
            while(arr[TOP]!= '('){
                char temp = pop();
                result[j++] = temp;
            }
            pop();
        }else{
            result[j++] = inputExp[i];
        }
    }
    while (TOP != 0)
    {
        char temp = pop();
        result[j++] = temp;
    }
    printf("Input expression : %s\n",inputExp);
    printf("Output expression : %s\n",result);

    return 0;
}