#include<iostream>
using namespace std;

int main(){
    int arr[]={5,1,4,2,3};
    int n=sizeof(arr)/4;
    // Insertion Sort
    for(int i=0;i<n-1;i++){ // no of passes
        int j=i+1;
        while(j>=1 && arr[j]<arr[j-1]){

        swap(arr[j],arr[j-1]);
        j--;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}