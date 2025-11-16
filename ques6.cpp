#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int arr[50];   // array to store heap
    int n;         // number of elements

    // Restore heap upward
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        while (index > 0 && arr[parent] < arr[index]) {
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;

            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Restore heap downward
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            int temp = arr[index];
            arr[index] = arr[largest];
            arr[largest] = temp;

            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() {
        n = 0;
    }

    // Insert element
    void push(int value) {
        arr[n] = value;
        heapifyUp(n);
        n++;
    }

    // Remove highest priority element
    void pop() {
        if (n == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        cout << "Removed: " << arr[0] << endl;

        arr[0] = arr[n - 1];  // move last element to root
        n--;

        heapifyDown(0);
    }

    // Get highest priority element
    int top() {
        if (n == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() {
        return (n == 0);
    }

    void display() {
        cout << "Priority Queue (heap array): ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(50);
    pq.push(30);
    pq.push(20);
    pq.push(40);
    pq.push(70);
    pq.push(60);

    pq.display();

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    pq.display();

    pq.pop();
    pq.display();

    return 0;
}
