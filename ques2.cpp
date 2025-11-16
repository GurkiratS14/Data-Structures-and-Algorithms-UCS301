#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Recursive insertion
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
    
        return node;
    }

    // Recursive search
    Node* searchRecursive(Node* node, int key) {
        if (node == nullptr || node->data == key)
            return node;

        if (key < node->data)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }

    // Find minimum node
    Node* minNode(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Find maximum node
    Node* maxNode(Node* node) {
        while (node && node->right != nullptr)
            node = node->right;
        return node;
    }

public:
    BST() { root = nullptr; }

    void insert(int value) {
        root = insert(root, value);
    }

    // Recursive search
    void searchRecursive(int key) {
        Node* result = searchRecursive(root, key);
        if (result)
            cout << key << " found (recursive search)\n";
        else
            cout << key << " not found (recursive search)\n";
    }

    // Non-recursive search
    void searchNonRecursive(int key) {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->data) {
                cout << key << " found (non-recursive search)\n";
                return;
            }
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        cout << key << " not found (non-recursive search)\n";
    }

    // Minimum element
    void findMin() {
        Node* node = minNode(root);
        if (node)
            cout << "Minimum element: " << node->data << endl;
    }

    // Maximum element
    void findMax() {
        Node* node = maxNode(root);
        if (node)
            cout << "Maximum element: " << node->data << endl;
    }

    // In-order successor
    void inorderSuccessor(int key) {
        Node* current = root;
        Node* successor = nullptr;
        while (current != nullptr) {
            if (key < current->data) {
                successor = current;
                current = current->left;
            } else if (key > current->data) {
                current = current->right;
            } else {
                if (current->right != nullptr)
                    successor = minNode(current->right);
                break;
            }
        }
        if (successor)
            cout << "In-order successor of " << key << " is " << successor->data << endl;
        else
            cout << "No successor found for " << key << endl;
    }

    // In-order predecessor
    void inorderPredecessor(int key) {
        Node* current = root;
        Node* predecessor = nullptr;
        while (current != nullptr) {
            if (key > current->data) {
                predecessor = current;
                current = current->right;
            } else if (key < current->data) {
                current = current->left;
            } else {
                if (current->left != nullptr)
                    predecessor = maxNode(current->left);
                break;
            }
        }
        if (predecessor)
            cout << "In-order predecessor of " << key << " is " << predecessor->data << endl;
        else
            cout << "No predecessor found for " << key << endl;
    }

    // Display BST (In-order)
    void inorderDisplay(Node* node) {
        if (node == nullptr) return;
        inorderDisplay(node->left);
        cout << node->data << " ";
        inorderDisplay(node->right);
    }

    void display() {
        cout << "BST In-order: ";
        inorderDisplay(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.display();

    tree.searchRecursive(40);
    tree.searchNonRecursive(25);

    tree.findMin();
    tree.findMax();

    tree.inorderSuccessor(40);
    tree.inorderPredecessor(60);

    return 0;
}
