#include <iostream>
#include "Header.h"
using namespace std;
Node* front = NULL;
Node* rear = NULL;
void Enqueue(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp; //rear points to temp
	rear = temp; //resert rear
}
void dequeue()
{
	Node* temp = front; //delete later
	if (front == NULL) //empty list
	{
		cout << "Queue is empty!!! we cant dequeue";
		return;
	}
	if (front == rear) //1 element in the list
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete temp;
}