#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
};
Node* head;
//this getnewNode is to avoid duplicate work when we 
// have multiple function to do. We can just simply call it
// to create a node pointer;
Node* getnewNode(int x)
{
	Node* newNode = new Node();
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void insertAtHead(int x)
{
	//local variable new Node
	Node* newNode = getnewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	//insert infront of the head node
	newNode->next = head;
	head->prev = newNode; 
	head = newNode;
}
void print()
{
	Node* temp = head;
	cout << "Forward: ";
	while (temp != NULL)
	{
		cout << " " << temp->data;
		temp = temp->next;
	}
	cout << endl;
}
void reversePrint()
{
	Node* temp = head;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	cout << "reverse: ";
	while (temp != NULL)
	{
		cout << " " << temp->data;
		temp = temp->prev;
	}
	cout << endl;
}
int main()
{
	head = NULL;
	insertAtHead(2); print(); reversePrint();
	insertAtHead(4); print(); reversePrint();
	insertAtHead(6); print(); reversePrint();
}