#include "double-linked-list.h"
#include <iostream>

using namespace std;

    //create a new node
    void LinkedList::insertNode(struct Node** head, int new_data)
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
    void LinkedList::pushAt(struct Node** head, int newElement, int position) {

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
    void LinkedList::pushFront(struct Node** head, int new_data)
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
    void LinkedList::pushBack(struct Node** head, int new_data)
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
    void LinkedList::popBack(struct Node** head) {
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
    void LinkedList::popFront(struct Node** head) {
        if (head != NULL) {
            Node* temp = *head;
            *head = (*head)->next;
            free(temp);
            if (head != NULL)
                (*head)->prev = NULL;
        }
    }

    //delete a node
    void LinkedList::eraseNode(Node** head, Node* del) {
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
    void LinkedList::removeNode(struct Node** head, int X)
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
    void LinkedList::insertAfter(struct Node* prev_node, int new_data)
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
    void LinkedList::insertBefore(struct Node* next_node, int new_data)
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
    int LinkedList::countNodes() {

        //create a temp node pointing to head
        Node* temp = head;

        int i = 0;

        while (temp != NULL) {
            i++;
            temp = temp->next;
        }

        return i;
    }

    //check if empty
    bool LinkedList::isEmpty(Node* head) {
        if (head->next == head && head->data == 0) return true;
        return false;
    }

    //sort
    void LinkedList::bubbleSort(struct Node** head)
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
    int LinkedList::getNth(Node* head, int index)
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
    void LinkedList::displayList(struct Node* node) {
        struct Node* last;

        while (node != NULL) {
            cout << node->data << "<--->";
            last = node;
            node = node->next;
        }
        if (node == NULL)
            cout << "NULL";
    }