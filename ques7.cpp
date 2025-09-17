#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    vector<int>A(n);
    cout<<"Enter the elements in array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];

    }
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
                count++;
            }
        }
    }
    cout<<"Total inversions: "<<count<<endl;

    return 0;

}