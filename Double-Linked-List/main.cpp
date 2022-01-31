#include <iostream>
#include "double-linked-list.h"
using namespace std;

//main program
int menu();
int main() {
    struct Node* head = NULL;
    pushBack(&head, 2);
    pushBack(&head, 4);
    pushBack(&head, 6);
    pushBack(&head, 8);
    pushBack(&head, 10);
    pushAt(&head, 200, 4);
    for (auto choice(menu()); choice != 8; choice = menu())
    {
        switch (choice)
        {
        case 1:
        {
            displayList(head);
            break;
        }

        case 2:
        {
            system("cls");
            int pfno;
            std::cout << "Enter number to push front \n";
            if (std::cin.peek() == '\n')std::cin.ignore();
            std::cin >> pfno;
            pushFront(&head, pfno);
            displayList(head);
            break;
        }

        case 3:
        {
            system("cls");
            int pbno;
            std::cout << "Enter number to push back \n";
            if (std::cin.peek() == '\n')std::cin.ignore();
            std::cin >> pbno;
            pushBack(&head, pbno);
            displayList(head);
            break;
        }

        case 4:
        {
            system("cls");
            popFront(&head);
            displayList(head);
            break;
        }

        case 5:
        {
            system("cls");
            popBack(&head);
            displayList(head);
            break;
        }

        case 6:
        {
            system("cls");
            eraseNode(&head, head);
            displayList(head);
            break;
        }

        case 7:
        {
            system("cls");
            countNodes(&head);
            displayList(head);
            break;
        }

        case 8:
        {
            system("cls");
            bubbleSort(&head);
            displayList(head);
            break;
        }

        }
    }

    //pushFront(&head, 20);
    //pushBack(&head, 40);
    //pushFront(&head, 45);
    //pushBack(&head, 25);
    //insertAfter(head->next, 30);

    /*if (isEmpty(head)) cout << "The list is empty!\n";
    else {
        cout << "The list is not empty! List contains:\n";
        displayList(head);
    }*/

    /*cout << "\nList after sort\n";
    bubbleSort(&head);
    displayList(head);*/
    

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

int menu()
{
    std::cout << " \n1. Print List" << std::endl;
    std::cout << "2. Push Front" << std::endl;
    std::cout << "3. Push Back" << std::endl;
    std::cout << "4. Erase Front" << std::endl;
    std::cout << "5. Erase Back" << std::endl;
    std::cout << "6. Count Nodes" << std::endl;
    std::cout << "7. Sort node" << std::endl;
    std::cout << "8. Quit" << std::endl;


    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.bad()) {
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            std::cout << "Bad input" << std::endl;
        }
        else break;
    }
    return choice;
}