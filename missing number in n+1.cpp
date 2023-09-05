#include <iostream>
using namespace std;

int main() {
// input
int arr[]={0,2,1,10,5,3,6,7,8,9};
int length = sizeof(arr)/sizeof(arr[0]);

// soultion to code

int sum = (length*(length+1))/2;
for (int i = 0 ; i < length ; i++)
{
    sum = sum - arr[i];
}
cout<<sum ;
return 0;

}
