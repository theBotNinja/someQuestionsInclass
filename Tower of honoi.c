#include<stdio.h>

void TOH(char S,char I,char D,int n){
    if (n==0){
        return;
    }else{
        TOH(S,D,I,n-1);
        printf("%c -> %c\n",S,D);
        TOH(I,S,D,n-1);
    }
}

int main(){
    TOH('A','B','C',3);
    return 0;
}