#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "binarySearchTree.h"

using namespace std;

// Function to generate unique random numbers
void generateUniqueRandomNumbers(vector<int>& numbers, int count) {
    bool used[100] = { false }; // Array to track used numbers
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < count; ) {
        int num = rand() % 100; // Generate a random number in the range [0, 99]
        if (!used[num]) { // Check if the number has been used
            numbers[i++] = num; // Add the number to the vector
            used[num] = true;    // Mark the number as used
        }
    }
}

// Function to print the generated numbers
void printArray(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    int numCount = 35;

    // Step 1: Get user input for the number of unique random numbers
    do {
        cout << "Enter the number of unique random numbers to generate (between 35 and 100): ";
        cin >> numCount;
        if (numCount < 35 || numCount > 100) {
            cout << "Invalid input. Please enter a number between 35 and 100." << endl;
        }
    } while (numCount < 35 || numCount > 100);

    // Use a vector to dynamically allocate memory for the numbers
    vector<int> numbers(numCount);  // Create a vector of size numCount

    generateUniqueRandomNumbers(numbers, numCount);
    cout << "Generated Numbers, Original Order: \n";
    printArray(numbers); cout << endl;

    // Step 2: Build the Binary Search Tree
    BinarySearchTree bst;
    cout << "Constructing Binary Search Tree...\n";
    bst.buildFromArray(numbers.data(), numCount);  // Use .data() to pass a raw pointer to the array
    cout << "Binary Search Tree Construction Complete.\n";

    // Step 3: Perform and display traversals
    LinkedList preOrder, inOrder, postOrder;
    bst.getPreOrderTraversal(preOrder);
    bst.getInOrderTraversal(inOrder);
    bst.getPostOrderTraversal(postOrder);

    cout << "Pre-order Traversal: \n";
    preOrder.print(); cout << endl;

    cout << "In-order Traversal: \n";
    inOrder.print(); cout << endl;

    cout << "Post-order Traversal: \n";
    postOrder.print(); cout << endl;

    return 0;
}
