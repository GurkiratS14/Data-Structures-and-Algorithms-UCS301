#include <iostream>
using namespace std;

class HeapSort {
private:
    int arr[50];     
    int n;          

  
    void heapifyMax(int arr[], int n, int i) {
        int largest = i;           // root
        int left = 2 * i + 1;      // left child
        int right = 2 * i + 2;     // right child

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapifyMax(arr, n, largest);
        }
    }

   
    void heapifyMin(int arr[], int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            heapifyMin(arr, n, smallest);
        }
    }

public:
    HeapSort() {
        n = 0;
    }

    void input() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

   
    void sortIncreasing() {
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyMax(arr, n, i);

        // Extract elements one by one
        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapifyMax(arr, i, 0);
        }
    }

    
    void sortDecreasing() {
        // Build min heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyMin(arr, n, i);

        // Extract elements one by one
        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapifyMin(arr, i, 0);
        }
    }

    void display() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    HeapSort h;
    h.input();

    cout << "\nOriginal array: ";
    h.display();

    h.sortIncreasing();
    cout << "Sorted in Increasing order: ";
    h.display();

    h.sortDecreasing();
    cout << "Sorted in Decreasing order: ";
    h.display();

    return 0;
}
