#include <iostream>
#include <vector>
using namespace std;

int findMissingBinary(vector<int>& arr, int n) {
    int st = 0, end = arr.size()-1;
    while(st <= end) {
        int mid = (st+end)/2;
        
        
        if(arr[mid] == mid+1) {
            st = mid+1;
        } 
        else {
            
            end = mid-1;
        }
    }
    return st+1; 
}

int main() {
    vector<int> arr = {1,2,3,4,6,7,8}; // missing 5
    int n = 8; 
    cout << "Missing number: " << findMissingBinary(arr,n) << endl;
}
