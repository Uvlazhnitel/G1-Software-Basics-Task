#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// Function to remove all elements that have the same value as the previous element
void removeDuplicates(list<int>& myList) {
    if (myList.empty()) return; // If the list is empty, do nothing

    auto it = myList.begin(); // Start from the beginning of the list
    auto nextIt = it; // Create a next iterator
    ++nextIt; // Move nextIt to the second element

    while (nextIt != myList.end()) { // Ensure not at the end of the list
        if (*it == *nextIt) {
            // If current element's value equals the next element's value
            nextIt = myList.erase(nextIt); // Remove the next element and update nextIt
        } else {
            it = nextIt; // Move it to nextIt
            ++nextIt; // Increment nextIt
        }
    }
}

// Function to display the elements of the list
void displayList(const list<int>& myList) {
    for (int num : myList) {
        // Traverse the list and print each element
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    list<int> myList; // Initialize an empty list

    cout << "Enter values for the list (0 to stop): ";
    int value;
    while (true) {
        cin >> value; // Read input from the user
        if (value == 0) break; // Stop input if the user enters 0
        myList.push_back(value); // Insert the value at the end of the list
    }

    cout << "Initial list: ";
    displayList(myList); // Display the list before removing duplicates

    removeDuplicates(myList); // Remove consecutive duplicates

    cout << "List after removing duplicates: ";
    displayList(myList); // Display the list after removing duplicates

    return 0; // End of the program
}
