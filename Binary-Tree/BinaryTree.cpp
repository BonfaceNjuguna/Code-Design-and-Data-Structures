#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"
using namespace std;

binarySearch::node* binarySearch::makeEmpty(node* t)
{
    if (t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

//insert a node
binarySearch::node* binarySearch::insert(int x, node* t)
{
    if (t == NULL)
    {
        t = new node;
        t->data = x;
        t->left = t->right = NULL;
    }
    else if (x < t->data)
        t->left = insert(x, t->left);
    else if (x > t->data)
        t->right = insert(x, t->right);
    return t;
}

//findMin
binarySearch::node* binarySearch::findMin(node* t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

//findMax
binarySearch::node* binarySearch::findMax(node* t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

//remove a node
binarySearch::node* binarySearch::remove(int x, node* t)
{
    node* temp;
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        t->left = remove(x, t->left);
    else if (x > t->data)
        t->right = remove(x, t->right);
    else if (t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    else
    {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}

//order list
void binarySearch::inorder(node* t)
{
    if (t == NULL)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

binarySearch::node* binarySearch::find(node* t, int x)
{
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return find(t->left, x);
    else if (x > t->data)
        return find(t->right, x);
    else
        return t;
}