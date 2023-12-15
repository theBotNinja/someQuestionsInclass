#include<iostream>
using namespace std;

void displayArr(int arr[],int lengthOfArr){
    for (int i = 0; i<lengthOfArr ; i++){
        cout << arr[i] << " ";
    } 
    cout << endl;
}

void insertionSort(int arr[],int length){
    for(int i = 0;i < length;i++){
        int key = arr[i];
        int j = i;
        while (arr[j-1]>key && j>=1) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}


int main(){
    int arr[] = {1,86,7,19,8,64,6,5,41,14,65,41,68};
    int length = sizeof(arr)/sizeof(int);
    displayArr(arr,length);
    insertionSort(arr,length);
    displayArr(arr,length);
    return 0;
}