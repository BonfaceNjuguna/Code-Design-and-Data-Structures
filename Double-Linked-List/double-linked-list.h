#pragma once
#include <cstddef>

// A doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertNode(struct Node** head, int new_data);
    void pushAt(struct Node** head, int newElement, int position);
    void pushFront(struct Node** head, int new_data);
    void pushBack(struct Node** head, int new_data);
    void popBack(struct Node** head);
    void popFront(struct Node** head);
    void eraseNode(Node** head, Node* del);
    void removeNode(struct Node** head, int X);
    void insertAfter(struct Node* prev_node, int new_data);
    void insertBefore(struct Node* next_node, int new_data);
    int countNodes();
    bool isEmpty(Node* head);
    void bubbleSort(struct Node** head);
    int getNth(Node* head, int index);
    void displayList(struct Node* node);
};