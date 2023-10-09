#include <iostream>
using namespace std;

int main() {
// input
int arr[]={0,1,2,0,1,0,2,2,2,1,2,1,2,0,1,2,1,0,2,1,2,0,0,1,2};
int n = sizeof(arr)/sizeof(arr[0]);
// soultion to code

int count[]={0,0,0};
for (int i =0 ;i<n ; i++){
    if (arr[i]==1){
        count[1]++;
    }else if (arr[i]==2){
        count[2]++;
    }
}
count[0] = n - (count[1] + count[2]);
for (int i =0 ;i<n ; i++){
    if (count[0]){
        arr[i]=0;
        count[0]--;
    }else if (count[1]){
        arr[i]=1;
        count[1]--;
    }else{
        arr[i]=2;
        count[2]--;
    }
}
cout<<"["<<arr[0];
for (int i =1 ;i<n ; i++){
    cout << ","<< arr[i];
}
cout<<"]\n";
return 0;

}
