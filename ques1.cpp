#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insertAtBeginning(int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = new Node{val, NULL};
    if (head == NULL) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void insertAfterValue(int val, int afterVal) {
    Node* temp = head;
    while (temp && temp->data != afterVal) temp = temp->next;
    if (!temp) cout << "Value " << afterVal << " not found.\n";
    else {
        Node* newNode = new Node{val, temp->next};
        temp->next = newNode;
    }
}

void deleteAtBeginning() {
    if (!head) cout << "List empty.\n";
    else {
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }
}

void deleteAtEnd() {
    if (!head) cout << "List empty.\n";
    else if (!head->next) {
        cout << "Deleted: " << head->data << endl;
        delete head; head = NULL;
    }
    else {
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        cout << "Deleted: " << temp->next->data << endl;
        delete temp->next;
        temp->next = NULL;
    }
}

void deleteSpecific(int val) {
    if (!head) { cout << "List empty.\n"; return; }
    if (head->data == val) {
        Node* temp = head; head = head->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp; return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) cout << "Value not found.\n";
    else {
        Node* del = temp->next;
        temp->next = del->next;
        cout << "Deleted: " << del->data << endl;
        delete del;
    }
}

void searchNode(int val) {
    Node* temp = head; int pos = 1;
    while (temp) {
        if (temp->data == val) { cout << "Found at position " << pos << endl; return; }
        temp = temp->next; pos++;
    }
    cout << "Not found.\n";
}

void display() {
    if (!head) { cout << "List empty.\n"; return; }
    Node* temp = head;
    cout << "List: ";
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    int ch, val, afterVal;
    do {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertAfter 4.DelBeg 5.DelEnd 6.DelSpecific 7.Search 8.Display 9.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
            case 3: cout << "Enter value and after which value: "; cin >> val >> afterVal; insertAfterValue(val, afterVal); break;
            case 4: deleteAtBeginning(); break;
            case 5: deleteAtEnd(); break;
            case 6: cout << "Enter value to delete: "; cin >> val; deleteSpecific(val); break;
            case 7: cout << "Enter value to search: "; cin >> val; searchNode(val); break;
            case 8: display(); break;
        }
    } while (ch != 9);
    return 0;
}
