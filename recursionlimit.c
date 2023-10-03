#include<stdio.h>

void recursivecall(int a){
    printf("%d\n",a);
    recursivecall(a+1);
}

int main(){
    recursivecall(0);
    return 0;
}