#pragma once

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
using namespace std;

// Node struct for the Binary Search Tree
struct Node {
    int data;
    Node* leftNext;
    Node* rightNext;

    Node(int value) : data(value), leftNext(nullptr), rightNext(nullptr) {}
};

// ListNode struct for the linked list
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int value) : data(value), next(nullptr) {}
};

// LinkedList struct to store traversal results
struct LinkedList {
    ListNode* head;
    ListNode* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList();
    void add(int value);
    void print() const;
};

// Binary Search Tree class
class BinarySearchTree {
private:
    Node* root;

    Node* insertNode(Node* root, int value);
    void preOrderTraversal(Node* root, LinkedList& result) const;
    void inOrderTraversal(Node* root, LinkedList& result) const;
    void postOrderTraversal(Node* root, LinkedList& result) const;

public:
    BinarySearchTree();
    void insert(int value);
    void buildFromArray(const int* numbers, int size);
    void getPreOrderTraversal(LinkedList& result) const;
    void getInOrderTraversal(LinkedList& result) const;
    void getPostOrderTraversal(LinkedList& result) const;
};

#endif // BINARY_SEARCH_TREE_H