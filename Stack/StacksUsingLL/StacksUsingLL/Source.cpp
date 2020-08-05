#include <iostream>
struct Node
{
	int data;
	Node* next;
};
Node* head = NULL;
void Push(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}