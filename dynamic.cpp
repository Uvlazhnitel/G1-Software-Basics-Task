#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data; // Data held by the node
    Node* next; // Pointer to the next node in the list
};

// Function to create a new node with given value
Node* createNode(int value) {
    Node* newNode = new Node; // Dynamically allocate memory for a new node
    newNode->data = value; // Set the data of the node
    newNode->next = nullptr; // Initialize the next pointer to nullptr
    return newNode; // Return the newly created node1
}

// Function to insert a node with the given value at the end of the list
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value); // Create a new node with the given value
    if (*head == nullptr) {
        // If the list is empty, make the new node the head of the list
        *head = newNode;
        return;
    }
    // If the list is not empty, traverse to the end of the list
    Node* temp = *head; // Start from the head of the list
    while (temp->next != nullptr) {
        // Keep moving to the next node until reaching the end
        temp = temp->next;
    }
    // At the end, point the last node's next to the new node
    temp->next = newNode;
}

// Function to remove all elements that have the same value as the previous element
void removeDuplicates(Node** head) {
    if (*head == nullptr) return; // If the list is empty, do nothing

    Node* current = *head; // Start with the first node
    while (current->next != nullptr) {
        // While not at the end of the list
        if (current->data == current->next->data) {
            // If current node's value equals the next node's value
            Node* nextNext = current->next->next; // Store the next node's next node
            delete current->next; // Delete the next node
            current->next = nextNext; // Link current node to nextNext
        } else {
            // Move to the next node if no duplicate
            current = current->next;
        }
    }
}

// Function to display the elements of the list
void displayList(Node* head) {
    while (head != nullptr) {
        // Traverse the list and print each node's data
        cout << head->data << " ";
        head = head->next; // Move to the next node
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Initialize the list as empty

    cout << "Enter values for the list (0 to stop): ";
    int value;
    while (true) {
        cin >> value; // Read input from the user
        if (value == 0) break; // Stop input if the user enters 0
        insertEnd(&head, value); // Insert the value at the end of the list
    }

    cout << "Initial list: ";
    displayList(head); // Display the list before removing duplicates

    removeDuplicates(&head); // Remove consecutive duplicates

    cout << "List after removing duplicates: ";
    displayList(head); // Display the list after removing duplicates

    return 0; // End of the program
}
