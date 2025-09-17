#include<iostream>
#include<string>
using namespace std;

class Stack{
    char arr[100];
    int top;
    

    public:
        Stack(){
            top=-1;
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
            return (top==99);
        }
        void push(char c){
            if(top==99){
                cout<<"Stack is overflow!"<<endl;
            }
            else{
                arr[++top]=c;
            }
        }
        char pop(){
            if(top==-1){
                cout<<"Stack underflow!"<<endl;
                return '\0';
            }
            else{
                return arr[top--];
            }
        }
       
};

int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    Stack s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    
    string reversed="";
    while(!s.isEmpty()){
        reversed +=s.pop();

    }
    cout<<"Reversed String: "<<reversed<<endl;
    return 0;
}
