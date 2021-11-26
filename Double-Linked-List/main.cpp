#include <iostream>
using namespace std;

// A doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

//create a new node
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

//insert at a certain position
void pushAt(struct Node** head, int newElement, int position) {

    Node* newNode = new Node();
    newNode->data = newElement;
    newNode->next = NULL;
    newNode->prev = NULL;

    //check if the position is > 0
    if (position < 1) {
        cout << "\nposition should be >= 1.";
    }
    else if (position == 1) {

        //if the position is 1, make new node as head
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else {

        //make a temp node and traverse to the node previous to the position
        Node* temp = *head;
        for (int i = 1; i < position - 1; i++) {
            if (temp != NULL) {
                temp = temp->next;
            }
        }

        //If the previous node is not null, adjust the links
        if (temp != NULL) {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next != NULL)
                newNode->next->prev = newNode;
        }
        else {

            //When the previous node is null
            cout << "\nThe previous node is null.";
        }
    }
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

//remove specific node
void removeNode(struct Node** head, int X)
{
    if ((*head) == NULL)
        return;
    struct Node* del = *head;
    struct Node* next;
    while (del != NULL) {
        if (del->data == X) {
            next = del->next;
            eraseNode(head, del);
            del = next;
        }
        else
            del = del->next;
    }
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

//count nodes
int countNodes(Node** head) {

    //create a temp node pointing to head
    Node* temp = *head;

    int i = 0;

    while (temp != NULL) {
        i++;
        temp = temp->next;
    }

    return i;
}

//check if empty
bool isEmpty(Node* head) {
    if (head->next == head && head->data == 0) return true;
    return false;
}

//sort
void bubbleSort(struct Node **head)
{
    int swapp, i;
    struct Node* ptr1;
    struct Node* lptr = NULL;
    if (head == NULL)
        return;
    do
    {
        swapp = 0;
        ptr1 = *head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapp = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapp);
}

//get nth position
int getNth(Node* head, int index)
{

    Node* current = head;

    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
}

//print linked list
void displayList(struct Node* node) {
    struct Node* last;

    while (node != NULL) {
        cout << node->data << "<--->";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "NULL";
}

//main program
int main() {
    struct Node* head = NULL;

    pushBack(&head, 2);
    pushBack(&head, 4);
    pushBack(&head, 6);
    pushBack(&head, 8);
    pushBack(&head, 10);
    pushAt(&head, 200, 4);
    //pushFront(&head, 20);
    //pushBack(&head, 40);
    //pushFront(&head, 45);
    //pushBack(&head, 25);
    //insertAfter(head->next, 30);

    if (isEmpty(head)) cout << "The list is empty!\n";
    else {
        cout << "The list is not empty! List contains:\n";
        displayList(head);
    }

    cout << "\nList after sort\n";
    bubbleSort(&head);
    displayList(head);
    

    /*cout << "Linked list before deletion:" << endl;
    displayList(head);*/


    //cout << "\nElement at index 3 is " << getNth(head, 3);
    //cout << "\nThe first node in the list is:  " << getNth(head, 0);
    //cout << "\nThe last node in the list is:" << getNth(head, );

    //cout << "\nLinked list after deletion: " << endl;
    //int X = 3;
    //removeNode(&head, X);
    //eraseNode(&head, head);
    //popFront(&head);
    //popBack(&head);
    //cout << "\n" << endl;
    //displayList(head);
    //
    ////count
    //cout << "\nNo. of nodes: " << countNodes(&head);

    return 0;
}