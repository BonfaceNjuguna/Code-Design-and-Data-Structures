#pragma once
#include <iostream>
#include <cstdlib>
#include <raylib.h>

using namespace std;

class binarySearch {

private:
    struct node
    {
        int data;
        node* left;
        node* right;
    };

    node* root;

public:
    node* makeEmpty(node* t);
    node* insert(int x, node* t);
    node* findMin(node* t);
    node* findMax(node* t);
    node* remove(int x, node* t);
    void inorder(node* t);
    node* find(node* t, int x);

    //constructor
    binarySearch()
    {
        root = NULL;
    }

    //destructor 
    ~binarySearch()
    {
        root = makeEmpty(root);
    }

    //insert
    void insert(int x) {
        root = insert(x, root);
    }

    //remove
    void remove(int x)
    {
        root = remove(x, root);
    }

    //display
    void display()
    {
        inorder(root);
        cout << endl;
    }

    //search
    void search(int x)
    {
        root = find(root, x);
    }
};