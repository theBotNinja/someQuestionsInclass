#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
// Write C code here
char *words[] ={ "zero", "one", "two", "three", "four","five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *thplace[] = {"twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety","hundred", "thousand"};
int number,counter,newnum;
char res[100];
scanf("%d",&number);
if (number){
printf("%s",words[number]);
return 0;
}
counter = 0;
int digit ,temp;
char local[100];
for (int i = number ; i ; i=i/10){
counter++;
digit = i % 10 ;
if (counter){
strcpy(res,words[digit]);
}else if (counter==2 && digit == 1){
strcpy(res,words[10+temp]);
}else if (counter == 2){
if ((temp != 0)&&(digit!=0)){
strcpy(local,res);
strcpy(res,thplace[digit-2]);
strcat(res,local);
}
else if (digit!=0){
strcpy(res,thplace[digit-2]);
}
}else if (counter == 3){
if (digit !=0){
strcpy(local,res);
strcpy(res,words[digit]);
strcat(res, " hundred ");
if (local[0] != 'z'){
strcat(res,local);
}
}
}else if (counter ==4){
strcpy(local,res);
strcpy(res,words[digit]);
strcat(res, " thousand ");
strcat(res,local);
}else if (counter == 5 && digit == 1){
printf("\n%s\n",local);
strcpy(res,words[10+temp]);
strcat(res, " thousand ");
strcat(res,local);
}else if (counter == 5){
if ((temp != 0)&&(digit!=0)){
strcpy(local,res);
strcpy(res,thplace[digit-2]);
strcat(res,local);
}
else if (digit!=0){
strcpy(res,thplace[digit-2]);
}
}
temp = digit;
}
printf("%s",res);
return 0;
}
