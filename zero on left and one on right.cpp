#include <iostream>
using namespace std;

int main() {

int arr[] = {0,1,0,1,1,0,1,0,1,1,1,0,0,0,1,1,0,1,1,0};
int length = sizeof(arr)/sizeof(arr[0]),count = 0;
// Write C code here

int left = 0;
int right = length -1;

while (left < right){
    if ((arr[left]==1)&&(arr[right]==0)){
        arr[right]=arr[left];
        arr[left]=0;
        right--;
    }else if (arr[left]==arr[right]==1){
        left++;
    }else if (arr[left]==arr[right]==0){
        right--;
    }
    else{
        left++;
    }
    count++;
}


for (int i = 0 ; i < length ; i++){
    cout<<arr[i]<<",";
}
cout<<"\n"<<count<<"\n"<<length;
return 0;

}
