#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size() / 2;
    queue<int> firstHalf;
    for (int i = 0; i < n; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); firstHalf.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    int n, x;
    cout << "Enter number of elements (even): ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) { cin >> x; q.push(x); }

    interleaveQueue(q);
    cout << "Interleaved Queue: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    return 0;
}
