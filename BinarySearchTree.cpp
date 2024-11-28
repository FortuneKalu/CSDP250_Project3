#include "binarySearchTree.h"
#include <iostream>
using namespace std;

// LinkedList destructor
LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Add a value to the linked list
void LinkedList::add(int value) {
    ListNode* newNode = new ListNode(value);
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

// Print the linked list
void LinkedList::print() const {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// BinarySearchTree constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Insert a value into the BST
Node* BinarySearchTree::insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->leftNext = insertNode(root->leftNext, value);
    }
    else {
        root->rightNext = insertNode(root->rightNext, value);
    }
    return root;
}

// Public method to insert a value
void BinarySearchTree::insert(int value) {
    root = insertNode(root, value);
}

// Build the tree from an array of numbers
void BinarySearchTree::buildFromArray(const int* numbers, int size) {
    for (int i = 0; i < size; ++i) {
        insert(numbers[i]);
    }
}

// Pre-order traversal
void BinarySearchTree::preOrderTraversal(Node* root, LinkedList& result) const {
    if (root == nullptr) return;
    result.add(root->data);
    preOrderTraversal(root->leftNext, result);
    preOrderTraversal(root->rightNext, result);
}

// In-order traversal
void BinarySearchTree::inOrderTraversal(Node* root, LinkedList& result) const {
    if (root == nullptr) return;
    inOrderTraversal(root->leftNext, result);
    result.add(root->data);
    inOrderTraversal(root->rightNext, result);
}

// Post-order traversal
void BinarySearchTree::postOrderTraversal(Node* root, LinkedList& result) const {
    if (root == nullptr) return;
    postOrderTraversal(root->leftNext, result);
    postOrderTraversal(root->rightNext, result);
    result.add(root->data);
}

// Public methods for traversals
void BinarySearchTree::getPreOrderTraversal(LinkedList& result) const {
    preOrderTraversal(root, result);
}

void BinarySearchTree::getInOrderTraversal(LinkedList& result) const {
    inOrderTraversal(root, result);
}

void BinarySearchTree::getPostOrderTraversal(LinkedList& result) const {
    postOrderTraversal(root, result);
}
