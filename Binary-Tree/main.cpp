#include<iostream>
#include<cstdlib>
#include "BinaryTree.h"
using namespace std;

int main()
{
	binarySearch t;
	t.insert(50);
	t.insert(25);
	t.insert(75);
	t.insert(13);
	t.insert(37);
	t.display();
	t.remove(25);
	t.display();
	return 0;
}