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

    // Recursive insert
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            cout << "Duplicate value ignored: " << value << endl;
        return node;
    }

    // Recursive delete
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr)
            return node;

        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            
            Node* temp = minNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // find min node
    Node* minNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Calculate maximum depth
    int maxDepth(Node* node) {
        if (node == nullptr)
            return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }

    // Calculate minimum depth
    int minDepth(Node* node) {
        if (node == nullptr)
            return 0;

        int leftDepth = minDepth(node->left);
        int rightDepth = minDepth(node->right);

        if (node->left == nullptr)
            return 1 + rightDepth;
        if (node->right == nullptr)
            return 1 + leftDepth;

        return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
    }

    // Display BST in-order
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() { root = nullptr; }

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void display() {
        cout << "BST In-order: ";
        inorder(root);
        cout << endl;
    }

    void printMaxDepth() {
        cout << "Maximum Depth: " << maxDepth(root) << endl;
    }

    void printMinDepth() {
        cout << "Minimum Depth: " << minDepth(root) << endl;
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

    
    cout << "Deleting 20..." << endl;
    tree.deleteValue(20);
    tree.display();

    cout << "Deleting 30..." << endl;
    tree.deleteValue(30);
    tree.display();

    cout << "Deleting 50..." << endl;
    tree.deleteValue(50);
    tree.display();

    
    tree.printMaxDepth();
    tree.printMinDepth();

    return 0;
}
