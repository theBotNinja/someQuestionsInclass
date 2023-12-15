#include<iostream>
using namespace std;

void BubbleSort(int arr[],int lengthOfArr){
    for (int i = 0; i < lengthOfArr ;i++){
        for(int j = 0;j<=lengthOfArr-i;j++){
            if(arr[i]<arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void displayArr(int arr[],int lengthOfArr){
    for (int i = 0; i<lengthOfArr ; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
}

int main(){
    int IntArray[] = {1,731,35,10,41,531,53,10,51};
    int lengthOfArr = sizeof(IntArray)/sizeof(int);
    displayArr(IntArray,lengthOfArr);
    BubbleSort(IntArray,lengthOfArr);
    displayArr(IntArray,lengthOfArr);
    return 0;
}