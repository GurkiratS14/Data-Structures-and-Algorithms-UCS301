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

class BinaryTree {
private:
    Node* root;

    
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        return node;
    }


    bool isBSTUtil(Node* node, int min, int max) {
        if (node == nullptr)
            return true;
        if (node->data <= min || node->data >= max)
            return false;
        return (isBSTUtil(node->left, min, node->data) &&
                isBSTUtil(node->right, node->data, max));
    }


    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BinaryTree() { root = nullptr; }

    
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to check if current tree is BST
    void checkBST() {
        if (isBSTUtil(root, -100000, 100000))
            cout << "The given binary tree IS a BST.\n";
        else
            cout << "The given binary tree is NOT a BST.\n";
    }

    void display() {
        cout << "In-order Traversal: ";
        inorder(root);
        cout << endl;
    }

    
    void createNonBST() {
        root = new Node(10);
        root->left = new Node(5);
        root->right = new Node(8); // violates BST property
    }
};

int main() {
    BinaryTree tree1;
    
    tree1.insert(50);
    tree1.insert(30);
    tree1.insert(70);
    tree1.insert(20);
    tree1.insert(40);
    tree1.insert(60);
    tree1.insert(80);

    tree1.display();
    tree1.checkBST();

    cout << endl;

    
    BinaryTree tree2;
    tree2.createNonBST();
    tree2.display();
    tree2.checkBST();

    return 0;
}
