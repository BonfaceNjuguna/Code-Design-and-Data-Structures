#include <iostream>
#include "double-linked-list.h"
using namespace std;

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