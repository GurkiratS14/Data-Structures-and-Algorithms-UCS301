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

int deleteKey(int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head; head = head->next;
        delete temp; count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp; count++;
        } else curr = curr->next;
    }
    return count;
}

void display() {
    Node* temp = head;
    while (temp) { cout << temp->data; if(temp->next) cout<<"->"; temp = temp->next; }
    cout << endl;
}

int main() {
    int n, x, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(x); }

    cout << "Enter key to delete: "; cin >> key;
    int cnt = deleteKey(key);

    cout << "Occurrences: " << cnt << endl;
    cout << "Updated List: "; display();
    return 0;
}
