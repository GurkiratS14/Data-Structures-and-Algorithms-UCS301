#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int cnt=0;
    for(int i=0; i<n; i++) {
        bool flag=false;
        for(int j=0; j<i; j++) {
            if(arr[i]==arr[j]) {
                flag=true; break;
            }
        }
        if(!flag) cnt++;
    }
    return cnt;
}

int main() {
    int arr[]={1,2,2,3,4,1,5};
    int n=7;
    cout<<"Distinct elements = "<<countDistinct(arr,n);
}
