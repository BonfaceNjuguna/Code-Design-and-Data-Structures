#include <iostream>
using namespace std;

// A doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertNode(struct Node** head, int new_data)
{
    //allocate memory for New node
    struct Node* newNode = new Node;

    newNode->data = new_data;

    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = newNode;

    /*move the head to point to the new node */
    (*head) = newNode;
}

//inserts node at the front of the list
void pushFront(struct Node** head, int new_data)
{
    //allocate memory for New node
    struct Node* newNode = new Node;

    //assign data to new node
    newNode->data = new_data;

    newNode->next = (*head);
    newNode->prev = NULL;

    //previous of head is new node
    if ((*head) != NULL)
        (*head)->prev = newNode;

    (*head) = newNode;
}

//insert a new node at the end of the list
void pushBack(struct Node** head, int new_data)
{
    struct Node* newNode = new Node;
    struct Node* last = *head;
    newNode->data = new_data;
    newNode->next = NULL;

    //check if list is empty, if yes make new node the head of list
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;

    newNode->prev = last;
    return;
}

//deletes last node in the list
void popBack(struct Node** head) {
    if (head != NULL) {
        if ((*head)->next == NULL) {
            head = NULL;
        }
        else {
            Node* temp = *head;
            while (temp->next->next != NULL)
                temp = temp->next;
            Node* lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}

//deletes first node in the list
void popFront(struct Node** head) {
    if (head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        if (head != NULL)
            (*head)->prev = NULL;
    }
}

//delete a node
void eraseNode(Node** head, Node* del) {
    if (*head == NULL || del == NULL) {
        return;
    }
    if (*head == del) {
        *head = del->next;
    }
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    free(del);
    return;
}

//inserts node after previous
void insertAfter(struct Node* prev_node, int new_data)
{
    //check if prev node is null
    if (prev_node == NULL) {
        cout << "Previous node is required , it cannot be NULL \n";
        return;
    }

    struct Node* newNode = new Node;
    newNode->data = new_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

//inserts node before previous
void insertBefore(struct Node* next_node, int new_data)
{
    //check if after node is null
    if (next_node == NULL) {
        cout << "Next node is required , it cannot be NULL \n";
        return;
    }

    struct Node* newNode = new Node;
    newNode->data = new_data;
    newNode->prev = next_node->prev;
    next_node->prev = newNode;
    newNode->next = next_node;
    if (newNode->prev != NULL)
        newNode->prev->next = newNode;
}

//prints contents of linked list starting from the given node
void displayList(struct Node* node) {
    struct Node* last;

    while (node != NULL) {
        cout << node->data << "<==>";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "NULL";
}

//main program
int main() {
    struct Node* head = NULL;

    insertNode(&head, 2);
    pushFront(&head, 20);
    pushBack(&head, 40);
    pushFront(&head, 45);
    pushBack(&head, 25);
    //insertAfter(head->next, 30);
    

    cout << "Linked list before deletion:" << endl;
    displayList(head);

    cout << "\nLinked list after deletion: " << endl;
    eraseNode(&head, head->next);
    popFront(&head);
    popBack(&head);
    displayList(head);
    return 0;
}