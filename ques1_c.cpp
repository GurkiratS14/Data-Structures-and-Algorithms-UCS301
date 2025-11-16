#include<iostream>
using namespace std;

int main(){
    int arr[]={5,1,4,2,3};
    int n=sizeof(arr)/4;
    // Bubble sort Optimize
    for(int i=0;i<n-1;i++){ // no of passes
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag==true) break; // for already sorted array
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
