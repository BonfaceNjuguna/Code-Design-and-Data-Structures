#include <stdlib.h>
#include <stdio.h>

struct node
{
	struct node* prev;
	int data;
	struct node* next;
};

//inserting a node in an empty list
struct node* addToEmpty(struct node* head, int data)
{
	struct node* temp = malloc(sizeof(struct node));
	head->prev = NULL;
	head->data = data;
	head->next = NULL;
	head = temp;
	return head;
};

//inserting at the beginning
struct node* addAtBeg(struct node* head, int data)
{
	struct node* temp = malloc(sizeof(struct node));
	head->prev = NULL;
	head->data = data;
	head->next = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	return head;
};

//inserting at the end
struct node* addAtEnd(struct node* head, int data)
{
	struct node* temp, *tp;
	temp = malloc(sizeof(struct node));
	head->prev = NULL;
	head->data = data;
	head->next = NULL;

	tp = head;
	while (tp->next != NULL)
	{
		tp = tp->next;
	}

	tp->next = temp;
	temp->prev = tp;
	return head;
};

//inserting after
struct node* addAfterPos(struct node* head, int data, int position)
{
	struct node* newP = NULL;
	struct node* temp = head;
	struct node* temp2 = NULL;
	newP = addToEmpty(newP, data);

	while (position != 1)
	{
		temp = temp->next;
		position--;
	}

	//add node at the end of the list
	if (temp->next == NULL)
	{
		temp->next = newP;
		newP->prev = temp;
	}
	else 
	{
		temp2 = temp->next;
		temp->next = newP;
		temp2->prev = newP;
		newP->next = temp2;
		newP->prev = temp;
	}
	return head;
};

//inserting after
struct node* addBeforePos(struct node* head, int data, int position)
{
	struct node* newP = NULL;
	struct node* temp = head;
	struct node* temp2 = NULL;
	newP = addToEmpty(newP, data);

	int pos = position;

	while (pos > 2)
	{
		temp = temp->next;
		position--;
	}

	//add node at the begining of the list
	if (position == 1)
	{
		head = addAtBeg(head, data);
	}
	else
	{
		temp2 = temp->next;
		temp->next = newP;
		temp2->prev = newP;
		newP->next = temp2;
		newP->prev = temp;
	}
	return head;
};

//doubly linked list
struct node* createList(struct node* head)
{
	int n, data, i;
	printf("Enter the number of nodes: ");
	scanf_s("%d", &n);

	if (n == 0)
	{
		return head;
	}

	printf("Enter the element for node 1: ");
	scanf_s("%d", &data);
	head = addToEmpty(head, data);

	for (i = 1; i < n; i++)
	{
		printf("Enter the element for node %d: ", i + 1);
		scanf_s("%d", &data);
		head = addToEmpty(head, data);
	}
	return head;
};

int main() {
	struct node* head = NULL;
	struct node* ptr;
	//int position = 3;
	//head = addToEmpty(head, 10);
	//head = addAtBeg(head, 20);
	//head = addAtEnd(head, 9);
	//head = addAfterPos(head, 44, position);
	//head = addBeforePos(head, 55, position);

	head = createList(head);

	ptr = head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}