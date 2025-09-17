#include<iostream>
using namespace std;

int main(){
    int arr[10]={1,2,3,4,5,7,8,9,10,11};
    int flag=0;
    int number;
    for(int i=0;i<10;i++){
        if(arr[i]-i !=1){
            number=i+1;
            flag=1;
            break;
        }

    }
    if(flag==0){
        cout<<"No missing number!"<<endl;
    }
    else{
        cout<<"Missing number: "<<number<<endl;
    }

    return 0;
}
