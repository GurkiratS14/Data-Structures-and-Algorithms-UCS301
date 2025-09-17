#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    int size=str.length();

    cout<<"Reversed string: ";
    for(int i=size-1;i>=0;i--){
        cout<<str[i];
    }
    cout<<endl;

    return 0;
}