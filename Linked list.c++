#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    Node* link;
};

int main() {
    // Create a series of nodes with integer data
    Node *head, *tail = NULL;
    head = (struct Node*) malloc(sizeof(struct Node));
    Node *second = (struct Node*) malloc(sizeof(struct Node));
    Node *third = (struct Node*) malloc(sizeof(struct Node));
    Node *fourth = (struct Node*) malloc(sizeof(struct Node));
    tail = (struct Node*) malloc(sizeof(struct Node));

    head -> data = 48;
    head -> link = second;
    
    second -> data = 38; 
    head -> link -> link = third;

    third -> data = 28; 
    head -> link -> link -> link = fourth;

    fourth -> data = 18;
    head -> link -> link -> link -> link = tail;

    tail -> data = 8;
    tail -> link = NULL;

    // Print out result
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> link;
    }
    return 0;
}
