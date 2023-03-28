#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        this -> head = NULL;
    }
    // Insert Node
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
    // Print Node
    void printList() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Delete Node
    void deleteNode(int data) {
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (current != NULL) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
        }
    }
    // Search Node
    void searchNode(int data) {
        Node* current = head;
        int index = 0;
        while (current != nullptr && current->data != data) {
            current = current->next;
            index++;
        }
        cout << current->data << " at index " << index << endl;
    }
    // Sort Node
    void sortNode() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        bool swapped;
        Node* current;
        do {
            swapped = false;
            current = head;
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};


int main() {
    int data;
    LinkedList obj;
    cout << "Enter Number: ";
    cin >> data;
    obj.insertNode(data);
    cout << "Enter Number: ";
    cin >> data;
    obj.insertNode(data);
    cout << "Enter Number: ";
    cin >> data;
    obj.insertNode(data);
    // obj.deleteNode(30);
    obj.printList();
    obj.searchNode(30);
    obj.sortNode();
    obj.printList();
    return 0;
}