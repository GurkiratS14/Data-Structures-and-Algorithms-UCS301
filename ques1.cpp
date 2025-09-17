#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int maxsize;

    public: 
        Stack(int size){
            maxsize=size;
            arr=new int[maxsize];
            top=-1;
        }

        void push(int x){
            if(top==maxsize-1){
                cout<<"Stack overflow!"<<endl;
            }
            else{
                arr[++top]=x;
            }
        }

        void pop(){
            if(top==-1){
                cout<<"Stack underflow!"<<endl;
            }
            else{
                top--;
            }
        }
        void display(){
            if(top==-1){
                cout<<"Stack is empty!"<<endl;
            }
            else{
                for(int i=top;i>=0;i--){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }
        void peek(){
            if(top==-1){
                cout<<"Stack is empty!"<<endl;
            }
            else{
                cout<<"Last element is: "<<arr[top]<<endl;
            }
        }
        bool isEmpty(){
            return(top==-1);
        }
        bool isFull(){
            return (top==maxsize-1);
        }

};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    Stack s(size);
    int choice,val;

    do{
        cout<<"---Menu Driven Program (Stack)---"<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Check if empty"<<endl;
        cout<<"6.Check if full"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        
        switch(choice){
            case 1:
            cout<<"Enter value to push: ";
            cin>>val;
            s.push(val);
            break;

            case 2:
            s.pop();
            break;

            case 3:
            s.peek();
            break;

            case 4:
            s.display();
            break;

            case 5:
            cout<< (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
            break;

            case 6:
            cout << (s.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
            break;


            case 7:
            cout<<"Exiting Program..."<<endl;
            break;

            default:
            cout<<"Invalid choice!"<<endl;
        }
    } while(choice !=7);

    return 0;
}