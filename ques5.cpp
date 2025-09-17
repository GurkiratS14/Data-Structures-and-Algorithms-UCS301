#include <iostream>
#include <queue>
using namespace std;

// (a) Stack using two queues
class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) cout << "Stack empty\n";
        else { cout << q1.front() << " removed\n"; q1.pop(); }
    }
    void top() {
        if (q1.empty()) cout << "Stack empty\n";
        else cout << "Top: " << q1.front() << endl;
    }
};

// (b) Stack using one queue
class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) cout << "Stack empty\n";
        else { cout << q.front() << " removed\n"; q.pop(); }
    }
    void top() {
        if (q.empty()) cout << "Stack empty\n";
        else cout << "Top: " << q.front() << endl;
    }
};

int main() {
    StackTwoQ s1;
    StackOneQ s2;
    int ch, val;
    cout << "Stack using Two Queues:\n";
    s1.push(10); s1.push(20); s1.top(); s1.pop();

    cout << "\nStack using One Queue:\n";
    s2.push(30); s2.push(40); s2.top(); s2.pop();

    return 0;
}
