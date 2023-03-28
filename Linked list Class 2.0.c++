#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked list class
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    // Insert node at the end of the list
    void insertNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete node with the given data
    void deleteNode(int data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Print all nodes in the list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Search for node with the given data
    Node* searchNode(int data) {
        Node* current = head;
        while (current != nullptr && current->data != data) {
            current = current->next;
        }
        return current;
    }

    // Sort the list in ascending order using bubble sort
    void sortList() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    swapNodes(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

private:
    Node* head;

    // Swap two nodes
    void swapNodes(Node* node1, Node* node2) {
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
};

// Example usage
int main() {
    LinkedList myList;
    myList.insertNode(5);
    myList.insertNode(2);
    myList.insertNode(8);
    myList.insertNode(1);
    myList.insertNode(7);
    myList.printList();  // Output: 5 2 8 1 7

    myList.deleteNode(8);
    myList.printList();  // Output: 5 2 1 7

    Node* foundNode = myList.searchNode(1);
    if (foundNode != nullptr) {
        cout << "Found node with data " << foundNode->data << endl;  // Output: Found node with data 1
    }

    myList.sortList();
    myList.printList();  // Output: 1 2 5 
}