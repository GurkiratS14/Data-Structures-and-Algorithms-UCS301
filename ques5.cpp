#include<iostream>
using namespace std;

int main(){
    int row,col;
    cout<<"Enter the number of rows in the array: ";
    cin>>row;
    cout<<"Enter the number of coloumns in the array:  ";
    cin>>col;
    int arr[row][col];

    cout<<"Enter the elements in the array: "<<endl;
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            cin>>arr[i][j];
        }
    }

    cout<<"-----------------------------"<<endl;
    cout<<"--- Matrix ---"<<endl;

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<"-----------------------------"<<endl;
    
    int sum=0;

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            sum+=arr[i][j];
        }
        cout<<"Sum of "<<i+1<<" row is: "<<sum<<endl;
        sum=0;
    }

    cout<<"-----------------------------"<<endl;

    for(int i=0;i<col;++i){
        for(int j=0;j<row;++j){
            sum+=arr[j][i];
        }
        cout<<"Sum of "<<i+1<<" coloumn is: "<<sum<<endl;
        sum=0;
    }

    return 0;
}