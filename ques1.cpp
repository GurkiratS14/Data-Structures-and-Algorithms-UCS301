#include <iostream>
using namespace std;
#define SIZE 100

class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return (front == -1); }
    bool isFull() { return (rear == SIZE - 1); }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full!\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
            cout << x << " inserted.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty!\n";
        else {
            cout << arr[front] << " removed.\n";
            if (front == rear) front = rear = -1;
            else front++;
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue is Empty!\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue is Empty!\n";
        else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int ch, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    } while (ch != 5);
    return 0;
}
