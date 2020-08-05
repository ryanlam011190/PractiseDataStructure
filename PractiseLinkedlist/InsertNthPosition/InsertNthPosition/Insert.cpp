#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next; //pointer next to the next node
};
//insert a node at position insert(data, position)
Node* head;
void insert(int data, int position)
{
	Node* temp1 = new Node();
	temp1->data = data; 
	temp1->next = NULL; //empty list
	//insert the first node into an empty node
	if (position == 1)
	{
		temp1->next = head;
		head = temp1; //temp1 is now new head
		return;
	}
	Node* temp2 = head;
	for(int i; i < position - 2; i++)
	{
		temp2 = temp2->next; //run until the node next to position
	}
	//temp1 is pointing the last node
	temp1->next = temp2->next;
	temp2->next = temp1; //link to next
}
void print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << " " << temp->data;
		temp = temp->next;
	}
	cout << "\n";
}
int main()
{
	head = NULL; //first, node is empty;
	insert(2, 1); //first node is 2
	insert(3, 2);// insert 3 at position 2 >> 2 3
	insert(4, 1); //insert 4 at position 1 >> 4 2 3
	insert(5, 2); //5 at position 2 >> 4 5 2 3 
	print();
}