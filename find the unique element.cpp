#include <iostream>
using namespace std;

int bitwiseXOR(int arr[],int length){
    int thenumber = arr[0];
    for (int i = 1 ; i < length ; i++){
        thenumber = thenumber ^ arr[i];
    }
    return thenumber;
}


int main(){
    int arr[] = {2,1,3,2,1,4,4};
    int length  = sizeof(arr)/sizeof(arr[0]);
    
    printf("%d",bitwiseXOR(arr,length));

    return 0;
}
