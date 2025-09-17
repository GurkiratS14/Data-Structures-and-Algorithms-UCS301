#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node{val, NULL};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    Node* temp = head;
    while (temp) { cout << temp->data; if(temp->next) cout<<"->"; temp = temp->next; }
    cout << "->NULL" << endl;
}

int main() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(x); }

    cout << "Original List: "; display();
    reverseList();
    cout << "Reversed List: "; display();
    return 0;
}
