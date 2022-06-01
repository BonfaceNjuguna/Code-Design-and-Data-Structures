#include<iostream>
#include<cstdlib>
#include <raylib.h>
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

	InitWindow(800, 600, "Raylib Example");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(Color{ 255,255,255,255 });
		DrawText("BST example", 10, 10, 50, Color{ 255,0,0,255 });
		EndDrawing();
	}
	return 0;
}