#include "double-linked-list.h"
#include <iostream>


using namespace std;

//main program
int menu();
int main() {
    struct Node* head = NULL;

    LinkedList mylist;

    for (auto choice(menu()); choice != 9; choice = menu())
    {
        switch (choice)
        {
        case 1:
        {
            system("cls");
            mylist.displayList(head);
            break;
        }

        case 2:
        {
            system("cls");
            int pfno;
            std::cout << "Enter number to push front \n";
            if (std::cin.peek() == '\n')std::cin.ignore();
            std::cin >> pfno;
            mylist.pushFront(&head, pfno);
            mylist.displayList(head);
            break;
        }

        case 3:
        {
            system("cls");
            int pbno;
            std::cout << "Enter number to push back \n";
            if (std::cin.peek() == '\n')std::cin.ignore();
            std::cin >> pbno;
            mylist.pushBack(&head, pbno);
            mylist.displayList(head);
            break;
        }

        case 4:
        {
            system("cls");
            mylist.popFront(&head);
            mylist.displayList(head);
            break;
        }

        case 5:
        {
            system("cls");
            mylist.popBack(&head);
            mylist.displayList(head);
            break;
        }

        case 6:
        {
            system("cls");
            mylist.eraseNode(&head, head);
            mylist.displayList(head);
            break;
        }

        case 7:
        {
            system("cls");
            mylist.countNodes();
            mylist.displayList(head);
            break;
        }

        case 8:
        {
            system("cls");
            mylist.bubbleSort(&head);
            mylist.displayList(head);
            break;
        }
        }
    }

    return 0;
}

int menu()
{
    std::cout << " \n1. Print List" << std::endl;
    std::cout << "2. Push Front" << std::endl;
    std::cout << "3. Push Back" << std::endl;
    std::cout << "4. Erase Front" << std::endl;
    std::cout << "5. Erase Back" << std::endl;
    std::cout << "6. Erase Node" << std::endl;
    std::cout << "7. Count Nodes" << std::endl;
    std::cout << "8. Sort node" << std::endl;
    std::cout << "9. Quit" << std::endl;


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