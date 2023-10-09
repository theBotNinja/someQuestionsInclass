#include <iostream>
using namespace std;
int NsquareMethod (int arr[],int ,int);


int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}


int NsquareMethod(int arr[],int length,int su){
    for (int i = 0 ; i < length ; i++){
        for (int j=0 ; j<length ; j++){
            if ((arr[i]+arr[j]==su)&&(arr[i]!=arr[j])){
                cout<< arr[i] << " & " << arr[j] << endl;
                return 0; 
            }
        }
    }
    printf("can't find such elements");
    return 0;
}
int main(){

    int arr[] = {5,7,10,20,6,4,2};
    int length = sizeof(arr)/sizeof(arr[0]);
    int su ;
    cin >> su ;
    NsquareMethod(arr,length,su);
    quickSort(arr,0,length);
    int low = 0;
    int high = length-1;
    while (low<high){
        if (su == arr[low]+arr[high]){
            cout<< arr[low] << " & " << arr[high] << endl;
            return 0;
        }else if (su > arr[low]+arr[high]){
            low++;
        }else{
            high--;
        }
    }
    return 0;
}