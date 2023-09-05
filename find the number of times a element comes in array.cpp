#include <iostream>
using namespace std;


int binarySearchForFirst(int arr[],int len , int x){
    int lb = 0;
    int ub = len;
    while (lb <= ub){
        int mid = (lb+ub)/2;
        if (arr[mid] == x && arr[mid-1] < x){
            return mid;
        }else if (arr[mid] < x){
            lb=mid;
        }else if(arr[mid] >= x){
            ub=mid;
        }
    }
    return -1;
}

int binarySearchForLast(int arr[],int len , int x){
    int lb = 0;
    int ub = len;
    while (lb <= ub){
        int mid = (lb+ub)/2;
        if (arr[mid] == x && arr[mid+1] > x){
            return mid;
        }else if (arr[mid] <= x){
            lb=mid;
        }else if(arr[mid] > x){
            ub=mid;
        }
    }
    return -1;
}

int main(){

    int arr[] = {1,2,2,2,3,3,4,4,4,4,4,5,5};
    int length = sizeof(arr)/sizeof(arr[0]);

    int x ;
    cin >> x ;
    int first = binarySearchForFirst(arr,length,x);
    int last = binarySearchForLast(arr,length,x);
    printf("%d\n",last-first+1);
    return 0;

}