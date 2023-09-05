#include <stdio.h>
#include <string.h>

int main() {
// Write C code here
int b,m,n;
printf("enter m : ");
scanf("%d",&m);

char res[200];
strcpy(res,"Arr");
char res2[200];
strcpy(res2,"= b + W[ ");
char local[50];
printf("S = upper bound - lower bound +1\n");
printf("E = L - t\n");
for (int i = 1,j = m ; i<=m ; i++,j--){
    sprintf(local,"[l%d]",i);
    strcat(res,local);
    if (i==1){
        sprintf(local,"(...(E%d",j);
        strcat(res2,local);
    }else{
    sprintf(local,"S%d + E%d)",j,j);
    strcat(res2,local);
    }
}
printf("%s%s]",res,res2);

return 0;

}