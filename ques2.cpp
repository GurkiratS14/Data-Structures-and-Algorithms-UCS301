#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;

        // Find the minimum and maximum in the current range
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;

            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum with left
        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        // If maximum was at left, update its position
        if (maxIndex == left)
            maxIndex = minIndex;

        // Swap maximum with right
        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        // Move inward
        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[50];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
