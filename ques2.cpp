#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr={64,34,25,12,22,11,90};
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-i-1;j++){ //important
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"Sorted elements: ";
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}