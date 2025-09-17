#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
    int arr[SIZE], front, rear, count;
public:
    CircularQueue() { front = 0; rear = -1; count = 0; }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == SIZE; }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is Full!\n";
        else {
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
            count++;
            cout << x << " inserted.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is Empty!\n";
        else {
            cout << arr[front] << " removed.\n";
            front = (front + 1) % SIZE;
            count--;
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
            for (int i = 0; i < count; i++)
                cout << arr[(front + i) % SIZE] << " ";
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int ch, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cq.peek(); break;
            case 4: cq.display(); break;
        }
    } while (ch != 5);
    return 0;
}
