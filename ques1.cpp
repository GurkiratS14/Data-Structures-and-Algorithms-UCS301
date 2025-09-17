#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr,int tar){
    int st=0; int end=arr.size()-1;

    while(st<=end){
        int mid=st+(end-st)/2; // optimation; to prevent overflow

        if(tar>arr[mid]){
            st=st+1;
        }
        else if(tar<arr[mid]){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int>arr1={-1,0,3,4,5,9,12};
    int tar1=12;

    cout<<"Index at element found: "<<binarySearch(arr1,tar1)<<endl;

    

    return 0;


}